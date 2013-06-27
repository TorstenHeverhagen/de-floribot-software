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
	// TODO: constructor fill with your code
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
	max_scan_distance = 1.0;
	n_.getParam("/floribot_task2/max_scan_distance", max_scan_distance);
	robot_width = 0.5;
	n_.getParam("/floribot_task2/robot_width", robot_width);
	x_hist_width = 0.1;
	n_.getParam("/floribot_task2/x_hist_width", x_hist_width);
	x_sec = 1;
	n_.getParam("/floribot_task2/x_sec", x_sec);

	plant_width = 0.05;
	//n_.getParam("/floribot_task2/plant_width", plant_width);
	plant_distance = 0.45;
	//n_.getParam("/floribot_task2/plant_distance", plant_distance);

	x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
	y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	x_hist_rowcount = new Histogramm(0,2,0.1);

	//code = new Codepattern(CodePattern);
	//floribot_task2_U.prob_threshold = 0.2;
	//floribot_task2_U.direction = 1.0;

	//Start parameters for the direction adjustment (FB)
	linear = 0.5;
	angular = 0.5;
	x_box = 0.5;
	y_box = 0.3;
	turn_direction = false;	//true = left, false = right
	stop_turn = false;

	left_row_y=0 ;
	front_row_y = 0;
	front_row_x = 0;
	right_row_y=0;
	left_row_prob = 0;
	front_row_prob = 0;
	right_row_prob = 0;




	left_n_max = 0;
	front_n_max = 0;
	right_n_max=0;

	//SCAN_SIZE = 800;

	// fill statechart constants
	statechart.setRowWidth(row_width);
	statechart.setTickRate(tick_rate);
		//seifrieds



	// End of user code don't delete this line

} // end of constructor

Floribot_task2::~Floribot_task2()
{
	// Start of user code destructor
	delete x_hist;
	delete y_hist;
	delete x_hist_rowcount;
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

	//Histogramme und Arrays nullen
	x_hist->clear();
	y_hist->clear();
	x_hist_rowcount->clear();

	for (uint i = 0; i < sizeof(x_array)/sizeof(double); i++) {
			x_array[i] = 0;
		}

	for (uint i = 0; i < sizeof(y_array)/sizeof(double); i++) {
			y_array[i] = 0;
		}



	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < max_scan_distance) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);

	//TODO eventuell anpassen, ?Filter löschen?
			if(y > -robot_width/2 && y < robot_width/2) x_hist->put(x);
			if(x < x_sec) y_hist->put(y);
		}
	}

	//left scan datas are saved (size 400)
		if (turn_direction == 1) {
			int k = 0;
			for (uint i = scan.ranges.size()/2; i < scan.ranges.size(); i++){
				if (scan.ranges[i] < max_scan_distance) {
					double x_var = scan.ranges[i] * cos(scan.angle_min + i * scan.angle_increment);
					double y_var = scan.ranges[i] * sin(scan.angle_min + i * scan.angle_increment);
					x_array[k] = x_var;
					y_array[k] = y_var;
					k++;
				}
			}
		}

		//right scan datas are saved (size 400)
		if (turn_direction == -1) {
			int k = 0;
			for (uint i = 0; i < scan.ranges.size()/2; i++){
				if (scan.ranges[i] < max_scan_distance) {
					double x_var = scan.ranges[i] * cos(scan.angle_min + i * scan.angle_increment);
					double y_var = scan.ranges[i] * sin(scan.angle_min + i * scan.angle_increment);
					x_array[k] = x_var;
					y_array[k] = y_var;
					k++;
				}
			}
		}


	//code.check();  // TODO code.check() sollte hier noch abgefragt werden mit if

	// Histogramme füllen

	int turn_direction = code.get_Direction(code.command[statechart.getCommandCount()]+1);

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
	else {
		for (uint i = 0; i < scan.ranges.size(); i++) {
			if(scan.ranges[i] < 2) {
				float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
				x_hist_rowcount->put(x);
			}
		}
	}


	//ROS_INFO("x");
	//################################################
	// TODO Histogramme auswerten für Reihenfahrt
/*
	left_row_y = y_hist->get_mean(0.2,2);
	front_row_y = y_hist->get_sum(-0.2,0.2);
	right_row_y = y_hist->get_mean(-2,-0.2);

	front_row_x = x_hist->get_mean(0,x_sec);

	left_n_max = 1; // TODO berechnung einfügen
	front_n_max = 2 * atan(y_hist_width / y_hist_max) / scan.angle_increment;
	front_n_max = trunc(1 + front_n_max * plant_width / plant_distance * robot_width
							/ plant_distance);
	printf("%i", front_n_max);
	right_n_max = 1;

	left_row_prob = y_hist-> get_sum(left_row_y- y_hist->get_width(),left_row_y)/ left_n_max;
	front_row_prob = x_hist -> get_n(front_row_y)/front_n_max;
	right_row_prob = y_hist-> get_sum(right_row_y- y_hist->get_width(),right_row_y)/ right_n_max;
*/

	left_row_y = y_hist->get_mean(y_hist->get_width(),
			row_width + y_hist->get_width());
	front_row_x = x_hist->get_mean(x_hist_width, x_sec);
	front_row_y = y_hist->get_mean(-y_hist_width,y_hist_width);

	right_row_y = y_hist->get_mean(-row_width - y_hist->get_width(),
			-y_hist->get_width());

	//double left_n_max, right_n_max, front_n_max;

	//Front_row parameters
	front_n_max = 2 * atan(y_hist_width / y_hist_max) / scan.angle_increment;

	front_n_max = trunc(
			1
			+ front_n_max * plant_width / plant_distance * robot_width
			/ plant_distance);

	front_row_prob = y_hist->get_sum(front_row_y - y_hist_width, front_row_y)
									/ front_n_max;
	//Left_row parameters
	left_n_max = atan(x_sec / (left_row_y + y_hist_width))
							/ scan.angle_increment;
	left_n_max = trunc(
			1
			+ left_n_max * plant_width / plant_distance * x_sec
			/ plant_distance);
	left_row_prob = y_hist->get_sum(left_row_y - y_hist_width, left_row_y)
							/ left_n_max;

	//Right_row parameters
	right_n_max = atan(x_sec / (-right_row_y + y_hist_width))
							/ scan.angle_increment;
	right_n_max = trunc(
			1
			+ right_n_max * plant_width / plant_distance * x_sec
			/ plant_distance);
	right_row_prob = y_hist->get_sum(right_row_y, right_row_y + y_hist_width)
							/ right_n_max;

	//Turn right/left (FB)
	//Read in the scan x-> front, y-> left, Turn direction: true = left, false = right

	//turn right
	if (turn_direction == -1) {
		uint counta = 0;

		for (uint i = 0; i < (sizeof(y_array)/sizeof(double) - 1); i++) {//Use only the right half of the scan
			if ((y_array[i] >= -y_box) && (x_array[i] >= x_box)&& y_array[i] != 0) {
				counta++;

				if (counta > 5) {	//Turn stops if atleast 5 points are found
					stop_turn = true;
					//printf("Stop_turn right -> true\n");

				} else {
					stop_turn = false;
					//printf("Stop_turn right -> false\n");
				}
			}
			//printf("y_array(%f)\tx_array(%f) for i <%d> from *soa <%d>\n", y_array[i], x_array[i], i, sizeof(y_array[1]));
		}
	}

	//turn left
	if (turn_direction == 1) {
		uint counta = 0;

		for (uint i = 0 ; i < sizeof(y_array)/sizeof(double); i++) {//Use only the left half of the scan
			if ((y_array[i] <= y_box) && (x_array[i] >= x_box) && y_array[i] != 0) {

				counta++;
				if (counta > 5) {	//Turn stops if atleast 5 points are found
					stop_turn = true;
					//printf("Stop_turn left\n");
				} else {
					stop_turn = false;
				}
			}
		}
	}

	//printf("Stop_turn(%i)\n",stop_turn);
	printf(" left: %f | right: %f | front %f ##############\n", left_row_prob, right_row_prob, front_row_prob);

		// TODO fill inputs of statechart
		// Histogrammvalues
		statechart.setLeftRowY(left_row_y);
		statechart.setFrontRowx(front_row_x);
		statechart.setFrontRowx(front_row_x);
		statechart.setRightRowY(right_row_y);

		statechart.setLeftRowProb(left_row_prob);
		statechart.setFrontRowProb(front_row_prob);
		statechart.setRightRowProb(right_row_prob);

		statechart.setStopTurn(stop_turn);

		//Codepattern
		statechart.setDirect(code.get_Direction(code.command[statechart.getCommandCount()]+1));
		statechart.setRows(code.get_Rows(code.command[statechart.getCommandCount()]));
		statechart.setMaxiN(x_hist_rowcount->get_Maxi_n(0,2));


		// End of user code don't delete this line
	}


	/**
	 * publish messages to topic task_cmd_vel
	 *
	 * @generated
	 */

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

		Codepattern code(CodePattern);
		statechart.setDirect(code.get_Direction(code.command[statechart.getCommandCount()]+1));
		statechart.setRows(code.get_Rows(code.command[statechart.getCommandCount()]));
		statechart.switch_State();
		//statechart.printState();
		geometry_msgs::Twist msg;
		msg.linear.x = statechart.getLinear();
		msg.angular.z = statechart.getAngular();
		//statechart.printState();
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
} // end of namespace
