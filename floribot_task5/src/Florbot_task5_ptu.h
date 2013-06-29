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
#include <sensor_msgs/JointState.h>
#include <std_msgs/Int8.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_task5 {

class Florbot_task5_ptu 
{
	typedef enum {
		Init = 0,
		Wait_For_Start = 10,
		Go_to_Dropposition = 20,
		Release_Ball = 30,
		Go_to_Driveposition = 40
	} Task5_PTU_States;

public:
	Florbot_task5_ptu(ros::NodeHandle n);
	virtual ~Florbot_task5_ptu();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void publish_ptu46_cmd (sensor_msgs::JointState msg);
	void ptu_action_message (const std_msgs::Int8::ConstPtr& msg);

	// Start of user code additional public members
	// TODO: declare your additional public members
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	int tick_rate;
	double pan2;
	double tilt2;
	double pan1;
	double tilt1;
	double tilt_vel;
	double pan_vel;
	ros::Publisher ptu46_cmd_pub;
	ros::Subscriber ptu_action_sub;
	// Start of user code additional members
	ros::ServiceClient client_interface_kit;
	Task5_PTU_States state, next_state, last_state;
	int Drop_timer, Release_timer, Drive_timer;
	double drop_time, release_time, drive_time;
	int trigger;

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORBOT_TASK5_PTU_H_ */
