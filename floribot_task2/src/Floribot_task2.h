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
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
// Start of user code specific includes
#include "Histogramm.h"
#include "Codepattern.h"
#include "Statediagramm.h"
#include "vector"

// End of user code don't delete this line

namespace floribot_task2 {

class Floribot_task2 
{

public:
	Floribot_task2(ros::NodeHandle n);
	virtual ~Floribot_task2();
	void tick();
	int get_tick_rate();
	void putXarray(double value, int index);
	void putYarray(double value, int index);

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& scan);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	// Start of user code additional public members
	// TODO: declare your variables and methods
	void throughRow(const sensor_msgs::LaserScan::ConstPtr &scan);
	void turn(int direction, int rows);
	//float calcFieldOfAttentionX(scan, angleIncrement, numRanges, x);
	//float calcFieldOfAttentionY(scan, angleIncrement, numRanges, y, yr, yl);

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
	double plant_width;
	double plant_distance;
	//Box parameters for direction adjustment at turning left or right (FB)
	int turn_direction;	//-1= rechts, 1 = links, 0 = 180 turn
	double x_box;
	double y_box;
	bool stop_turn;
	Statediagramm statechart;
	Histogramm *x_hist;
	Histogramm *y_hist;
	double left_row_y;
	double right_row_y;
	double front_row_y;
	double left_row_prob;
	double right_row_prob;
	double front_row_prob;
	double prob_threshold;
	double front_row_x;
//	std::vector<double> x_array;
//	std::vector<double> y_array;
//	std::vector<int>::iterator it;
	double x_array[800];
	double y_array[800];



	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK2_H_ */
