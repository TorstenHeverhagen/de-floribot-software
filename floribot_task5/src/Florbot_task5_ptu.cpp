/*
 * File: Florbot_task5_ptu.cpp
 * node florbot_task5_ptu
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Florbot_task5_ptu.h"
// Start of user code specific includes

#include <phidgets/interface_kit.h>
// End of user code don't delete this line

namespace floribot_task5 {

Florbot_task5_ptu::Florbot_task5_ptu(ros::NodeHandle n) : n_(n)
{
	ptu46_cmd_pub = n_.advertise<sensor_msgs::JointState>("ptu46/cmd",1);
	ptu_action_sub = n_.subscribe("ptu_action", 1,
			&Florbot_task5_ptu::ptu_action_message, this);
    tick_rate = 10;
    n_.getParam("/florbot_task5_ptu/tick_rate", tick_rate);
    pan2 = 0.3;
    n_.getParam("/florbot_task5_ptu/pan2", pan2);
    tilt2 = 0.1;
    n_.getParam("/florbot_task5_ptu/tilt2", tilt2);
    pan1 = 0;
    n_.getParam("/florbot_task5_ptu/pan1", pan1);
    tilt1 = 0;
    n_.getParam("/florbot_task5_ptu/tilt1", tilt1);
    tilt_vel = 0.1;
    n_.getParam("/florbot_task5_ptu/tilt_vel", tilt_vel);
    pan_vel = 0.1;
    n_.getParam("/florbot_task5_ptu/pan_vel", pan_vel);
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Florbot_task5_ptu::tick, this);

    // Start of user code constructor

	client_interface_kit = n.serviceClient<phidgets::interface_kit>("interface_kit");

    // End of user code don't delete this line

} // end of constructor

Florbot_task5_ptu::~Florbot_task5_ptu()
{
    // Start of user code destructor
    // TODO: fill destructor with your code
    // End of user code don't delete this line
} // end of destructor

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
 * process messages from topic ptu_action
 *
 * @generated
 */
void Florbot_task5_ptu::ptu_action_message (const std_msgs::Int8::ConstPtr& msg)
{
	// Start of user code process message from topic ptu_action

	sensor_msgs::JointState ptu_cmd;

	// set values in PTU command state
	ptu_cmd.name.push_back("pan");
	ptu_cmd.name.push_back("tilt");
	ptu_cmd.position.push_back(pan2);
	ptu_cmd.position.push_back(tilt2);
	ptu_cmd.velocity.push_back(pan_vel);
	ptu_cmd.velocity.push_back(tilt_vel);
	// publish PTU command state
	publish_ptu46_cmd(ptu_cmd);
	// log
	ROS_INFO(
			"pan = %f , tilt = %f", ptu_cmd.position[0], ptu_cmd.position[1]);

	phidgets::interface_kit srv;
	srv.request.index = 0;
	srv.request.value_type = 1;
	srv.request.value = 1;
	srv.response.ack = 0;
	if (client_interface_kit.call(srv)) {
		if ((int)srv.response.ack == 1) {
			ROS_INFO("Changed digital output %d to state %d", 0, 1);
		}
		else {
			ROS_INFO("Returned %d", (int)srv.response.ack);
		}
	}
	else {
		ROS_ERROR("Failed to call service interface_kit");
	}

	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Florbot_task5_ptu::tick (const ros::TimerEvent& event)
{
	// Start of user code call your own code
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
