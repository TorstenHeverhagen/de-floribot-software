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
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/JoyFeedbackArray.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

class Floribot_wiimote 
{
public:
	Floribot_wiimote(ros::NodeHandle n);
	virtual ~Floribot_wiimote();
	void tick();
	int get_tick_rate();

	void publish_cmd_vel (geometry_msgs::Twist msg);
	void joy_message (const sensor_msgs::Joy::ConstPtr& msg);
	void task_cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg);
	void publish_joy_set_feedback (sensor_msgs::JoyFeedbackArray msg);

private:
	ros::NodeHandle n_;
	int tick_rate;
	ros::Publisher cmd_vel_pub;
	ros::Subscriber joy_sub;
	ros::Subscriber task_cmd_vel_sub;
	ros::Publisher joy_set_feedback_pub;
	// Start of user code additional members

	geometry_msgs::Twist joy_to_vel();

	sensor_msgs::Joy joy_msg;
	ControlMode_t actual_state;
	ControlMode_t next_state;
	bool new_msg;

	geometry_msgs::Twist task1_vel;
	/* ---Constants--- */

	/* Movement control parameters */

	// divisor for pitch axis value in full accelerometer control mode
	static const int DIRECT_PITCH_AXIS_DIV = 10;
	// divisor for roll axis value in full accelerometer control mode
	static const int DIRECT_ROLL_AXIS_DIV = 30;
	// divisor for pitch axis value in button-controlled accelerometer mode
	static const int BUTTON_PITCH_AXIS_DIV = 20;
	// divisor for roll axis value in button-controlled accelerometer mode
	static const int BUTTON_ROLL_AXIS_DIV = 20;

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_WIIMOTE_H_ */
