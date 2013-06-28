/*
 * File: Floribot_task5_nav.cpp
 * node floribot_task5_nav
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_task5_nav.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task5 {

Floribot_task5_nav::Floribot_task5_nav(ros::NodeHandle n) : n_(n)
{
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
	ptu_action_pub = n_.advertise<std_msgs::Int8>("ptu_action",1);
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task5_nav::scan_message, this);
    helios_max_vel = 0.5;
    n_.getParam("/floribot_task5_nav/helios_max_vel", helios_max_vel);
    helios_width = 0.4;
    n_.getParam("/floribot_task5_nav/helios_width", helios_width);
    distance_to_helios = 2;
    n_.getParam("/floribot_task5_nav/distance_to_helios", distance_to_helios);
    helios_digger_depth = 0.3;
    n_.getParam("/floribot_task5_nav/helios_digger_depth", helios_digger_depth);
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Floribot_task5_nav::tick, this);

    // Start of user code constructor
    // TODO: fill constructor with your code
    // End of user code don't delete this line

} // end of constructor

Floribot_task5_nav::~Floribot_task5_nav()
{
    // Start of user code destructor
    // TODO: fill destructor with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic task_cmd_vel
 *
 * @generated
 */
void Floribot_task5_nav::publish_task_cmd_vel (geometry_msgs::Twist msg)
{
	task_cmd_vel_pub.publish(msg);
}

/**
 * publish messages to topic ptu_action
 *
 * @generated
 */
void Floribot_task5_nav::publish_ptu_action (std_msgs::Int8 msg)
{
	ptu_action_pub.publish(msg);
}

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task5_nav::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message from topic scan
	// TODO: fill scan_message with your code
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task5_nav::tick (const ros::TimerEvent& event)
{
	// Start of user code call your own code
	// TODO: fill tick() with your code
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_task5_nav::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods (additional members)

// End of user code don't delete this line

} // end of namespace
