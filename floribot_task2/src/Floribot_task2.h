/*
 * File: Floribot_task2.h
 * node floribot_task2
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_TASK2_H_
#define FLORIBOT_TASK2_H_

#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
// Start of user code specific includes
#include "Histogramm.h"
#include "Codepattern.h"
#include "Statediagramm.h"
// End of user code don't delete this line

namespace floribot_task2 {

class Floribot_task2 
{
public:
	Floribot_task2(ros::NodeHandle n);
	virtual ~Floribot_task2();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	void throughRow(const sensor_msgs::LaserScan::ConstPtr &scan);
	void turn(int direction, int rows);
	//float calcFieldOfAttentionX(scan, angleIncrement, numRanges, x);
	//float calcFieldOfAttentionY(scan, angleIncrement, numRanges, y, yr, yl);

	//Histogramm x_hist;
	//Histogramm y_hist;
private:
	ros::NodeHandle n_;
	std::string CodePattern;
	int tick_rate;
	ros::Subscriber scan_sub;
	ros::Publisher task_cmd_vel_pub;

	geometry_msgs::Twist last_published;

	float angular, linear;

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
	//Box parameters for direction adjustment at turning left or right (FB)
	bool turn_direction;	//true = left, false = right
	double x_box;
	double y_box;
	bool stop_turn;
	Statediagramm statechart;


	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	std::string CodePattern;
	int tick_rate;
	ros::Publisher task_cmd_vel_pub;
	ros::Subscriber scan_sub;
	// Start of user code additional members
	// TODO: declare your private variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK2_H_ */
