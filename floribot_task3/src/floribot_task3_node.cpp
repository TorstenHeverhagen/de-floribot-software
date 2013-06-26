/*
 * File: floribot_task3_node.cpp
 * node floribot_task3
 *
 * @author: floribot_acceleo
 */

#include "Floribot_task3.h"

using namespace floribot_task3;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "floribot_task3_node");
	ros::NodeHandle nh;
	Floribot_task3 node(nh);

	ros::spin();

	return 0;
}

