/*
 * File: floribot_accu_watchdog_node.cpp
 * node floribot_accu_watchdog
 *
 * @author: floribot_acceleo
 */

#include "Floribot_accu_watchdog.h"

using namespace floribot_base;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_accu_watchdog_node");
	ros::NodeHandle nh;
	Floribot_accu_watchdog node(nh);

	ros::Rate r(node.get_tick_rate());
	while (ros::ok())
	{
		ros::spinOnce();
		node.tick();
		r.sleep();
	}
	return 0;
}

