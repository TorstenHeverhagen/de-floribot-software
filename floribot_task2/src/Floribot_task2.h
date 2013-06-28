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
// End of user code don't delete this line

namespace floribot_task2 {

class Floribot_task2 
{

public:
	Floribot_task2(ros::NodeHandle n);
	virtual ~Floribot_task2();
	void tick();
	int get_tick_rate();

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& scan);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	// Start of user code additional public members
	// TODO: declare your variables and methods
	void print_params();


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
	int turn_direction;	//true = left, false = right

	Statediagramm statechart;
	Histogramm *x_hist;
	Histogramm *y_hist;
	Histogramm *x_hist_rowcount;
	Histogramm *alpha_hist;
	//Codepattern *code;
	float left_row_y, left_row_prob, right_row_prob,
			 right_row_y,front_row_y, front_row_x, front_row_prob;

	int left_n_max , right_n_max,front_n_max;

	// B. Bauer
	double alpha_hist_min, 	alpha_hist_max, alpha_hist_width;
	int line_extraction_k, maxi_n_erst ;
	double alpha_main;

	double leaving_time,stop_angle, prob_threshold,plant_distance ,plant_width;

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK2_H_ */
