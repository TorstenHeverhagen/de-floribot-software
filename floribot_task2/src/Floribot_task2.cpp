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
// End of user code don't delete this line

namespace floribot_task2 {

Floribot_task2::Floribot_task2(ros::NodeHandle n) : n_(n)
{
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_task2::scan_message, this);
	task_cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("task_cmd_vel",1);
    CodePattern = "";
    n_.getParam("/floribot_task2/CodePattern", CodePattern);
    tick_rate = 100;
    n_.getParam("/floribot_task2/tick_rate", tick_rate);
    // Start of user code constructor
    // TODO: fill with your code
    // End of user code don't delete this line

} // end of constructor

Floribot_task2::~Floribot_task2()
{
    // Start of user code destructor
    // TODO: fill with your code
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

	Codepattern code(CodePattern);

if (code.check())  // Wenn CodePattern richtig übergeben wurde, dann startet die Fahrt
	{
	int direction;
	int rows;
	throughRow(msg); // Reihenfahrt inkl. wenden bei hinderniss
	int i = 0;
	while(i<=code.get_Amount_Commands())
	{
		rows = code.get_Rows(code.command[i]);
		if (rows!=0) {
			direction = code.get_Direction(code.command[i]+1);
		}
		else direction = 0;
		turn(direction,rows); // beachte "0" kommando -> wenden und gleiche reihe zurück fahren
		throughRow(msg); // Wenn fahrbefehl
		i++;
	}
	}

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
	// TODO: fill with your code
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


void Floribot_task2::throughRow(const sensor_msgs::LaserScan::ConstPtr& scan) {

// TODO Fill in Bene Bauers Code ;)

	// Durch Reihe navigieren


		int numRanges = scan->ranges.size();
		float angleIncrement = scan->angle_increment;


		float speed = 0.2;

		float x = 0;
		float y = 0, yr = 0, yl = 0;

		x = this->calcFieldOfAttentionX(scan, angleIncrement, numRanges, x);
		y = this->calcFieldOfAttentionY(scan, angleIncrement, numRanges, y, yr, yl);

		this->setVelocity(x, y, speed);

}

void Floribot_task2::turn(bool direction, int rows) {

	switch (direction){
		case -1: //TODO Fill in right turn

			break;

		case 0: // TODO Return same row

			break;

		case 1: // TODO Fill in left turn
			break;

		default:
	}


}

// TODO Implement Method to Count Rows

// End of user code don't delete this line

float Floribot_task2::calcFieldOfAttentionX(scan, angleIncrement, numRanges,x) {
}

float Floribot_task2::calcFieldOfAttentionY(scan, angleIncrement, numRanges, y, yr, yl) {
}

} // end of namespace
