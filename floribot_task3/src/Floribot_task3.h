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

	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);

	// Start of user code additional public members
	void publish_ptu_cmd (sensor_msgs::JointState msg);
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double row_width;
	double turn_vel_yaw;
	double x_sec;
	double plant_distance;
	double x_hist_min;
	double max_scan_distance;
	double x_hist_max;
	double leav_vel_x;
	double prob_threshold;
	double plant_width;
	double turn_vel_x;
	int direction;
	double robot_width;
	double x_hist_width;
	double y_hist_max;
	int tick_rate;
	double y_hist_width;
	double leav_time;
	double turn_time;
	double y_hist_min;
	ros::Publisher task_cmd_vel_pub;
	ros::Subscriber scan_sub;
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
