/*
 * File: florbot_task5_ptu_node.cpp
 * node florbot_task5_ptu
 *
 * @author: floribot_acceleo
 */

#include "Florbot_task5_ptu.h"

using namespace floribot_task5;

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "florbot_task5_ptu_node");
	ros::NodeHandle nh;
	Florbot_task5_ptu node(nh);

	ros::spin();

	return 0;
}

