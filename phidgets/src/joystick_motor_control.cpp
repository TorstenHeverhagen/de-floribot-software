/*********************************************************************
* Software License Agreement (BSD License)
*
*  Joystick control of Phidgets motor control HC
*  Copyright (c) 2010, Bob Mottram
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <ros/ros.h>
#include <sound_play/sound_play.h>
#include <geometry_msgs/Twist.h>
#include "phidgets/motor_params.h"
#include "phidgets/joystick_params.h"
#include "phidgets/interface_kit_params.h"

ros::ServiceClient client_joystick;

float speed = 20;
float acceleration = 20;
float deadband = 0.1f;

// digital inputs on the interface kit used to start and stop joystick control
int start_button_input_index = -1;
int stop_button_input_index = -1;

// command to be run when the start or stop button is pressed
std::string start_button_command = "";
std::string stop_button_command = "";

// speech sounds made when start or stop buttons are pressed
std::string start_button_sound = "Started";
std::string stop_button_sound = "Stopped";
std::string enabled_sound = "Joystick control enabled";

ros::Publisher motor_pub;
geometry_msgs::Twist cmd;

double max_linear_velocity = 0.3;
double max_angular_velocity = 20*3.1415927/180.0;

bool started = false;
bool initialised = false;

/*!
 * \brief has joystick control been enabled
 * \return true if joystick motor control is enabled
 */
bool is_enabled()
{
    bool enable_motor_control = false;
    ros::NodeHandle n;
    n.getParam("joystick/enable_motor_control", enable_motor_control);
    return enable_motor_control;
}

/*!
 * \brief callback when an input is activated
 * \param ptr sensor parameters
 */
void interfaceKitCallback(
    const phidgets::interface_kit_params::ConstPtr& ptr)
{
    if (is_enabled()) {
        phidgets::interface_kit_params ifk = *ptr;
        // if this is a digital input with a non-zero state
        if ((ifk.value_type == 1) && (ifk.value != 0)) {            
            if ((ifk.index == start_button_input_index) && (!started)) {
                started = true;
                ROS_INFO("Start button pressed");
            }
            if ((ifk.index == stop_button_input_index) && (started)) {
                started = false;
                ROS_INFO("Stop button pressed");
            }
        }
    }
}

/*!
 * \brief callback when the motor parameters change
 * \param ptr motor parameters
 */
void motorCallback(
    const phidgets::motor_params::ConstPtr& ptr)
{
    phidgets::motor_params m = *ptr;
    switch(m.value_type)
    {
        case 1: { // inputs
            //ROS_INFO("Motor input %d State %.2f", m.index, m.value);
            break;
        }
        case 2: { // velocity
            //ROS_INFO("Motor %d Velocity %.2f", m.index, m.value);
            break;
        }
        case 3: { // current
            //ROS_INFO("Motor %d Current %.2f", m.index, m.value);
            break;
        }
    }    
}

/*!
 * \brief sets all velocities to zero
 */
void stop_motors()
{
    if (initialised) {
        cmd.linear.x = 0;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 0;
    }

    ROS_INFO("Motors stopped");
}

/*!
 * \brief joystick command has arrived
 */
void joystickCallback(
    const phidgets::joystick_params::ConstPtr& ptr)
{
    if (initialised) {
        if (is_enabled()) {
            if ((start_button_input_index == -1) ||
                (stop_button_input_index == -1) ||
                ((start_button_input_index != -1) && (stop_button_input_index != -1) && (started))) {
                // get the joystick values
                phidgets::joystick_params joy = *ptr;
                float rotate = joy.axes[0];
                float forward = joy.axes[1];
                bool button_press = false;
                if (joy.buttons[0] != 0) button_press = true;

                if ((fabs(rotate) > deadband) || 
                    (fabs(forward) > deadband)) {
                    // joystick moved
                    // vector values should be in the range -1 <= x <= 1
                    cmd.linear.x = forward*max_linear_velocity;
                    cmd.angular.z = rotate*max_angular_velocity;
                    ROS_INFO("Joystick command forward %f/%f", forward, cmd.linear.x);
                    ROS_INFO("Joystick command rotate %f/%f", rotate, cmd.angular.z);
                }
                else {
                    // joystick centred
                    stop_motors();
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ROS_INFO("Joystick control of Phidgets Motor Control HC");
    ros::init(argc, argv, "joystick_motor_control");
    ros::NodeHandle n;
    ros::NodeHandle nh("~");

    sound_play::SoundClient sc;
    sleep(4); // pause to wait for the sound client to connect

    bool enable = false;
    nh.getParam("enable", enable);

    std::string name = "cmd_vel";
    nh.getParam("name", name);
    std::string topic_path = "phidgets/";
    nh.getParam("topic_path", topic_path);

    std::string joystick_name = "joystick";
    nh.getParam("joystickname", joystick_name);
    std::string motor_control_name = "motorcontrol";
    nh.getParam("motorcontrolname", motor_control_name);
    std::string interface_kit_name = "interface_kit";
    nh.getParam("interfacekitname", interface_kit_name);

    double vel=0;
    nh.getParam("max_linear_velocity", vel);
    if (vel>0) max_linear_velocity = vel;
    nh.getParam("max_angular_velocity", vel);
    if (vel>0) max_angular_velocity = vel;

    // sounds
    std::string sound_str = "";
    nh.getParam("startbuttonsound", sound_str);
    if (sound_str != "") start_button_sound = sound_str;
    sound_str = "";
    nh.getParam("stopbuttonsound", sound_str);
    if (sound_str != "") stop_button_sound = sound_str;
    sound_str = "";
    nh.getParam("enablesound", sound_str);
    if (sound_str != "") enabled_sound = sound_str;

    // start and stop button digital inputs on the interface kit
    nh.getParam("startbutton", start_button_input_index);
    nh.getParam("startbuttoncommand", start_button_command);
    if ((start_button_input_index < 0) || (start_button_input_index > 16)) start_button_input_index = -1;
    nh.getParam("stopbutton", stop_button_input_index);
    nh.getParam("stopbuttoncommand", stop_button_command);
    if ((stop_button_input_index < 0) || (stop_button_input_index > 16)) stop_button_input_index = -1;
    if (start_button_input_index == stop_button_input_index) {
        start_button_input_index = -1;
        stop_button_input_index = -1;
    }

    // speed and acceleration of the motors
    int v;
    nh.getParam("speed", v);
    if ((v > 1) && (v < 100)) speed = (float)v;
    nh.getParam("acceleration", v);
    if ((v > 1) && (v < 100)) acceleration = (float)v;

    // joystick deadband
    nh.getParam("deadband", v);
    if ((v > 0.001) && (v < 1.0)) deadband = (float)v;

    double frequency = 20.0;
    nh.getParam("frequency", frequency);

    // subscribe to the motor control node
    ros::Subscriber motor_control_sub = n.subscribe(topic_path + motor_control_name, 1, motorCallback);

    // subscribe to the joystick node
    ros::Subscriber joystick_sub = n.subscribe(topic_path + joystick_name, 1, joystickCallback);

    // subscribe to the interface kit node
    ros::Subscriber interface_kit_sub = n.subscribe(topic_path + interface_kit_name, 1, interfaceKitCallback);

    // publish motor commands in geometry_msgs::Twist format
    motor_pub = n.advertise<geometry_msgs::Twist>(name, 10);

    // halt the motors
    stop_motors();

    // make the joystick active
    n.setParam("joystick/enable", true);

    n.setParam("joystick/enable_motor_control", enable);

    if (!enable) {
        ROS_INFO("Waiting for enable parameter to be set");
    }
    else {
        if (enabled_sound !="") sc.say(enabled_sound);
    }

    ros::Rate loop_rate(frequency);
    initialised = true;
    bool prev_enable = enable;
    bool prev_started = started;
    while (ros::ok()) {
        // has joystick control been enabled ?
        bool en = is_enabled();

        if (en) motor_pub.publish(cmd);
        ros::spinOnce();
        loop_rate.sleep();

        // speak message to indicate that joystick control has
        // started or stopped
        if ((started) && (!prev_started)) {
            if (start_button_sound !="") sc.say(start_button_sound);
            if (start_button_command != "") {
                ROS_INFO("Running command:\n%s",start_button_command.c_str());
                system(start_button_command.c_str());
            }
        }
        if ((!started) && (prev_started)) {
            if (stop_button_sound !="") sc.say(stop_button_sound);
            if (stop_button_command != "") {
                ROS_INFO("Running command:\n%s",stop_button_command.c_str());
                system(stop_button_command.c_str());
            }
        }
        if ((en) && (!prev_enable)) {
            if (enabled_sound !="") sc.say(enabled_sound);
        }

        // if joystick control has started and the enable flag goes low
        // then ensure that the motors are stopped
        if ((!en) && (prev_enable) && (started)) {
            started = false;
            stop_motors();
        }
        if ((en) && (!started) && (prev_started)) {
            stop_motors();
        }
        prev_enable = en;
        prev_started = started;
    }

    return 0;
}

