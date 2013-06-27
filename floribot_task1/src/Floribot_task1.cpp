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
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task1::scan_message, this);
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
    direction = ;
    n_.getParam("/floribot_task1/direction", direction);
    tick_rate = 100;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);
    tick_rate = ;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Floribot_task1::tick, this);

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
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task1::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message from topic scan
	// TODO: fill scan_message with your code
	// End of user code don't delete this line
}

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
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task1::tick (const ros::TimerEvent& event)
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
