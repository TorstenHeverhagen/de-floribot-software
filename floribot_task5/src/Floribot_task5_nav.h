/*
 * File: Floribot_task5_nav.h
 * node floribot_task5_nav
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_TASK5_NAV_H_
#define FLORIBOT_TASK5_NAV_H_

#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Int8.h>
#include "Histogramm.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task5 {

class Floribot_task5_nav 
{
public:
	Floribot_task5_nav(ros::NodeHandle n);
	virtual ~Floribot_task5_nav();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);
	void publish_ptu_action (std_msgs::Int8 msg);

	// Start of user code additional public members
	// TODO: declare your additional public members
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double helios_width;
	int tick_rate;
	double distance_to_helios;
	double helios_max_vel;
	double helios_digger_depth;
	double K_P;
	ros::Publisher task_cmd_vel_pub;
	ros::Subscriber scan_sub;
	ros::Publisher ptu_action_pub;
	// Start of user code additional members
	double x_min;
	Histogramm *hist;
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK5_NAV_H_ */
