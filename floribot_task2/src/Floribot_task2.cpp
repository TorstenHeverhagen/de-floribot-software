/*
 * File: Floribot_task2.cpp
 * node floribot_task2
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_task2.h"
// Start of user code specific includes
#include "Histogramm.h"
#include "Codepattern.h"
#include "stdio.h"
#include "iostream"
// End of user code don't delete this line

namespace floribot_task2 {

Floribot_task2::Floribot_task2(ros::NodeHandle n) : n_(n), statechart()
{

	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task2::scan_message, this);
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("cmd_vel",1);
	CodePattern = "";
	n_.getParam("/floribot_task2/CodePattern", CodePattern);
	CodePattern = "S-3L-2R-0-2R-F";
	tick_rate = 50;
	n_.getParam("/floribot_task2/tick_rate", tick_rate);
	// Start of user code constructor

	y_hist_min = -2;
	n_.getParam("/floribot_task2/y_hist_min", y_hist_min);
	y_hist_max = 2;
	n_.getParam("/floribot_task2/y_hist_max", y_hist_max);
	x_hist_max = 2;
	n_.getParam("/floribot_task2/x_hist_max", x_hist_max);
	y_hist_width = 0.1;
	n_.getParam("/floribot_task2/y_hist_width", y_hist_width);
	x_hist_min = 0;
	n_.getParam("/floribot_task2/x_hist_min", x_hist_min);
	row_width = 0.75;
	n_.getParam("/floribot_task2/row_width", row_width);
	max_scan_distance =2.0;
	n_.getParam("/floribot_task2/max_scan_distance", max_scan_distance);
	robot_width = 0.5;
	n_.getParam("/floribot_task2/robot_width", robot_width);
	x_hist_width = 0.1;
	n_.getParam("/floribot_task2/x_hist_width", x_hist_width);
	x_sec = 0.5;
	n_.getParam("/floribot_task2/x_sec", x_sec);

	leaving_time = 0.7;
	n_.getParam("/floribot_task2/leaving_time", leaving_time);

	stop_angle = 3.0;
	n_.getParam("/floribot_task2/stop_angle", stop_angle);

	alpha_hist_min = 0;
	alpha_hist_max = 180;
	alpha_hist_width = 5 ;
	line_extraction_k = 20;
	alpha_main = 0;

	n_.getParam("/floribot_task2/alpha_hist_min", alpha_hist_min);
	n_.getParam("/floribot_task2/alpha_hist_max", alpha_hist_max);
	n_.getParam("/floribot_task2/alpha_hist_width", alpha_hist_width);
	n_.getParam("/floribot_task2/line_extraction_k", line_extraction_k);

	plant_width = 0.05;
	n_.getParam("/floribot_task2/plant_width", plant_width);
	plant_distance = 0.45;
	n_.getParam("/floribot_task2/plant_distance", plant_distance);

	x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
	y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	x_hist_rowcount = new Histogramm(0,max_scan_distance,0.1);
	alpha_hist = new Histogramm(alpha_hist_min, alpha_hist_max, alpha_hist_width);

	//Start parameters for the direction adjustment (FB)
	linear = 0.5;
	angular = 0.5;
	turn_direction = 0;

	left_row_y = 0;
	front_row_y = 0;
	front_row_x = 0;
	right_row_y = 0;
	left_row_prob = 0;
	front_row_prob = 0;
	right_row_prob = 0;

	prob_threshold = 0.2;
	n_.getParam("/floribot_task2/prob_threshold", prob_threshold);

	left_n_max = 0;
	front_n_max = 0;
	right_n_max = 0;



	// fill statechart constants
	statechart.setRowWidth(row_width);
	statechart.setTickRate(tick_rate);
	statechart.setLeaveTime(leaving_time);
	// End of user code don't delete this line

} // end of constructor

Floribot_task2::~Floribot_task2()
{
	// Start of user code destructor
	delete x_hist;
	delete y_hist;
	delete x_hist_rowcount;
	delete alpha_hist;
	// End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_task2::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message
	sensor_msgs::LaserScan scan = *msg;
	Codepattern code(CodePattern);
	turn_direction = code.get_Direction(code.command[statechart.getCommandCount()]);
	//Histogramme und Arrays nullen
	x_hist->clear();
	y_hist->clear();
	x_hist_rowcount->clear();
	alpha_hist->clear();

	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
			//TODO eventuell anpassen, ?Filter loeschen?
			if(y > -robot_width/2 && y < robot_width/2) x_hist->put(x);
			if(x < x_sec) y_hist->put(y);
		}
	}

	//left scan datas are saved (size 400)
	if (turn_direction == 1) {
		for (uint i = 0; i < (scan.ranges.size()/2) - line_extraction_k; i++) {
			if(scan.ranges[i] < max_scan_distance) {
				float x = ((scan.ranges[i] * sin(scan.angle_min + i * scan.angle_increment))
						- (scan.ranges[i + line_extraction_k] * sin(scan.angle_min + (i + line_extraction_k) * scan.angle_increment)));
				float y = ((scan.ranges[i] * cos(scan.angle_min + i * scan.angle_increment))
						- (scan.ranges[i + line_extraction_k] * cos(scan.angle_min + (i + line_extraction_k) * scan.angle_increment)));
				float alpha = atan(x/y)* 180.0/3.141592653;
				alpha_hist->put((alpha));
			}
		}
	}

	//right scan datas are saved (size 400)
	if (turn_direction == -1) {
		for (uint i = scan.ranges.size()/2; i < scan.ranges.size() - line_extraction_k; i++) {
			if(scan.ranges[i] < max_scan_distance)
			{
				float x = ((scan.ranges[i] * sin(scan.angle_min + i * scan.angle_increment))
						- (scan.ranges[i + line_extraction_k] * sin(scan.angle_min + (i + line_extraction_k) * scan.angle_increment)));
				float y = ((scan.ranges[i] * cos(scan.angle_min + i * scan.angle_increment))
						- (scan.ranges[i + line_extraction_k] * cos(scan.angle_min + (i + line_extraction_k) * scan.angle_increment)));
				float alpha = atan(x/y)* 180.0/3.141592653;
				alpha_hist->put((alpha));
			}
		}
	}

	// TODO ALPHA berechnen!!!
	double nenner = 1;
	double zahler = 0;
	nenner = alpha_hist -> get_sum(alpha_hist_min,alpha_hist_max);

	for (unsigned int i = 0; i<(alpha_hist_min+alpha_hist_max)/alpha_hist_width;i++)
	{
		zahler += (alpha_hist->get_class_middle(i)) *(alpha_hist->histogramm[i]);
	}

	alpha_main = zahler/nenner;

	//code.check();  // TODO code.check() sollte hier noch abgefragt werden mit if

	// Histogramme füllen

	if (turn_direction == 1){
		for (uint i = scan.ranges.size()/2; i < scan.ranges.size(); i++) {
			if(scan.ranges[i] < 2) {
				float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
				x_hist_rowcount->put(x);
			}
		}
	}
	else if (turn_direction == -1){
		for (uint i = 0; i < scan.ranges.size()/2; i++) {
			if(scan.ranges[i] < 2) {
				float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
				x_hist_rowcount->put(x);
			}
		}
	}

	left_row_y = y_hist->get_mean(y_hist->get_width(),
			row_width + y_hist->get_width());
	front_row_x = x_hist->get_mean(x_hist_width, x_sec);
	front_row_y = y_hist->get_mean(-y_hist_width,y_hist_width);

	right_row_y = y_hist->get_mean(-row_width - y_hist->get_width(),
			-y_hist->get_width());

	//Front_row parameters
	front_n_max = 2 * atan(y_hist_width / y_hist_max) / scan.angle_increment;

	front_n_max = trunc(
			1
			+ front_n_max * plant_width / plant_distance * robot_width
			/ plant_distance);

	front_row_prob = y_hist->get_sum(front_row_y - y_hist_width, front_row_y)
													/ (double)front_n_max;
	//Left_row parameters
	left_n_max = atan(x_sec / (left_row_y + y_hist_width))
											/ scan.angle_increment;
	left_n_max = trunc(
			1
			+ left_n_max * plant_width / plant_distance * x_sec
			/ plant_distance);
	left_row_prob = y_hist->get_sum(left_row_y - y_hist_width, left_row_y)
											/ (double)left_n_max;

	//Right_row parameters
	right_n_max = atan(x_sec / (-right_row_y + y_hist_width))
											/ scan.angle_increment;
	right_n_max = trunc(
			1
			+ right_n_max * plant_width / plant_distance * x_sec
			/ plant_distance);
	right_row_prob = y_hist->get_sum(right_row_y, right_row_y + y_hist_width)
											/(double) right_n_max;
	printf(" left_prob %f | front_prob: %f | right_prob: %f \n", left_row_prob,front_row_prob,right_row_prob);
	// TODO fill inputs of statechart
	// Histogrammvalues
	statechart.setLeftRowY(left_row_y);
	statechart.setFrontRowx(front_row_x);
	statechart.setRightRowY(right_row_y);

	statechart.setLeftRowProb(left_row_prob);
	statechart.setFrontRowProb(front_row_prob);
	statechart.setRightRowProb(right_row_prob);
	statechart.setProbThreshold(prob_threshold);
	statechart.setAlpha(alpha_main);

	//Codepattern
	statechart.setDirect(turn_direction);
	statechart.setRows(code.get_Rows(code.command[statechart.getCommandCount()]));
	statechart.setMaxiN(x_hist_rowcount->get_Maxi_n(0,2));
	statechart.setStopAngle(stop_angle);
	// End of user code don't delete this line
}


void Floribot_task2::publish_task_cmd_vel (geometry_msgs::Twist msg)
{
	task_cmd_vel_pub.publish(msg);
}

/**
 * tick is triggered
 *
 * @generated
 */
void Floribot_task2::tick ()
{
	// Start of user code call your own code
	// fill inputs of statechart
	statechart.switch_State();
	statechart.printState();
	geometry_msgs::Twist msg;
	msg.linear.x = statechart.getLinear();
	msg.angular.z = statechart.getAngular();
	publish_task_cmd_vel(msg);
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_task2::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members


// End of user code don't delete this line
/*

 */

void Floribot_task2::print_params() {
	printf("left_row_prob: %f | front_row_prob: %f | right_row_prob: %f \n",left_row_prob, front_row_prob, right_row_prob);
	printf("Command %i | Alpha: %f ", statechart.getCommandCount()+1,alpha_main);
	statechart.printState();
	}

} // end of namespace
