/*
 * File: Floribot_find_goal.h
 * node floribot_find_goal
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_FIND_GOAL_H_
#define FLORIBOT_FIND_GOAL_H_

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/LaserScan.h>

namespace floribot_navigation {

class Floribot_find_goal 
{
public:
	Floribot_find_goal(ros::NodeHandle n);
	virtual ~Floribot_find_goal();
	void tick();
	int get_tick_rate();

	void scan_message (const sensor_msgs::LaserScan::ConstPtr& msg);

private:
	ros::NodeHandle n_;
	int tick_rate;
	ros::Subscriber scan_sub;
	// Start of user code additional members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_FIND_GOAL_H_ */
