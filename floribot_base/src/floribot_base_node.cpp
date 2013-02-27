/*
 * File: floribot_base_node.cpp
 * node floribot_base
 *
 * @author: Torsten Heverhagen
 */

#include "Floribot_base.h"

using namespace floribot_base;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_base_node");
	ros::NodeHandle nh;
	Floribot_base node(nh);

	ros::Rate r(node.get_tick_rate());
	while (ros::ok())
	{
		ros::spinOnce();
		node.tick();
		r.sleep();
	}
	return 0;
}

