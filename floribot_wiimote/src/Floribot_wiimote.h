/*
 * File: Floribot_wiimote.h
 * node floribot_wiimote
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_WIIMOTE_H_
#define FLORIBOT_WIIMOTE_H_

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

class Floribot_wiimote 
{
public:
	Floribot_wiimote(ros::NodeHandle n);
	virtual ~Floribot_wiimote();
	void tick(const ros::TimerEvent& event);
	int get_tick_rate();

	void joy_message (const sensor_msgs::Joy::ConstPtr& msg);
	void publish_joy_set_feedback (sensor_msgs::JoyFeedbackArray msg);
	void accu_low_message (const std_msgs::Bool::ConstPtr& msg);
	void task_cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg);
	void publish_cmd_vel (geometry_msgs::Twist msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	ros::Timer timer;
	int tick_rate;
	ros::Subscriber joy_sub;
	ros::Publisher joy_set_feedback_pub;
	ros::Subscriber accu_low_sub;
	ros::Subscriber task_cmd_vel_sub;
	ros::Publisher cmd_vel_pub;
	// Start of user code additional members

	geometry_msgs::Twist joy_to_vel();
	sensor_msgs::JoyFeedbackArray prepare_joy_feedback();

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_WIIMOTE_H_ */
