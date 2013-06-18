/*
 * File: Floribot_task1.cpp
 * node floribot_task1
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_task1.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task1 {

Floribot_task1::Floribot_task1(ros::NodeHandle n) : n_(n)
{
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task1::scan_message, this);
    direction = ;
    n_.getParam("/floribot_task1/direction", direction);
    tick_rate = ;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);
    tick_rate = 100;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);
    // Start of user code constructor
    // TODO: fill with your code
    // End of user code don't delete this line

} // end of constructor

Floribot_task1::~Floribot_task1()
{
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic task_cmd_vel
 *
 * @generated
 */
void Floribot_task1::publish_task_cmd_vel (geometry_msgs::Twist msg)
{
	task_cmd_vel_pub.publish(msg);
}

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task1::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
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
void Floribot_task1::tick ()
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
int Floribot_task1::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
