/*
 * File: floribot_task1_node.cpp
 * node floribot_task1
 *
 * @author: floribot_acceleo
 */

#include "Floribot_task1.h"

using namespace floribot_task1;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_task1_node");
	ros::NodeHandle nh;
	Floribot_task1 node(nh);

	ros::Rate r(node.get_tick_rate());
	while (ros::ok())
	{
		ros::spinOnce();
		node.tick();
		r.sleep();
	}
	return 0;
}


