/*
 * File: Floribot_base.h
 * node floribot_base
 *
 * @author: floribot_acceleo
 */

#ifndef FLORIBOT_BASE_H_
#define FLORIBOT_BASE_H_

#include <ros/ros.h>
#include <string>
#include <geometry_msgs/Twist.h>
#include "explorer_comms.h"

namespace floribot_base {

class Floribot_base 
{
public:
	Floribot_base(ros::NodeHandle n);
	virtual ~Floribot_base();
	void tick();
	int get_tick_rate();

	void cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg);

    double getVelX() const;
    void setVelX(double velX);
    double getVelYaw() const;
    void setVelYaw(double velYaw);
private:
	ros::NodeHandle n_;
	std::string tty_ssc_32;
	int tick_rate;
	ros::Subscriber cmd_vel_sub;
	// Start of user code additional members

    double vel_x;
    double vel_yaw;
    /** The SSC-32 comm port **/
    explorer_comm_t *m_ssc32Dev;

	// End of user code  don't delete this line
};

} // end of namespace

#endif /* FLORIBOT_BASE_H_ */
