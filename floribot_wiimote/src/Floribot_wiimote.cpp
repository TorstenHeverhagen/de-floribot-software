/*
 * File: Floribot_wiimote.cpp
 * node floribot_wiimote
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_wiimote.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

Floribot_wiimote::Floribot_wiimote(ros::NodeHandle n) : n_(n)
{
	cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("cmd_vel",1);
	joy_set_feedback_pub = n_.advertise<sensor_msgs::JoyFeedbackArray>("joy/set_feedback",1);
	joy_sub = n_.subscribe("joy", 1,
			&Floribot_wiimote::joy_message, this);
    tick_rate = 100;
    n_.getParam("/floribot_wiimote/tick_rate", tick_rate);
} // end of constructor

Floribot_wiimote::~Floribot_wiimote()
{
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic cmd_vel
 *
 * @generated
 */
void Floribot_wiimote::publish_cmd_vel (const geometry_msgs::Twist::ConstPtr& msg)
{
	cmd_vel_pub.publish(msg);
}

/**
 * publish messages to topic joy/set_feedback
 *
 * @generated
 */
void Floribot_wiimote::publish_joy_set_feedback (const sensor_msgs::JoyFeedbackArray::ConstPtr& msg)
{
	joy_set_feedback_pub.publish(msg);
}

/**
 * process messages from topic joy
 *
 * @generated
 */
void Floribot_wiimote::joy_message (const sensor_msgs::Joy::ConstPtr& msg)
{
	// Start of user code process message
	// TODO: fill with your code
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_wiimote::tick ()
{
	// Start of user code call your own code
	// TODO: fill with your code
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

// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
