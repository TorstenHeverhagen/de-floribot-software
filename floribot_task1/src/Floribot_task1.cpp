/*
 * File: Floribot_task1.cpp
 * node floribot_task1
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_task1.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task1 {

Floribot_task1::Floribot_task1(ros::NodeHandle n) : n_(n)
{
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
	scan_sub = n_.subscribe("scan", 1, &Floribot_task1::scan_message, this);

    direction = 1;
    n_.getParam("/floribot_task1/direction", direction);
    tick_rate = 100;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);

    // Start of user code constructor

    max_scan_distance = 2.0;
    n_.getParam("/floribot_task1/max_scan_distance", max_scan_distance);
	robot_width = 0.5;
    n_.getParam("/floribot_task1/robot_width", robot_width);
	row_width = 0.75;
    n_.getParam("/floribot_task1/row_width", row_width);


	x_hist_min = 0.0;
    n_.getParam("/floribot_task1/x_hist_min", x_hist_min);
	x_hist_max = 2.0;
    n_.getParam("/floribot_task1/x_hist_max", x_hist_max);
	x_hist_width = 0.1;
    n_.getParam("/floribot_task1/x_hist_width", x_hist_width);
	y_hist_min = -2.0;
    n_.getParam("/floribot_task1/y_hist_min", y_hist_min);
	y_hist_max = 2.0;
    n_.getParam("/floribot_task1/y_hist_max", y_hist_max);
	y_hist_width = 0.1;
    n_.getParam("/floribot_task1/y_hist_width", y_hist_width);
	x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
	y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);

    // End of user code don't delete this line

} // end of constructor

Floribot_task1::~Floribot_task1()
{
    // Start of user code destructor

    delete x_hist;
    delete y_hist;

    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic task_cmd_vel
 *
 * @generated
 */
void Floribot_task1::publish_task_cmd_vel (geometry_msgs::Twist msg)
{
	task_cmd_vel_pub.publish(msg);
}

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task1::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message

	x_hist->clear();
	y_hist->clear();
	sensor_msgs::LaserScan scan = *msg;

	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
			x_hist->put(x);
			y_hist->put(y);
		}
	}

	// x_hist->print();
	// y_hist->print();



	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task1::tick ()
{
	// Start of user code call your own code
	// TODO: fill with your code
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_task1::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods

// End of user code don't delete this line

} // end of namespace
