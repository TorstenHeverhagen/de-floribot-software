/*
 * File: Floribot_base.cpp
 * node floribot_base
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_base.h"
// Start of user code specific includes
// TODO: include your own headers
// End of user code don't delete this line

namespace floribot_base {

Floribot_base::Floribot_base(ros::NodeHandle n) : n_(n)
{
	cmd_vel_sub = n_.subscribe("cmd_vel", 1,
			&Floribot_base::cmd_vel_message, this);
    tick_rate = 100;
    n_.getParam("/floribot_base/tick_rate", tick_rate);
    tty_ssc_32 = "/dev/ttyS1";
    n_.getParam("/floribot_base/tty_ssc_32", tty_ssc_32);
    // Start of user code constructor
    vel_x = 0;
    vel_yaw = 0;

    m_ssc32Dev = 0;

	// attempt to open and interact with the SSC-32 board
	m_ssc32Dev = explorer_comm_create("/dev/ttyS1");
	if (m_ssc32Dev == 0)
	{
		perror("Can't open serial port");
	}
	else
	{
		if (explorer_comm_open(m_ssc32Dev) < 0)
		{
			explorer_comm_destroy(m_ssc32Dev);
			m_ssc32Dev = 0;
			perror("failed to connect to Explorer");
		}
	}
    // End of user code don't delete this line

} // end of constructor

Floribot_base::~Floribot_base()
{
    // Start of user code destructor

	explorer_comm_close(m_ssc32Dev);
	m_ssc32Dev = 0;
    // End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic cmd_vel
 *
 * @generated
 */
void Floribot_base::cmd_vel_message (const geometry_msgs::Twist::ConstPtr& msg)
{
	// Start of user code process message
	setVelX(msg->linear.x);
	setVelYaw(msg->angular.z);
	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_base::tick ()
{
	// Start of user code call your own code

    if (explorer_comm_set_speeds(m_ssc32Dev,
                           vel_x,
                           vel_yaw) < 0)
    {
    	perror("failed to set speeds to Explorer");
    }
	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_base::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members


double Floribot_base::getVelX() const
{
    return vel_x;
}

void Floribot_base::setVelX(double velX)
{
    vel_x = velX;
}

double Floribot_base::getVelYaw() const
{
    return vel_yaw;
}

void Floribot_base::setVelYaw(double velYaw)
{
    vel_yaw = velYaw;
}

// End of user code don't delete this line

} // end of namespace
