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
#include <sensor_msgs/JoyFeedbackArray.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

// Enumeration of available control modes
enum ControlMode {
	NO_CONTROL,
	MANUAL,
	TASK_1_SET,
	TASK_1_START,
	TASK_2,
	TASK_3,
	TASK_4,
	TASK_5
};

// Type for control modes
typedef ControlMode ControlMode_t;

class Floribot_wiimote 
{
public:
	Floribot_wiimote(ros::NodeHandle n);
	virtual ~Floribot_wiimote();
	void tick();
	int get_tick_rate();

	void publish_joy_set_feedback (sensor_msgs::JoyFeedbackArray msg);
	void publish_cmd_vel (geometry_msgs::Twist msg);
	void task_cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg);
	void joy_message (const sensor_msgs::Joy::ConstPtr& msg);

	// Start of user code additional public members
	// TODO: declare your variables and methods
	// End of user code  don't delete this line
private:
	ros::NodeHandle n_;
	int tick_rate;
	ros::Publisher joy_set_feedback_pub;
	ros::Publisher cmd_vel_pub;
	ros::Subscriber task_cmd_vel_sub;
	ros::Subscriber joy_sub;
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
