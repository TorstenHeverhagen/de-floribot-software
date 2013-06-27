/*
 * File: floribot_base_node.cpp
 * node floribot_base
 *
 * @author: floribot_acceleo
 */

#include "Floribot_base.h"

using namespace floribot_base;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_base_node");
	ros::NodeHandle nh;
	Floribot_base node(nh);

	ros::spin();

	return 0;
}

