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
#include <std_msgs/Integer.h>
#include <sensor_msgs/LaserScan.h>
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
	void publish_ptu_action (std_msgs::Integer msg);
	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);

	// Start of user code additional public members
	// TODO: declare your additional public members
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double distance_to_helios;
	double helios_width;
	int ptu_action;
	double helios_digger_depth;
	int tick_rate;
	double helios_max_vel;
	ros::Publisher task_cmd_vel_pub;
	ros::Publisher ptu_action_pub;
	ros::Subscriber scan_sub;
	// Start of user code additional members
	// TODO: declare your private variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK5_NAV_H_ */
