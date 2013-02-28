/*
 * File: Floribot_find_goal.cpp
 * node floribot_find_goal
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_find_goal.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_navigation {

Floribot_find_goal::Floribot_find_goal(ros::NodeHandle n) : n_(n)
{
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_find_goal::scan_message, this);
    tick_rate = 100;
    n_.getParam("/floribot_find_goal/tick_rate", tick_rate);
} // end of constructor

Floribot_find_goal::~Floribot_find_goal()
{
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_find_goal::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message
	float r1 = msg->ranges[0];
	ROS_INFO("Abstand ist: %f", r1);
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_find_goal::tick ()
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
int Floribot_find_goal::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
