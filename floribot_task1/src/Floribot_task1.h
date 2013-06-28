/*
 * File: Floribot_task1.h
 * node floribot_task1
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_TASK1_H_
#define FLORIBOT_TASK1_H_

#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
// Start of user code specific includes
#include "Histogramm.h"
#include "Statediagramm.h"
// End of user code don't delete this line

namespace floribot_task1 {

class Floribot_task1 
{
public:
	Floribot_task1(ros::NodeHandle n);
	virtual ~Floribot_task1();
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
	ros::Publisher task_cmd_vel_pub;
	ros::Subscriber scan_sub;
	// Start of user code additional members

	double max_scan_distance;
	double robot_width;
	double row_width;

	int line_extraction_k;

	double max_speed_angular, max_speed_linear;

	double x_hist_min;
	double x_hist_max;
	double x_hist_width;
	double y_hist_min;
	double y_hist_max;
	double y_hist_width;
	double alpha_hist_min;
	double alpha_hist_max;
	double alpha_hist_width;
	Histogramm *x_hist;
	Histogramm *y_hist;
	Histogramm *alpha_hist;

	Statediagramm statechart;
	double max_scanns_x, max_scanns_right_y, max_scanns_left_y;
	double prob_trashhold, leaving_time;
	double alpha_mean, alpha_trashhold;
	double left_row_y, right_row_y, row_x, row_x_min;
	double left_row_y_prob, right_row_y_prob, row_x_prob;

	int x_max_turn, x_max_turn_erste;

	int direction;


	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK1_H_ */
