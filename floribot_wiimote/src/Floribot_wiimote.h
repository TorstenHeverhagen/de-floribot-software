/*
 * File: Floribot_wiimote.h
 * node floribot_wiimote
 *
 * @author: Torsten Heverhagen
 */

#ifndef FLORIBOT_WIIMOTE_H_
#define FLORIBOT_WIIMOTE_H_

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <geometry_msgs/Twist.h>

namespace floribot_wiimote {

class Floribot_wiimote 
{
public:
	Floribot_wiimote(ros::NodeHandle n);
	virtual ~Floribot_wiimote();
	void tick();
	int get_tick_rate();

	void joy_message (const sensor_msgs::Joy::ConstPtr& msg);
	void publish_joy_set_feedback (const sensor_msgs::JoyFeedbackArray::ConstPtr& msg);
	void publish_cmd_vel (const geometry_msgs::Twist::ConstPtr& msg);

private:
	ros::NodeHandle n_;
	ros::Subscriber joy_sub;
	ros::Publisher joy_set_feedback_pub;
	ros::Publisher cmd_vel_pub;
	// Start of user code additional members
		// TODO: declare your variables and methods
	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_WIIMOTE_H_ */
