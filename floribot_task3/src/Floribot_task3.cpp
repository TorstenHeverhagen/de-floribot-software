/*
 * File: Floribot_task3.cpp
 * node floribot_task3
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_task3.h"
#include "simulink/floribot_task3_ert_rtw/floribot_task3.h"
// Start of user code specific includes
#include <stdio.h>
// End of user code don't delete this line

namespace floribot_task3 {

Floribot_task3::Floribot_task3(ros::NodeHandle n) : n_(n)
{
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task3::scan_message, this);
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
    robot_width = 0.5;
    n_.getParam("/floribot_task3/robot_width", robot_width);
    max_scan_distance = 1.0;
    n_.getParam("/floribot_task3/max_scan_distance", max_scan_distance);
    y_hist_max = 2;
    n_.getParam("/floribot_task3/y_hist_max", y_hist_max);
    x_hist_min = 0;
    n_.getParam("/floribot_task3/x_hist_min", x_hist_min);
    direction = 1;
    n_.getParam("/floribot_task3/direction", direction);
    leav_vel_x = 0.5;
    n_.getParam("/floribot_task3/leav_vel_x", leav_vel_x);
    turn_time = 0.8;
    n_.getParam("/floribot_task3/turn_time", turn_time);
    plant_distance = 0.45;
    n_.getParam("/floribot_task3/plant_distance", plant_distance);
    turn_vel_yaw = 0.5;
    n_.getParam("/floribot_task3/turn_vel_yaw", turn_vel_yaw);
    prob_threshold = 0.2;
    n_.getParam("/floribot_task3/prob_threshold", prob_threshold);
    x_hist_width = 0.1;
    n_.getParam("/floribot_task3/x_hist_width", x_hist_width);
    leav_time = 0.2;
    n_.getParam("/floribot_task3/leav_time", leav_time);
    row_width = 0.75;
    n_.getParam("/floribot_task3/row_width", row_width);
    plant_width = 0.05;
    n_.getParam("/floribot_task3/plant_width", plant_width);
    turn_vel_x = 0.1;
    n_.getParam("/floribot_task3/turn_vel_x", turn_vel_x);
    y_hist_min = -2;
    n_.getParam("/floribot_task3/y_hist_min", y_hist_min);
    x_hist_max = 2;
    n_.getParam("/floribot_task3/x_hist_max", x_hist_max);
    y_hist_width = 0.1;
    n_.getParam("/floribot_task3/y_hist_width", y_hist_width);
    x_sec = 1;
    n_.getParam("/floribot_task3/x_sec", x_sec);
    tick_rate = 100;
    n_.getParam("/floribot_task3/tick_rate", tick_rate);
    /* Initialize simulink model */
    floribot_task3_initialize();
    // Start of user code constructor
    x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
    y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	floribot_task3_U.prob_threshold = prob_threshold;
	floribot_task3_U.direction = direction;
	floribot_task3_U.turn_vel_x = turn_vel_x;
	floribot_task3_U.turn_vel_yaw = turn_vel_yaw;
	floribot_task3_U.leav_vel_x = leav_vel_x;
	floribot_task3_U.leav_time = leav_time;
	floribot_task3_U.turn_time = turn_time;
    // End of user code don't delete this line

} // end of constructor

Floribot_task3::~Floribot_task3()
{
    /* Terminate simulink model */
    floribot_task3_terminate();
    // Start of user code destructor
    delete x_hist;
    delete y_hist;
    // End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task3::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message from topic scan
	x_hist->clear();
	y_hist->clear();
	sensor_msgs::LaserScan scan = *msg;

	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
			if(y > -robot_width/2 && y < robot_width/2) x_hist->put(x);
			if(x < x_sec) y_hist->put(y);
		}
	}

	double left_n_max, right_n_max, front_n_max;

	floribot_task3_U.front_row_x = x_hist->get_mean(x_hist_width, x_sec);
	if (floribot_task3_U.front_row_x == 0) floribot_task3_U.front_row_prob = 0;
	else {
		front_n_max = 2 * atan(robot_width/2/x_sec)/scan.angle_increment;
		front_n_max = trunc(1 + front_n_max*plant_width/plant_distance*robot_width/plant_distance);
		floribot_task3_U.front_row_prob = x_hist->get_n(floribot_task3_U.front_row_x)/front_n_max;
	}

	floribot_task3_U.left_row_y = y_hist->get_mean(y_hist->get_width(), row_width + y_hist->get_width());
	if (floribot_task3_U.left_row_y == 0) floribot_task3_U.left_row_prob = 0;
	else {
		left_n_max = atan(x_sec/(floribot_task3_U.left_row_y+y_hist_width))/scan.angle_increment;
		left_n_max = trunc(1 + left_n_max * plant_width/plant_distance*x_sec/plant_distance);
		floribot_task3_U.left_row_prob = y_hist->get_sum(floribot_task3_U.left_row_y - y_hist_width, floribot_task3_U.left_row_y)/left_n_max;
	}

	floribot_task3_U.right_row_y = y_hist->get_mean(-row_width - y_hist->get_width(), -y_hist->get_width());
	if (floribot_task3_U.right_row_y == 0) floribot_task3_U.right_row_prob = 0;
	else {
		right_n_max = atan(x_sec/(-floribot_task3_U.right_row_y+y_hist_width))/scan.angle_increment;
		right_n_max = trunc(1 + right_n_max*plant_width/plant_distance*x_sec/plant_distance);
		floribot_task3_U.right_row_prob = y_hist->get_sum(floribot_task3_U.right_row_y, floribot_task3_U.right_row_y + y_hist_width)/right_n_max;
	}
	floribot_task3_U.row_width = row_width;

	printf("left(%f; %f) right(%f; %f) front(%f; %f)\n",
			floribot_task3_U.left_row_y, floribot_task3_U.left_row_prob,
			floribot_task3_U.right_row_y, floribot_task3_U.right_row_prob,
			floribot_task3_U.front_row_x, floribot_task3_U.front_row_prob);
	/*printf("s mx(%d; %f) s mx(%d; %f) s mx(%d; %f)\n",
			y_hist->get_sum(floribot_task3_U.left_row_y - y_hist_width, floribot_task3_U.left_row_y), left_n_max,
			y_hist->get_sum(floribot_task3_U.right_row_y, floribot_task3_U.right_row_y + y_hist_width), right_n_max,
			x_hist->get_n(floribot_task3_U.front_row_x), front_n_max);*/

	// End of user code don't delete this line
}

/**
 * publish messages to topic task_cmd_vel
 *
 * @generated
 */
void Floribot_task3::publish_task_cmd_vel (geometry_msgs::Twist msg)
{
	task_cmd_vel_pub.publish(msg);
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task3::tick ()
{
    /* Step the simulink model */
    floribot_task3_step();
	// Start of user code call your own code
    //printf("state: %d", floribot_task3_DW.is_c1_floribot_task3);
    geometry_msgs::Twist cmd_vel;
	cmd_vel.angular.z = floribot_task3_Y.cmd_vel_yaw;
	cmd_vel.linear.x = floribot_task3_Y.cmd_vel_x;
	publish_task_cmd_vel(cmd_vel);
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_task3::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
