/*
 * File: floribot_find_goal_node.cpp
 * node floribot_find_goal
 *
 * @author: floribot_acceleo
 */

#include "Floribot_find_goal.h"

using namespace floribot_navigation;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_find_goal_node");
	ros::NodeHandle nh;
	Floribot_find_goal node(nh);

	ros::Rate r(node.get_tick_rate());
	while (ros::ok())
	{
		ros::spinOnce();
		node.tick();
		r.sleep();
	}
	return 0;
}

