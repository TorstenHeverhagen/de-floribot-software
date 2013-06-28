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
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task1::scan_message, this);
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
    tick_rate = 100;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);
    direction = ;
    n_.getParam("/floribot_task1/direction", direction);
	
	timer = n_.createTimer(ros::Duration(1.0/tick_rate), &Floribot_task1::tick, this);

    // Start of user code constructor

    max_scan_distance = 2.0;
    n_.getParam("/floribot_task1/max_scan_distance", max_scan_distance);
	robot_width = 0.5;
    n_.getParam("/floribot_task1/robot_width", robot_width);
	row_width = 0.75;
    n_.getParam("/floribot_task1/row_width", row_width);

    line_extraction_k = 5;
    n_.getParam("/floribot_task1/line_extraction_k", line_extraction_k);

    max_speed_angular = 3.15 / 2;
    n_.getParam("/floribot_task1/max_speed_angular", max_speed_angular);
    max_speed_linear = 1.0 / 2;
    n_.getParam("/floribot_task1/max_speed_linear", max_speed_linear);

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
    alpha_hist_min = 0;
    n_.getParam("/floribot_task1/alpha_hist_min", alpha_hist_min);
    alpha_hist_max = 3.141592653; //* 180 / 180.0;
    n_.getParam("/floribot_task1/alpha_hist_max", alpha_hist_max);
    alpha_hist_width = 3.141592653 * 5 / 180.0;
    n_.getParam("/floribot_task1/alpha_hist_width", alpha_hist_width);



	left_row_y = 0;
	right_row_y = 0;
	left_row_y_prob = 0;
	right_row_y_prob = 0;
	row_x = 0;
	row_x_prob = 0;
	alpha_mean = 0;
	max_scanns_x = 0;
	max_scanns_right_y = 0;
	max_scanns_left_y = 0;

    prob_trashhold = 0.05;
    n_.getParam("/floribot_task1/mean_trashhold", prob_trashhold);

	statechart.setTickRate(tick_rate);
	statechart.setProbTrashhold(prob_trashhold);
	statechart.setRobotWidth(robot_width);
	statechart.setRowWidth(row_width);
	statechart.setMaxSpeedLinear(max_speed_linear);
	statechart.setMaxSpeedAngular(max_speed_angular);

	x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
	y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	alpha_hist = new Histogramm(alpha_hist_min, alpha_hist_max, alpha_hist_width);

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
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task1::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message from topic scan
	// TODO: fill scan_message with your code
	// End of user code don't delete this line
}

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
 * tick is triggered 
 *
 * @generated
 */
void Floribot_task1::tick (const ros::TimerEvent& event)
{
	// Start of user code call your own code

	geometry_msgs::Twist vel;

	statechart.switch_State();

	vel.linear.x  =  statechart.getLinear();
	vel.angular.z =  statechart.getAngular();


	printf("#################################################################################################################\n");
	printf("x-Histogramm\n");
	x_hist->print();
	printf("y-Histogramm\n");
	y_hist->print();
	printf("alpha-Histogramm\n");
	alpha_hist->print();
	printf("#################################################################################################################\n");
	printf("row_x = %f, row_x_prob = %f, \n",row_x, row_x_prob);
	printf("left_row_y = %f, left_row_y_prob = %f, \n", left_row_y, left_row_y_prob);
	printf("right_row_y = %f, right_row_y_prob = %f\n", right_row_y, right_row_y_prob);
	printf("left_row_y + right_row_y = %f\n", (left_row_y + right_row_y));
	printf("histMin = %f histMax = %f histWidth = %f\n", alpha_hist->getMin(), alpha_hist->getMax(), alpha_hist->get_width());
	statechart.printState();
	printf("#################################################################################################################\n");
	printf("vel_x = %f , vel_z = %f\n",vel.linear.x,vel.angular.z);
	printf("#################################################################################################################\n");

	this->publish_task_cmd_vel(vel);

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
