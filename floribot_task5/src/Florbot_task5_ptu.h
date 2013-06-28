/*
 * File: Florbot_task5_ptu.h
 * node florbot_task5_ptu
 *
 * @author: floribot_acceleo
 */

#ifndef FLORBOT_TASK5_PTU_H_
#define FLORBOT_TASK5_PTU_H_

#include <ros/ros.h>
#include <string>
#include <std_msgs/Integer.h>
#include <phidgets/interface_kit_params.h>
#include <sensor_msgs/JointState.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task5 {

class Florbot_task5_ptu 
{
public:
	Florbot_task5_ptu(ros::NodeHandle n);
	virtual ~Florbot_task5_ptu();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void ptu_action_message (const std_msgs::Integer::ConstPtr& msg);
	void publish_phidgets_interface_kit (phidgets::interface_kit_params msg);
	void publish_ptu46_cmd (sensor_msgs::JointState msg);

	// Start of user code additional public members
	// TODO: declare your additional public members
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	double tilt2;
	double pan1;
	double pan_vel;
	double tilt1;
	int tick_rate;
	int ptu_action;
	double pan2;
	double tilt_vel;
	ros::Subscriber ptu_action_sub;
	ros::Publisher phidgets_interface_kit_pub;
	ros::Publisher ptu46_cmd_pub;
	// Start of user code additional members
	// TODO: declare your private variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORBOT_TASK5_PTU_H_ */
