/*
 * File: Floribot_wiimote.cpp
 * node floribot_wiimote
 *
 * @author: Torsten Heverhagen
 */

#include "Floribot_wiimote.h"
// Start of user code specific includes
	// TODO: include your own headers
// End of user code

namespace floribot_wiimote {

Floribot_wiimote::Floribot_wiimote(ros::NodeHandle n) : n_(n)
{
	cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("cmd_vel",1);
	joy_set_feedback_pub = n_.advertise<sensor_msgs::JoyFeedbackArray>("joy/set_feedback",1);
	joy_sub = n_.subscribe("joy", 1,
			&Floribot_wiimote::joy_message, this);
} // end of constructor

Floribot_wiimote::~Floribot_wiimote()
{
	// Start of user code destructure
		// TODO: fill with your code
	// End of user code
}

void Floribot_wiimote::publish_cmd_vel (const geometry_msgs::Twist::ConstPtr& msg)
{
	cmd_vel_pub.publish(msg);
}

void Floribot_wiimote::publish_joy_set_feedback (const sensor_msgs::JoyFeedbackArray::ConstPtr& msg)
{
	joy_set_feedback_pub.publish(msg);
}

void Floribot_wiimote::joy_message (const sensor_msgs::Joy::ConstPtr& msg)
{
	// Start of user code process message
		// TODO: fill with your code
	// End of user code
}

void Floribot_wiimote::tick ()
{
	// Start of user code call your own code
		// TODO: fill with your code
	// End of user code
}

// Start of user code additional members
	// TODO: define your methods
// End of user code

} // end of namespace
