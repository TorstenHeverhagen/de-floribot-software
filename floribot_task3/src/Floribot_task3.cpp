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
#include <geometry_msgs/Point.h>
// End of user code don't delete this line

namespace floribot_task3 {

Floribot_task3::Floribot_task3(ros::NodeHandle n) : n_(n)
{
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task3::scan_message, this);
    row_width = 0.75;
    n_.getParam("/floribot_task3/row_width", row_width);
    turn_vel_yaw = 0.5;
    n_.getParam("/floribot_task3/turn_vel_yaw", turn_vel_yaw);
    x_sec = 1;
    n_.getParam("/floribot_task3/x_sec", x_sec);
    plant_distance = 0.45;
    n_.getParam("/floribot_task3/plant_distance", plant_distance);
    x_hist_min = 0;
    n_.getParam("/floribot_task3/x_hist_min", x_hist_min);
    max_scan_distance = 1.0;
    n_.getParam("/floribot_task3/max_scan_distance", max_scan_distance);
    x_hist_max = 2;
    n_.getParam("/floribot_task3/x_hist_max", x_hist_max);
    leav_vel_x = 0.5;
    n_.getParam("/floribot_task3/leav_vel_x", leav_vel_x);
    prob_threshold = 0.2;
    n_.getParam("/floribot_task3/prob_threshold", prob_threshold);
    plant_width = 0.05;
    n_.getParam("/floribot_task3/plant_width", plant_width);
    turn_vel_x = 0.1;
    n_.getParam("/floribot_task3/turn_vel_x", turn_vel_x);
    direction = 1;
    n_.getParam("/floribot_task3/direction", direction);
    robot_width = 0.5;
    n_.getParam("/floribot_task3/robot_width", robot_width);
    x_hist_width = 0.1;
    n_.getParam("/floribot_task3/x_hist_width", x_hist_width);
    y_hist_max = 2;
    n_.getParam("/floribot_task3/y_hist_max", y_hist_max);
    tick_rate = 100;
    n_.getParam("/floribot_task3/tick_rate", tick_rate);
    y_hist_width = 0.1;
    n_.getParam("/floribot_task3/y_hist_width", y_hist_width);
    leav_time = 0.2;
    n_.getParam("/floribot_task3/leav_time", leav_time);
    turn_time = 0.3;
    n_.getParam("/floribot_task3/turn_time", turn_time);
    y_hist_min = -2;
    n_.getParam("/floribot_task3/y_hist_min", y_hist_min);
    /* Initialize simulink model */
    floribot_task3_initialize();
	
	//timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Floribot_task3::tick, this);

    // Start of user code constructor
    x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
    y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
    geometry_msgs::Point x_p1, x_p2;
    x_p1.x = 0.1;
    x_p1.y = robot_width/2;
    x_p2.x = x_sec;
    x_p2.y = -robot_width/2;
    x_SH = new SectorHistogram(x_p1, x_p2, x_hist_width);

    geometry_msgs::Point left_p1, left_p2;
    left_p1.x = 0.1;
    left_p1.y = row_width;
    left_p2.x = x_sec;
    left_p2.y = 0.1;
    left_Y_map = new SH_Map(left_p1, left_p2, x_hist_width, y_hist_width);

    geometry_msgs::Point right_p1, right_p2;
    right_p1.x = 0.1;
    right_p1.y = -0.1;
    right_p2.x = x_sec;
    right_p2.y = -row_width;
    right_Y_map = new SH_Map(right_p1, right_p2, x_hist_width, y_hist_width);

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
    delete x_SH;
    delete left_Y_map;
    delete right_Y_map;
    // End of user code don't delete this line
} // end of destructor

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
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task3::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message from topic scan
	x_hist->clear();
	y_hist->clear();
	x_SH->clear();
	left_Y_map->clear();
	right_Y_map->clear();
	sensor_msgs::LaserScan scan = *msg;

	for (uint i = 0; i < scan.ranges.size(); i++) {
		geometry_msgs::Point p;
		double angle = scan.angle_min+i*scan.angle_increment;
		p.x = scan.ranges[i] * cos(angle);
		p.y = scan.ranges[i] * sin(angle);

		x_SH->add(p, angle);
		left_Y_map->add(p, angle);
		right_Y_map->add(p, angle);
		if(scan.ranges[i] < max_scan_distance) {
			if(p.y > -robot_width/2 && p.y < robot_width/2) x_hist->put(p.x);
			if(p.x < x_sec) y_hist->put(p.y);
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

	double x_mean = x_SH->getXMean(), x_prob = x_SH->getXProb(x_mean);
	double left_mean = left_Y_map->getYMean(), left_prob = left_Y_map->getYProb(left_mean);
	double right_mean = right_Y_map->getYMean(), right_prob = right_Y_map->getYProb(right_mean);
	ROS_DEBUG("left(%f; %f) right(%f; %f) front(%f; %f)",
			floribot_task3_U.left_row_y, floribot_task3_U.left_row_prob,
			floribot_task3_U.right_row_y, floribot_task3_U.right_row_prob,
			floribot_task3_U.front_row_x, floribot_task3_U.front_row_prob);
	ROS_DEBUG("lef2(%f; %f) righ2(%f; %f) fron2(%f; %f)",
			left_mean, left_prob,
			right_mean, right_prob,
			x_mean, x_prob);

	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task3::tick (const ros::TimerEvent& event)
{
    /* Step the simulink model */
    floribot_task3_step();
	// Start of user code call your own code
    ROS_DEBUG("state: %d", floribot_task3_DW.is_c1_floribot_task3);
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
