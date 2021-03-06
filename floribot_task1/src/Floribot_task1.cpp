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

Floribot_task1::Floribot_task1(ros::NodeHandle n) : n_(n), statechart()
{
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
	scan_sub = n_.subscribe("scan", 1, &Floribot_task1::scan_message, this);

    direction = 1;
    n_.getParam("/floribot_task1/direction", direction);
    tick_rate = 20;
    n_.getParam("/floribot_task1/tick_rate", tick_rate);

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
	y_hist_width = 0.05;
    n_.getParam("/floribot_task1/y_hist_width", y_hist_width);
    alpha_hist_min = 0;
    n_.getParam("/floribot_task1/alpha_hist_min", alpha_hist_min);
    alpha_hist_max = 3.141592653;
    n_.getParam("/floribot_task1/alpha_hist_max", alpha_hist_max);
    alpha_hist_width = 0.3141592653;
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

	x_max_turn = 0;
	x_max_turn_erste = 7;
    n_.getParam("/floribot_task1/x_max_turn_erste", x_max_turn_erste);

    prob_trashhold = 0.15;
    n_.getParam("/floribot_task1/mean_trashhold", prob_trashhold);
    row_x_min = 0.5;
    n_.getParam("/floribot_task1/row_x_min", row_x_min);
    leaving_time = 2.2;
    n_.getParam("/floribot_task1/leaving_time", leaving_time);
    alpha_trashhold = 0.3;
    n_.getParam("/floribot_task1/alpha_trashhold", alpha_trashhold);
    direction = 1;
    n_.getParam("/floribot_task1/direction", direction);

    statechart.setDirection(direction);
	statechart.setTickRate(tick_rate);
	statechart.setLeavingTime(leaving_time);
	statechart.setProbTrashhold(prob_trashhold);
	statechart.setRowXMin(row_x_min);
	statechart.setAlphaTrashhold(alpha_trashhold);
	statechart.setRobotWidth(robot_width);
	statechart.setRowWidth(row_width);
	statechart.setMaxSpeedLinear(max_speed_linear);
	statechart.setMaxSpeedAngular(max_speed_angular);
	statechart.setXMaxTurnErst(x_max_turn_erste);

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
	alpha_hist->clear();

	sensor_msgs::LaserScan scan = *msg;

	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
			x_hist->put(x);
			y_hist->put(y);
		}
	}

	for (uint i = 0; i < scan.ranges.size() - line_extraction_k; i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float alpha = atan(((scan.ranges[i] * sin(scan.angle_min + i * scan.angle_increment))
					- (scan.ranges[i + line_extraction_k] * sin(scan.angle_min + (i + line_extraction_k) * scan.angle_increment)))
							/ ((scan.ranges[i] * cos(scan.angle_min + i * scan.angle_increment))
									- (scan.ranges[i + line_extraction_k] * cos(scan.angle_min + (i + line_extraction_k) * scan.angle_increment))));
			alpha_hist->put(alpha);
		}
	}

	x_max_turn = x_hist->get_Maxi_n(x_hist->getMin(), x_hist->getMax());

	left_row_y = y_hist->get_class_middle(y_hist->get_class_num((y_hist->get_mean(0,1))));
	max_scanns_left_y = (((acos(left_row_y/max_scan_distance)) - (3.14159/2 - scan.angle_max)) / scan.angle_increment);
	left_row_y_prob = y_hist->get_n(left_row_y) / max_scanns_left_y;

	right_row_y = y_hist->get_class_middle(y_hist->get_class_num(y_hist->get_mean(-1,0)));
	max_scanns_right_y = (((acos(-right_row_y/max_scan_distance)) - (3.14159/2 - scan.angle_max)) / scan.angle_increment);
	right_row_y_prob = y_hist->get_n(right_row_y) / max_scanns_right_y;

	row_x = x_hist->get_class_middle(x_hist->get_class_num(x_hist->get_mean(0,1)));
	max_scanns_x = (acos(row_x/max_scan_distance)/ scan.angle_increment);
	row_x_prob = x_hist->get_n(row_x) / (max_scanns_x * 2);

	alpha_mean = alpha_hist->get_mean(alpha_hist->getMin(), alpha_hist->getMax()/2);

	statechart.setLeftRowY(left_row_y);
	statechart.setLeftRowYProb(left_row_y_prob);
	statechart.setRightRowY(right_row_y);
	statechart.setRightRowYProb(right_row_y_prob);
	statechart.setRowX(row_x);
	statechart.setRowXProb(row_x_prob);
	statechart.setAlphaMean(alpha_mean);
	statechart.setXMaxTurn(x_max_turn);

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
	//printf("row_x = %f, row_x_prob = %f, \n",row_x, row_x_prob);
	printf("left_row_y = %f, left_row_y_prob = %f, \n", left_row_y, left_row_y_prob);
	printf("right_row_y = %f, right_row_y_prob = %f\n", right_row_y, right_row_y_prob);
	printf("left_row_y + right_row_y = %f\n", (left_row_y + right_row_y));
	printf("row_x = %f , row_x_prob = %f\n", row_x, row_x_prob);
	printf("alpha_mean = %f\n", alpha_mean);
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
