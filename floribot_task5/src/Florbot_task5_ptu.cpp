/*
 * File: Florbot_task5_ptu.cpp
 * node florbot_task5_ptu
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Florbot_task5_ptu.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task5 {

Florbot_task5_ptu::Florbot_task5_ptu(ros::NodeHandle n) : n_(n)
{
	ptu_action_sub = n_.subscribe("ptu_action", 1,
			&Florbot_task5_ptu::ptu_action_message, this);
	phidgets_interface_kit_pub = n_.advertise<phidgets::interface_kit_params>("phidgets/interface_kit",1);
	ptu46_cmd_pub = n_.advertise<sensor_msgs::JointState>("ptu46/cmd",1);
    tilt2 = 0.1;
    n_.getParam("/florbot_task5_ptu/tilt2", tilt2);
    pan1 = 0;
    n_.getParam("/florbot_task5_ptu/pan1", pan1);
    pan_vel = 0.1;
    n_.getParam("/florbot_task5_ptu/pan_vel", pan_vel);
    tilt1 = 0;
    n_.getParam("/florbot_task5_ptu/tilt1", tilt1);
    tick_rate = 10;
    n_.getParam("/florbot_task5_ptu/tick_rate", tick_rate);
    pan2 = 0.3;
    n_.getParam("/florbot_task5_ptu/pan2", pan2);
    tilt_vel = 0.1;
    n_.getParam("/florbot_task5_ptu/tilt_vel", tilt_vel);
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Florbot_task5_ptu::tick, this);

    // Start of user code constructor
    // TODO: fill constructor with your code
    // End of user code don't delete this line

} // end of constructor

Florbot_task5_ptu::~Florbot_task5_ptu()
{
    // Start of user code destructor
    // TODO: fill destructor with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic ptu_action
 *
 * @generated
 */
void Florbot_task5_ptu::ptu_action_message (const std_msgs::Integer::ConstPtr& msg)
{
	// Start of user code process message from topic ptu_action
	// TODO: fill ptu_action_message with your code
	// End of user code don't delete this line
}

/**
 * publish messages to topic phidgets/interface_kit
 *
 * @generated
 */
void Florbot_task5_ptu::publish_phidgets_interface_kit (phidgets::interface_kit_params msg)
{
	phidgets_interface_kit_pub.publish(msg);
}

/**
 * publish messages to topic ptu46/cmd
 *
 * @generated
 */
void Florbot_task5_ptu::publish_ptu46_cmd (sensor_msgs::JointState msg)
{
	ptu46_cmd_pub.publish(msg);
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Florbot_task5_ptu::tick (const ros::TimerEvent& event)
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
int Florbot_task5_ptu::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods (additional members)

// End of user code don't delete this line

} // end of namespace
