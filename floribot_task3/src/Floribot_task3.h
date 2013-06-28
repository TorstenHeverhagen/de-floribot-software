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
#include "SectorHistogram.h"
#include "SHMap.h"
#include <sensor_msgs/JointState.h>
// End of user code don't delete this line

namespace floribot_task3 {

class Floribot_task3 
{
public:
	Floribot_task3(ros::NodeHandle n);
	virtual ~Floribot_task3();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);

	// Start of user code additional public members
	void publish_ptu_cmd (sensor_msgs::JointState msg);
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double leav_vel_x;
	int direction;
	double x_sec;
	double x_hist_min;
	int tick_rate;
	double y_hist_min;
	double x_hist_width;
	double y_hist_width;
	double leav_time;
	double turn_vel_yaw;
	double row_width;
	double plant_distance;
	double prob_threshold;
	double y_hist_max;
	double max_scan_distance;
	double robot_width;
	double plant_width;
	double turn_vel_x;
	double x_hist_max;
	double turn_time;
	ros::Subscriber scan_sub;
	ros::Publisher task_cmd_vel_pub;
	// Start of user code additional members
	ros::Publisher ptu_cmd_pub;
	Histogramm *x_hist;
	Histogramm *y_hist;
	SectorHistogram::P_SectorHistogram x_SH;
	SH_Map *left_Y_map;
	SH_Map *right_Y_map;
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK3_H_ */
