/*
 * File: Floribot_wiimote.cpp
 * node floribot_wiimote
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_wiimote.h"
#include "simulink/floribot_wiimote_ert_rtw/floribot_wiimote.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

Floribot_wiimote::Floribot_wiimote(ros::NodeHandle n) : n_(n)
{
	joy_sub = n_.subscribe("joy", 1,
			&Floribot_wiimote::joy_message, this);
	joy_set_feedback_pub = n_.advertise<sensor_msgs::JoyFeedbackArray>("joy/set_feedback",1);
	accu_low_sub = n_.subscribe("accu_low", 1,
			&Floribot_wiimote::accu_low_message, this);
	task_cmd_vel_sub = n_.subscribe("task_cmd_vel", 1,
			&Floribot_wiimote::task_cmd_vel_message, this);
	cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("cmd_vel",1);
    tick_rate = 100;
    n_.getParam("/floribot_wiimote/tick_rate", tick_rate);
    /* Initialize simulink model */
    floribot_wiimote_initialize();
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Floribot_wiimote::tick, this);

    // Start of user code constructor

    // End of user code don't delete this line

} // end of constructor

Floribot_wiimote::~Floribot_wiimote()
{
    /* Terminate simulink model */
    floribot_wiimote_terminate();
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic joy
 *
 * @generated
 */
void Floribot_wiimote::joy_message (const sensor_msgs::Joy::ConstPtr& msg)
{
	// Start of user code process message from topic joy
	
	floribot_wiimote_U.Button1 = msg->buttons[0];
	floribot_wiimote_U.Button2 = msg->buttons[1];
	floribot_wiimote_U.A = msg->buttons[2];
	floribot_wiimote_U.B = msg->buttons[3];
	floribot_wiimote_U.Left = msg->buttons[6];
	floribot_wiimote_U.Right = msg->buttons[7];
	floribot_wiimote_U.Up = msg->buttons[8];
	floribot_wiimote_U.Down = msg->buttons[9];
	floribot_wiimote_U.joy_roll = msg->axes[0];
	floribot_wiimote_U.joy_pitch = msg->axes[1];
	floribot_wiimote_U.joy_yaw = msg->axes[2];

	// End of user code don't delete this line
}

/**
 * publish messages to topic joy/set_feedback
 *
 * @generated
 */
void Floribot_wiimote::publish_joy_set_feedback (sensor_msgs::JoyFeedbackArray msg)
{
	joy_set_feedback_pub.publish(msg);
}

/**
 * process messages from topic accu_low
 *
 * @generated
 */
void Floribot_wiimote::accu_low_message (const std_msgs::Bool::ConstPtr& msg)
{
	// Start of user code process message from topic accu_low
	floribot_wiimote_U.accu_low = msg->data;
	// End of user code don't delete this line
}

/**
 * process messages from topic task_cmd_vel
 *
 * @generated
 */
void Floribot_wiimote::task_cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg)
{
	// Start of user code process message from topic task_cmd_vel
	floribot_wiimote_U.task_x = msg->linear.x;
	floribot_wiimote_U.task_yaw = msg->angular.z;
	// End of user code don't delete this line
}

/**
 * publish messages to topic cmd_vel
 *
 * @generated
 */
void Floribot_wiimote::publish_cmd_vel (geometry_msgs::Twist msg)
{
	cmd_vel_pub.publish(msg);
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_wiimote::tick (const ros::TimerEvent& event)
{
    /* Step the simulink model */
    floribot_wiimote_step();
	// Start of user code call your own code

	geometry_msgs::Twist cmd_vel_msg;
	cmd_vel_msg.linear.x = floribot_wiimote_Y.cmd_vel_x;
	cmd_vel_msg.angular.z = floribot_wiimote_Y.cmd_vel_yaw;
	publish_cmd_vel(cmd_vel_msg);
	// log
	ROS_DEBUG("z = %f , x = %f", cmd_vel_msg.angular.z, cmd_vel_msg.linear.x);

	publish_joy_set_feedback(prepare_joy_feedback());

	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_wiimote::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members


sensor_msgs::JoyFeedbackArray Floribot_wiimote::prepare_joy_feedback() {
	sensor_msgs::JoyFeedbackArray joy_feedback_msg;
	sensor_msgs::JoyFeedback led1;
	led1.type = 0;
	led1.id = 0;
	led1.intensity = floribot_wiimote_Y.joy_led1;
	joy_feedback_msg.array.push_back(led1);
	sensor_msgs::JoyFeedback led2;
	led2.type = 0;
	led2.id = 1;
	led2.intensity = floribot_wiimote_Y.joy_led2;
	joy_feedback_msg.array.push_back(led2);
	sensor_msgs::JoyFeedback led3;
	led3.type = 0;
	led3.id = 2;
	led3.intensity = floribot_wiimote_Y.joy_led3;
	joy_feedback_msg.array.push_back(led3);
	sensor_msgs::JoyFeedback led4;
	led4.type = 0;
	led4.id = 3;
	led4.intensity = floribot_wiimote_Y.joy_led4;
	joy_feedback_msg.array.push_back(led4);
	sensor_msgs::JoyFeedback rumble;
	rumble.type = 1;
	rumble.id = 0;
	rumble.intensity = floribot_wiimote_Y.joy_rumble;
	joy_feedback_msg.array.push_back(rumble);
	return joy_feedback_msg;
}

// End of user code don't delete this line

} // end of namespace
