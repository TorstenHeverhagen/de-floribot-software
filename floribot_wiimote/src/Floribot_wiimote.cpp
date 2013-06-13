/*
 * File: Floribot_wiimote.cpp
 * node floribot_wiimote
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_wiimote.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_wiimote {

Floribot_wiimote::Floribot_wiimote(ros::NodeHandle n) : n_(n)
{
	joy_set_feedback_pub = n_.advertise<sensor_msgs::JoyFeedbackArray>("joy/set_feedback",1);
	cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("cmd_vel",1);
	task_cmd_vel_sub = n_.subscribe("task_cmd_vel", 1,
			&Floribot_wiimote::task_cmd_vel_message, this);
	joy_sub = n_.subscribe("joy", 1,
			&Floribot_wiimote::joy_message, this);
    tick_rate = 100;
    n_.getParam("/floribot_wiimote/tick_rate", tick_rate);
    // Start of user code constructor
    actual_state = MANUAL;
    next_state = MANUAL;
    new_msg = false;
    // End of user code don't delete this line

} // end of constructor

Floribot_wiimote::~Floribot_wiimote()
{
    // Start of user code destructor
    // TODO: fill with your code
    // End of user code don't delete this line
} // end of destructor

/**
 * publish messages to topic joy/set_feedback
 *
 * @generated
 */
void Floribot_wiimote::publish_joy_set_feedback (sensor_msgs::JoyFeedbackArray msg)
{
	joy_set_feedback_pub.publish(msg);
}

/**
 * publish messages to topic cmd_vel
 *
 * @generated
 */
void Floribot_wiimote::publish_cmd_vel (geometry_msgs::Twist msg)
{
	cmd_vel_pub.publish(msg);
}

/**
 * process messages from topic task_cmd_vel
 *
 * @generated
 */
void Floribot_wiimote::task_cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg)
{
	// Start of user code process message
	// TODO: fill with your code
	// End of user code don't delete this line
}

/**
 * process messages from topic joy
 *
 * @generated
 */
void Floribot_wiimote::joy_message (const sensor_msgs::Joy::ConstPtr& msg)
{
	// Start of user code process message
	// TODO: fill with your code
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_wiimote::tick ()
{
	// Start of user code call your own code
	if (new_msg) {
		// 1 Button
		bool oneBtn = joy_msg.buttons[0];
		// 2 Button
		bool twoBtn = joy_msg.buttons[1];

		switch (actual_state) {
			case MANUAL:
				publish_cmd_vel(joy_to_vel());
				if (twoBtn) next_state = TASK_1_START;
				break;

			case TASK_1_START:
				publish_cmd_vel(task1_vel);
				if (oneBtn) next_state = MANUAL;
				break;
			default:
				next_state = MANUAL;
				break;
		}
		actual_state = next_state;
		new_msg = false;
	}
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_wiimote::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

geometry_msgs::Twist Floribot_wiimote::joy_to_vel() {
	// velocity difference
	geometry_msgs::Twist vel;
	// buttons
	bool bBtn = joy_msg.buttons[3];
	bool leftBtn = joy_msg.buttons[6];
	bool rightBtn = joy_msg.buttons[7];
	bool upBtn = joy_msg.buttons[8];
	bool downBtn = joy_msg.buttons[9];

	// if any drive control related button is pressed:
	if (bBtn || leftBtn || rightBtn || upBtn || downBtn) {
		// Pressed B-button for control only via accelerometer
		if (bBtn) {
			// define forward/backward movement by pitch angle
			vel.linear.x = (joy_msg.axes[1]) / DIRECT_PITCH_AXIS_DIV;
			// define left/right movement by roll angle
			vel.angular.z = -1 * joy_msg.axes[0] / DIRECT_ROLL_AXIS_DIV;
		} else if (upBtn) { // Up on D-pad pressed
			// move forward
			if (joy_msg.axes[1] > 0)
				vel.linear.x = (joy_msg.axes[1]) / BUTTON_PITCH_AXIS_DIV;
			else
				vel.linear.x = 0;
			// don't move sideways
			vel.angular.z = 0;
		} else if (downBtn) { // Down on D-pad pressed
			// move backward
			if (joy_msg.axes[1] < 0)
				vel.linear.x = (joy_msg.axes[1]) / BUTTON_PITCH_AXIS_DIV;
			else
				vel.linear.x = 0;
			// don't move sideways
			vel.angular.z = 0;
		} else if (rightBtn) { // Right on D-pad pressed
			// move right
			if (joy_msg.axes[0] > 0)
				vel.angular.z = (joy_msg.axes[0]) / BUTTON_ROLL_AXIS_DIV;
			else
				vel.angular.z = 0;
			// don't move straight
			vel.linear.x = 0;
		} else if (leftBtn) { // Left on D-pad pressed
			// move left
			if (joy_msg.axes[0] < 0)
				vel.angular.z = (joy_msg.axes[0]) / BUTTON_ROLL_AXIS_DIV;
			else
				vel.angular.z = 0;
			// don't move straight
			vel.linear.x = 0;
		}
		// log
		ROS_INFO("z = %f , x = %f", vel.angular.z, vel.linear.x);
	} else {
		// no drive control: no velocity - stand still!
		vel.angular.z = 0;
		vel.linear.x = 0;
	}
	return vel;
}

// End of user code don't delete this line

} // end of namespace
