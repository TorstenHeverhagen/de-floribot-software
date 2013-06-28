/*
 * File: floribot_task5_nav_node.cpp
 * node floribot_task5_nav
 *
 * @author: floribot_acceleo
 */

#include "Floribot_task5_nav.h"

using namespace floribot_task5;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_task5_nav_node");
	ros::NodeHandle nh;
	Floribot_task5_nav node(nh);

	ros::spin();

	return 0;
}

