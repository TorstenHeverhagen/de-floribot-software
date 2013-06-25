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
	tick_rate = 100;
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

	x_hist = new Histogramm(x_hist_min, x_hist_max, x_hist_width);
	y_hist = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	//x_hist_rowcount = new Histogramm(y_hist_min, y_hist_max, y_hist_width);
	x_hist_rowcount = new Histogramm(0,3,0.1);

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

	// fill statechart constants
	statechart.setRowWidth(row_width);
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
	int turn_direction = code.get_Direction(code.command[statechart.getCommandCount()]+1);
	//printf(" direction: %i \n", turn_direction);
	//int rows = code.get_Rows(code.command[statechart.getCommandCount()]);

	//code.check();  // sollte hier noch abgefragt werden mit if

	// Histogramme füllen

	x_hist-> clear();
	y_hist -> clear();

	x_hist_rowcount->clear();

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


	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < 2) {
			float x = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			x_hist->put(x);
			x_hist_rowcount->put(x);
			float y = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
			y_hist->put(y);
			}
		}

	//ROS_INFO("x");
	//x_hist->print();
	//ROS_INFO("y");
	//y_hist->print();

	// x_hist_rowcount Auswerten bei Reihenpassage
		//int hauptmax_n = x_hist_rowcount->get_Maxi_n(2,1);  // n des hauptmaximums
		//int huaptmax_n_alt = hauptmax_n;



	// Codepattern auswerten und als eingangsvariablen übergeben

	//Turn right/left (FB)
	//Read in the scan x-> front, y-> left, Turn direction: true = left, false = right

	float x_array[scan.ranges.size()];
	float y_array[scan.ranges.size()];


	for (uint i = 0; i < scan.ranges.size(); i++) {
		if(scan.ranges[i] < 3) {
			x_array[i] = scan.ranges[i] * cos(scan.angle_min+i*scan.angle_increment);
			y_array[i] = scan.ranges[i] * sin(scan.angle_min+i*scan.angle_increment);
		}
	}

	//turn right
	if (turn_direction == false){
		uint counta = 0;

		for(uint i = 0; i < sizeof(y_array)/2; i++){	//Use only the right half of the scan
			if (y_array[i]>= -y_box && x_array[i] <= x_box){
				counta++;

				if (counta > 5){			//Turn stops if atleast 5 points are found
					stop_turn = true;
					printf("%d",stop_turn);
				}
			}
		}
	}

	//turn left
	if (turn_direction == true){
		uint counta = 0;

		for(uint i = sizeof(y_array)/2; i < sizeof(y_array); i++){	//Use only the left half of the scan
			if (y_array[i]<= y_box && x_array[i] <= x_box){

				counta++;
				if (counta > 5){			//Turn stops if atleast 5 points are found
					stop_turn = true;
					printf("%d",stop_turn);
				}
			}
		}
	}

		// fill inputs of statechart
		statechart.setLeftRowY(y_hist->get_mean(0.3,1));
		//printf("leftrowy: %f \n",y_hist->get_mean(0.3,1) );
		//printf("rightrowy: %f\n",y_hist->get_mean(-1,-0.3));
		statechart.setRightRowY(y_hist->get_mean(-1,-0.3));
		statechart.setMiddRowX(44); //TODO setze midd_row_x aus berechnung
		//Codepattern
		statechart.setDirect(code.get_Direction(code.command[statechart.getCommandCount()]+1));
		statechart.setRows(code.get_Rows(code.command[statechart.getCommandCount()]));
		statechart.setMaxiN(x_hist_rowcount->get_Maxi_n(0,2));// TODO grenzen angeben
		// End of user code don't delete this line
	}
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
		statechart.setLeftRowY(y_hist->get_mean(0.3,1));

		statechart.setRightRowY(y_hist->get_mean(-1,-0.3));
		statechart.setMiddRowX(44); //TODO setze midd_row_x aus berechnung
		//Codepattern
		statechart.setDirect(code.get_Direction(code.command[statechart.getCommandCount()]+1));
		statechart.setRows(code.get_Rows(code.command[statechart.getCommandCount()]));
		statechart.setMaxiN(x_hist_rowcount->get_Maxi_n(0,2));// TODO grenzen angeben

		statechart.switch_State();
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
