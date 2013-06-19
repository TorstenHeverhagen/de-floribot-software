/*
 * File: Floribot_task3.h
 * node floribot_task3
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_TASK3_H_
#define FLORIBOT_TASK3_H_

#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
// Start of user code specific includes
#include "Histogramm.h"
// End of user code don't delete this line

namespace floribot_task3 {

class Floribot_task3 
{
public:
	Floribot_task3(ros::NodeHandle n);
	virtual ~Floribot_task3();
	void tick();
	int get_tick_rate();

	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	int tick_rate;
	double y_hist_min;
	double y_hist_max;
	double x_hist_max;
	double y_hist_width;
	double x_hist_min;
	double row_width;
	double max_scan_distance;
	double robot_width;
	double x_hist_width;
	double x_sec;
	ros::Publisher task_cmd_vel_pub;
	ros::Subscriber scan_sub;
	// Start of user code additional members
	Histogramm *x_hist;
	Histogramm *y_hist;
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK3_H_ */
