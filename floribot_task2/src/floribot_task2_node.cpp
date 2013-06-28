/*
 * File: floribot_task2_node.cpp
 * node floribot_task2
 *
 * @author: floribot_acceleo
 */

#include "Floribot_task2.h"

using namespace floribot_task2;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_task2_node");
	ros::NodeHandle nh;
	Floribot_task2 node(nh);

	ros::Rate r(node.get_tick_rate());
	while (ros::ok())
	{
		ros::spinOnce();
		node.tick();
		r.sleep();
	}
	return 0;
}

