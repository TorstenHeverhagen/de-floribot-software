/*
 * File: Floribot_wiimote.h
 * node floribot_wiimote
 *
 * @author: Torsten Heverhagen
 */

#ifndef FLORIBOT_WIIMOTE_H_
#define FLORIBOT_WIIMOTE_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <sensor_msgs/Joy.h>

namespace floribot_wiimote {

class Floribot_wiimote 
{
public:
	Floribot_wiimote(ros::NodeHandle n);
	virtual ~Floribot_wiimote();
	void tick();

	void publish_cmd_vel (const geometry_msgs::Twist::ConstPtr& msg);
	void publish_joy_set_feedback (const sensor_msgs::JoyFeedbackArray::ConstPtr& msg);
	void joy_message (const sensor_msgs::Joy::ConstPtr& msg);

private:
	ros::NodeHandle n_;
	ros::Publisher cmd_vel_pub;
	ros::Publisher joy_set_feedback_pub;
	ros::Subscriber joy_sub;
	// Start of user code additional members
		// TODO: declare your variables and methods
	// End of user code
};

} // end of namespace

#endif /* FLORIBOT_WIIMOTE_H_ */
