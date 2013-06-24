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
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
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

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	double robot_width;
	double max_scan_distance;
	double y_hist_max;
	double x_hist_min;
	int direction;
	double leav_vel_x;
	double turn_time;
	double plant_distance;
	double turn_vel_yaw;
	double prob_threshold;
	double x_hist_width;
	double leav_time;
	double row_width;
	double plant_width;
	double turn_vel_x;
	double y_hist_min;
	double x_hist_max;
	double y_hist_width;
	double x_sec;
	int tick_rate;
	ros::Subscriber scan_sub;
	ros::Publisher task_cmd_vel_pub;
	// Start of user code additional members
	Histogramm *x_hist;
	Histogramm *y_hist;
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK3_H_ */
