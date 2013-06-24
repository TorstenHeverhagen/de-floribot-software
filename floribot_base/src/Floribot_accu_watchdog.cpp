/*
 * File: Floribot_accu_watchdog.cpp
 * node floribot_accu_watchdog
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_accu_watchdog.h"
#include "simulink/floribot_accu_watchdog_ert_rtw/floribot_accu_watchdog.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_base {

Floribot_accu_watchdog::Floribot_accu_watchdog(ros::NodeHandle n) : n_(n)
{
	accu_low_pub = n_.advertise<std_msgs::Bool>("accu_low",1);
	phidgets_interface_kit_sub = n_.subscribe("phidgets/interface_kit", 1,
			&Floribot_accu_watchdog::phidgets_interface_kit_message, this);
    voltage_threshold = 1000;
    n_.getParam("/floribot_accu_watchdog/voltage_threshold", voltage_threshold);
    tick_rate = 100;
    n_.getParam("/floribot_accu_watchdog/tick_rate", tick_rate);
    /* Initialize simulink model */
    floribot_accu_watchdog_initialize();
    // Start of user code constructor
    
    floribot_accu_watchdog_U.voltage_threshold = voltage_threshold;
    // End of user code don't delete this line

} // end of constructor

Floribot_accu_watchdog::~Floribot_accu_watchdog()
{
    /* Terminate simulink model */
    floribot_accu_watchdog_terminate();
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic accu_low
 *
 * @generated
 */
void Floribot_accu_watchdog::publish_accu_low (std_msgs::Bool msg)
{
	accu_low_pub.publish(msg);
}

/**
 * process messages from topic phidgets/interface_kit
 *
 * @generated
 */
void Floribot_accu_watchdog::phidgets_interface_kit_message (const phidgets::interface_kit_params::ConstPtr& msg)
{
	// Start of user code process message from topic phidgets/interface_kit
	ROS_INFO("phidgets_interface_kit_message: %d", msg->value_type);
    phidgets::interface_kit_params ifk = *msg;
    switch(ifk.value_type)
    {
        case 1: { // digital input
            ROS_INFO("Digital input %d State %d", ifk.index, ifk.value);
            break;
        }
        case 2: { // digital output
            ROS_INFO("Digital output %d State %d", ifk.index, ifk.value);
            break;
        }
        case 3: { // sensor
            ROS_INFO("Sensor %d Value %d", ifk.index, ifk.value);
            if(ifk.index == 0) {
            	floribot_accu_watchdog_U.voltage = ifk.value;
            }
            break;
        }
    }
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_accu_watchdog::tick ()
{
    /* Step the simulink model */
    floribot_accu_watchdog_step();
	// Start of user code call your own code
    std_msgs::Bool accu_low_msg;
    accu_low_msg.data = floribot_accu_watchdog_Y.accu_low;
    publish_accu_low(accu_low_msg);
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_accu_watchdog::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members
// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
