/*********************************************************************
* Software License Agreement (BSD License)
*
*  Example ROS subscription to Phidgets motor control HC
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

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <ros/ros.h>
#include "phidgets/motor_params.h"
#include "phidgets/motor_control.h"
#include "phidgets/encoder_params.h"
#include "phidgets/pid_params.h"
#include "phidgets/pid.h"

int wrap(int a) {
  return ((a + 1) > a);
}

bool check_wrap() {
  return (wrap(~0u>>1));
}

ros::ServiceClient client_motor_control;
phidgets::pid_params pid;
float PV = 0.0f;
int current_encoder_count = 0;
float build_up = 0.0f;
int motor_index = 0;
float integral = 0.0f;
float last_error = 0.0f;
float last_output = 0.0f;
double velocity_counts_per_sec = 0.0;
bool encoder_position_known = false;

ros::Time time_point[5];
int encoder_point[5];
int time_index = 0;

bool initialised = false;

/*!
 * \brief returns the current process variable value
 * \param output
 * \param pid PID parameters
 * \return process variable value
 */
float GetCurrentPV(
    float output,
    phidgets::pid_params &pid)
{
    build_up += output;
    float value = build_up * (1 - pid.lag) * pid.trans;
    build_up *= pid.lag;
    return (value);
}

/*!
 * \brief main PID update
 * \param PV process variable
 * \param this_target
 * \param next_target
 * \param pid PID parameters
 * \param rms_error returned position error
 * \return 
 */
float PID(
    float PV,
    float &this_target,
    float &next_target,
    phidgets::pid_params &pid,
    float &rms_error)
{
    float this_error;
    float this_output;
    float accel;
    float deriv;
    float friction;

    /* the desired PV for this iteration is the value     */
    /* calculated as next_target during the last loop     */
    this_target = next_target;
  
    /* test for acceleration, compute new target PV for   */
    /* the next pass through the loop                     */
    if ((pid.accel > 0.0f) && 
        (this_target != pid.target_position)) {
        if (this_target < pid.target_position) {
            next_target += pid.accel;
            if (next_target > pid.target_position) {
                next_target = pid.target_position;
            }
        }
        else { 
            /* pid.target > pid.setpoint */
            next_target -= pid.accel;
            if (next_target < pid.target_position) {
                next_target = pid.target_position;
            }
        }
    }
    else {
        next_target = pid.target_position;
    }
  
    /* acceleration is the difference between the PV      */
    /* target on this pass and the next pass through the  */
    /* loop                                               */
    accel = next_target - this_target;

    /* the error for the current pass is the difference   */
    /* between the current target and the current PV      */
    this_error = this_target - PV;

    /* the derivative is the difference between the error */
    /* for the current pass and the previous pass         */
    deriv = this_error - last_error;

    /* a very simple determination of whether there is    */
    /* special friction to be overcome on the next pass,  */
    /* if the current PV is 0 and the target for the next */
    /* pass is not 0, stiction could be a problem         */
    friction = (PV == 0.0f && next_target != 0.0f);

    /* the new error is added to the integral             */
    integral += this_target - PV;

    /* the square of the error is accumulated in          */
    /* rms_error, for reporting at the end of the program */
    /* it has no part in the PID loop calculations        */
    rms_error = (this_error * this_error);

    /* now that all of the variable terms have been       */
    /* computed they can be multiplied by the appropriate */
    /* coefficients and the resulting products summed     */
    this_output = 
        pid.p_gain * this_error +
        pid.i_gain * integral +
        pid.d_gain * deriv +
        pid.acc_ff * accel +
        pid.vel_ff * next_target +
        pid.fri_ff * friction +
        pid.bias;

    last_error = this_error;

    /* check for slew rate limiting on the output change  */
    if (pid.slew != 0.0f) {
        if (this_output - last_output > pid.slew) {
            this_output = last_output + pid.slew;
        }
        else if (last_output - this_output > pid.slew) {
            this_output = last_output - pid.slew;
        }
    }

    /* now check the output value for absolute limits     */
    if (this_output < pid.min) {
        this_output = pid.min;
    }
    else if (this_output > pid.max) {
        this_output = pid.max;
    }
  
    /* store the new output value to be used as the old   */
    /* output value on the next loop pass                 */
    return (last_output = this_output);
}

/*!
 * \brief callback when the encoder count changes
 * \param ptr encoder parameters
 */
void encoderCallback(const phidgets::encoder_params::ConstPtr& ptr)
{
    if (initialised) {
        phidgets::encoder_params e = *ptr;
        current_encoder_count = e.count * pid.direction;
        PV = current_encoder_count; //GetCurrentPV(current_encoder_count, pid);
        if (!encoder_position_known) encoder_point[0] = current_encoder_count;
        encoder_position_known = true;
        ROS_INFO("Encoder %d Count %d", e.index, current_encoder_count);
    }
}

/*!
 * \brief callback when the motor parameters change
 * \param ptr motor parameters
 */
void motorCallback(const phidgets::motor_params::ConstPtr& ptr)
{
    phidgets::motor_params m = *ptr;
    switch(m.value_type)
    {
        case 1: { // inputs
            ROS_INFO("Motor input %d State %d", m.index, (int)m.value);
            break;
        }
        case 2: { // velocity
            ROS_INFO("Motor %d Velocity %.2f", m.index, m.value);
            break;
        }
        case 3: { // current
            ROS_INFO("Motor %d Current %.2f", m.index, m.value);
            break;
        }
    }    
}

/*!
 * \brief set the speed and acceleration of a motor
 * \param motor_index index of the motor
 * \param velocity velocity of the motor
 * \param acceleration acceleration of the motor
 */
void set_motor_reference(
    int motor_index,
    float velocity,
    float acceleration)
{
  phidgets::motor_control srv;
  srv.request.index = motor_index;
  srv.request.velocity = velocity;
  srv.request.acceleration = acceleration;
  srv.response.ack = 0;
  if (client_motor_control.call(srv)) {
      if ((int)srv.response.ack == 1) {
          ROS_INFO("Changed motor %d reference velocity %.2f", motor_index, velocity);
      }
      else {
          ROS_INFO("Returned %d", (int)srv.response.ack);
      }
  }
  else {
      ROS_ERROR("Failed to call service motorcontrol");
  }
}

/*!
 * \brief sets target position or velocity and PID parameters
 * \param req requested parameters
 * \param res returned parameters
 */
bool set_target_position_velocity(
  phidgets::pid::Request &req,
  phidgets::pid::Response &res)
{
    if (req.index == motor_index) {
        if (req.mode == 0) {
            ROS_INFO("Control Mode: Speed");
            ROS_INFO("Target velocity %.3f", req.target_velocity);
            pid.target_velocity = req.target_velocity;
            time_index++;
            if (time_index >= 5) time_index = 0;
            time_point[time_index] = ros::Time::now();
            encoder_point[time_index] = current_encoder_count;
        }
        else {
            ROS_INFO("Control Mode: Position");
            ROS_INFO("Target position %d", req.target_position);
            pid.target_position = req.target_position;
        }
        pid.mode = req.mode;
        pid.direction = req.direction;
        pid.p_gain = req.p_gain;
        pid.i_gain = req.i_gain;
        pid.d_gain = req.d_gain;
        pid.acc_ff = req.acc_ff;
        pid.fri_ff = req.fri_ff;
        pid.vel_ff = req.vel_ff;
        pid.hold = req.hold;
        pid.bias = req.bias;
        pid.accel = req.accel;
        pid.trans = req.trans;
        pid.lag = req.lag;
        pid.min = req.min;
        pid.max = req.max;
        pid.slew = req.slew;

        res.ack = 1;
    }

    return(true);
}

/*!
 * \brief updates the set point in accordance with the desired velocity
 */
void update_set_point()
{
    ros::Time current_time = ros::Time::now();

    // how much time has elapsed since the speed command?
    ros::Duration time_elapsed = current_time - time_point[time_index];

    if ((!time_elapsed.isZero()) && 
        (encoder_position_known)) {

        // update the set point.  Relying on GCC signed integer wraparound here.
        pid.target_position = encoder_point[time_index] + (int)(time_elapsed.toSec() * (double)pid.target_velocity);

        // how much distance has been covered?
        unsigned int actual_distance = current_encoder_count - encoder_point[time_index];

        // current velocity
        velocity_counts_per_sec = (double)actual_distance / time_elapsed.toSec();

        ROS_INFO("Velocity %.1f/%.1f error %.4f", (float)pid.target_velocity, (float)velocity_counts_per_sec, (float)(pid.target_velocity - velocity_counts_per_sec));
    }
}

int main(int argc, char** argv)
{
    ROS_INFO("Phidgets PID Motor Control");
    ros::init(argc, argv, "pid_motor_control");

    if (!check_wrap()) {
        ROS_ERROR("This version of GCC does not support signed integer wraparound.  Try using the -fwrapv compile option.");
    }
    else {

        ros::NodeHandle n;
        ros::NodeHandle nh("~");
        int motor_control_serial_number = -1;
        nh.getParam("serial", motor_control_serial_number);
        nh.getParam("motorindex", motor_index);
        int encoder_serial_number = -1;
        nh.getParam("serialenc", encoder_serial_number);
        nh.getParam("direction", pid.direction);
        if (pid.direction != -1) pid.direction = 1;
        double v;
        pid.min = -50;
        nh.getParam("min", v);
        if (v < -1.0) pid.min = v;
        pid.max = 50;
        nh.getParam("max", v);
        if (v > 1.0) pid.max = v;
        double test_speed_counts_per_sec = 0;
        nh.getParam("testspeed", test_speed_counts_per_sec);
        nh.setParam("testspeed", 0);

        if (test_speed_counts_per_sec != 0) {
            ROS_INFO("Initiating test sequence at speed %.2f counts/sec", (float)test_speed_counts_per_sec);
            pid.mode = 0;
            pid.target_velocity = (float)test_speed_counts_per_sec;
        }

        pid.p_gain = 1.3f;
        pid.i_gain = 1.2f;
        pid.d_gain = 0.025f;
        nh.getParam("p", v);
        if (v != 0) pid.p_gain = (float)v;
        nh.getParam("i", v);
        if (v != 0) pid.i_gain = (float)v;
        nh.getParam("d", v);
        if (v != 0) pid.d_gain = (float)v;

        pid.acc_ff = 0;
        pid.fri_ff = 0;
        pid.vel_ff = 0;
        pid.hold = 0;
        pid.bias = 0;
        pid.accel = 0;
        pid.target_position = 0;
        pid.trans = 1;
        pid.lag = 0.0f; //368f;
        pid.slew = 0;

        std::string motor_topic = "phidgets/motorcontrol";
        if (motor_control_serial_number > -1) {
            char motor_control_serial_number_str[10];            
            sprintf(motor_control_serial_number_str,"%d", motor_control_serial_number);
            motor_topic += "/";
            motor_topic += motor_control_serial_number_str;
        }
        ROS_INFO("Motor Control: %s", motor_topic.c_str());
        ros::Subscriber motor_control_sub = n.subscribe(motor_topic, 1, motorCallback);

        std::string encoder_topic = "phidgets/encoder";
        if (encoder_serial_number > -1) {
            char encoder_serial_number_str[10];            
            sprintf(encoder_serial_number_str,"%d", encoder_serial_number);
            encoder_topic += "/";
            encoder_topic += encoder_serial_number_str;
        }
        ROS_INFO("Encoder: %s", encoder_topic.c_str());
        ros::Subscriber encoder_sub = n.subscribe(encoder_topic, 1, encoderCallback);

        client_motor_control = n.serviceClient<phidgets::motor_control>("motorcontrol");

        // start service which can be used to set target position/velocity
        std::string service_name = "closed_loop_motor_control";
        ros::ServiceServer service = n.advertiseService(service_name, set_target_position_velocity);

        int event_index = 0;
        float this_target = 0.0f;
        float next_target = 0.0f;
        float rms_error = 0.0f;

        float speed_output = 0.0f;
        float old_speed_output = 0.0f;
        unsigned long hold_time = 0;

        this_target = next_target = pid.target_position;

        initialised = true;
        time_index = 0;
        time_point[0] = ros::Time::now();

        ros::Rate loop_rate(30);
        while(ros::ok) {

            ros::Time current_time = ros::Time::now();
            ros::Duration time_elapsed = current_time - time_point[0];

            if ((pid.mode != 0) ||
                ((pid.mode == 0) && (pid.target_velocity != 0))) {
                if ((time_elapsed.toSec() > 4) && (!encoder_position_known)) {
                    ROS_WARN("No encoder signal.  Check that the correct encoder serial number was specified and that the encoder is connected");
                    break;
                }
            }

            // test sequence
            if (test_speed_counts_per_sec != 0) {
                if (time_elapsed.toSec() > 10) break;
            }

            // if in speed conrol mode change the set point
            if (pid.mode == 0) {
                update_set_point();
            }

            speed_output = PID(PV, this_target, next_target, pid, rms_error);

            if (hold_time > 0) {
                --hold_time;
                speed_output = old_speed_output;
            }
            else if (speed_output != old_speed_output) {
                hold_time = (unsigned long)floor(pid.hold);
                old_speed_output = speed_output;
            }

            ROS_INFO("PID Motor %d Target %7.2f Actual %7.2f Vel %7.2f Error %.8f", motor_index, this_target, PV, speed_output, rms_error);

            if (encoder_position_known) {
                set_motor_reference(motor_index, speed_output, 20);
            }
            else {
                // No encoder feedback yet, so just start things rolling
                if (pid.target_velocity >= 0) {
                    set_motor_reference(motor_index, 10, 20);
                }
                else {
                    set_motor_reference(motor_index, -10, 20);
                }
            }
  
            ros::spinOnce();
            loop_rate.sleep();
        }

        if (test_speed_counts_per_sec != 0) {
            if (!encoder_position_known) {
                ROS_INFO("Test sequence aborted due to no encoder signal being received");
            }
            else {
                ROS_INFO("Test sequence completed");
            }
        }

        set_motor_reference(motor_index, 0, 0);
    }

    return 0;
}

