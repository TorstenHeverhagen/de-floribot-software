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
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task2 {

class Floribot_task2 
{
public:
	Floribot_task2(ros::NodeHandle n);
	virtual ~Floribot_task2();
	void tick();
	int get_tick_rate();

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);
	void publish_task_cmd_vel (geometry_msgs::Twist msg);

private:
	ros::NodeHandle n_;
	std::string CodePattern;
	int tick_rate;
	ros::Subscriber scan_sub;
	ros::Publisher task_cmd_vel_pub;
	// Start of user code additional members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_TASK2_H_ */
