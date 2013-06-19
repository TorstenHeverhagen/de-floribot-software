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
    tick_rate = 100;
    n_.getParam("/floribot_task2/tick_rate", tick_rate);
    CodePattern = "";
    n_.getParam("/floribot_task2/CodePattern", CodePattern);
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
	// TODO: fill with your code
	Codepattern code(CodePattern);

if (code.check())  // Wenn CodePattern richtig übergeben wurde, dann startet die Fahrt
	{
	int i = 0;
	while(i<=code.get_Amount_Commands())
	{
		if (code.get_Rows(code.starts[i]) == "S")
		{

		}

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

// TODO: define your methods


// End of user code don't delete this line

} // end of namespace
