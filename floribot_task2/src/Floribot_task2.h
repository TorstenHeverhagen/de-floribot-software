/*
 * File: Floribot_task2.h
 * node floribot_task2
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_TASK2_H_
#define FLORIBOT_TASK2_H_

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
// Start of user code specific includes
#include "Histogramm.h"
#include "Codepattern.h"
// End of user code don't delete this line

namespace floribot_task2 {

class Floribot_task2 
{
public:
	Floribot_task2(ros::NodeHandle n);
	virtual ~Floribot_task2();
	void tick();
	int get_tick_rate();

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& scan);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);
	// Start of user code additional public members
	// TODO: declare your variables and methods
	void throughRow(const sensor_msgs::LaserScan::ConstPtr &scan);
	void turn(bool direction, int rows);
	float calcFieldOfAttentionX(scan, angleIncrement, numRanges, x);
	float calcFieldOfAttentionY(scan, angleIncrement, numRanges, y, yr, yl);
private:
	ros::NodeHandle n_;
	std::string CodePattern;
	int tick_rate;
	ros::Subscriber scan_sub;
	ros::Publisher task_cmd_vel_pub;

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK2_H_ */
