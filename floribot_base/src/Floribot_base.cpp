/*
 * File: Floribot_base.cpp
 * node floribot_base
 *
 * @author: Torsten Heverhagen
 */

#include "Floribot_base.h"
// Start of user code specific includes
	// TODO: include your own headers
// End of user code

namespace floribot_base {

Floribot_base::Floribot_base(ros::NodeHandle n) : n_(n)
{
	cmd_vel_sub = n_.subscribe("cmd_vel", 1,
			&Floribot_base::cmd_vel_message, this);
} // end of constructor

Floribot_base::~Floribot_base()
{
	// Start of user code destructure
		// TODO: fill with your code
	// End of user code
}

void Floribot_base::cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg)
{
	// Start of user code process message
		// TODO: fill with your code
	// End of user code
}

void Floribot_base::tick ()
{
	// Start of user code call your own code
		// TODO: fill with your code
	// End of user code
}

// Start of user code additional members
	// TODO: define your methods
// End of user code

} // end of namespace
