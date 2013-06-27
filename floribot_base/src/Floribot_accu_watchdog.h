/*
 * File: Floribot_accu_watchdog.h
 * node floribot_accu_watchdog
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_ACCU_WATCHDOG_H_
#define FLORIBOT_ACCU_WATCHDOG_H_

#include <ros/ros.h>
#include <string>
#include <phidgets/interface_kit_params.h>
#include <std_msgs/Bool.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_base {

class Floribot_accu_watchdog 
{
public:
	Floribot_accu_watchdog(ros::NodeHandle n);
	virtual ~Floribot_accu_watchdog();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void phidgets_interface_kit_message (const phidgets::interface_kit_params::ConstPtr& msg);
	void publish_accu_low (std_msgs::Bool msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double voltage_threshold;
	int tick_rate;
	ros::Subscriber phidgets_interface_kit_sub;
	ros::Publisher accu_low_pub;
	// Start of user code additional members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_ACCU_WATCHDOG_H_ */
