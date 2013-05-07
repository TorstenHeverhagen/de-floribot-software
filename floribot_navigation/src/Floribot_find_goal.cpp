/*
 * File: Floribot_find_goal.cpp
 * node floribot_find_goal
 *
 * @author: floribot_acceleo
 * @generated
 */

#include "Floribot_find_goal.h"
// Start of user code specific includes
// TODO: include your own headers

// End of user code don't delete this line

namespace floribot_navigation {

Floribot_find_goal::Floribot_find_goal(ros::NodeHandle n) : n_(n)
{
	count = 0;
	scan_sub = n_.subscribe("scan", 1,
			&Floribot_find_goal::scan_message, this);

	pub = n_.advertise<geometry_msgs::Twist>("cmd_vel", 1);

	tick_rate = 100;
	n_.getParam("/floribot_find_goal/tick_rate", tick_rate);
} // end of constructor

Floribot_find_goal::~Floribot_find_goal()
{
	// Start of user code destructor
	// TODO: fill with your code

	// End of user code don't delete this line
} // end of destructor

/**
 * process messages from topic scan
 *
 * @generated
 */
void Floribot_find_goal::scan_message (const sensor_msgs::LaserScan::ConstPtr& msg)
{
	// Start of user code process message
	// TODO: fill with your code
	int numRanges = msg->ranges.size();

	float min = msg->ranges[0];
	for (int i = 0; i < numRanges; i++)
	{
	      if (msg->ranges[i] < min)
	          min = msg->ranges[i];
	}

	if (min < 1.0)
	{
		this->throughRow(msg);
	}
	else
	{
		int dir = 1;
		if (count%2)
		{
			dir = -dir;
		}

		geometry_msgs::Twist vel;
		ros::Rate rate(10);
		for (int i = 0; i < 10; i++)
		{
			vel.angular.z = 0;
			vel.linear.x = 0.5;
			last_published = vel;
			this->tick();
			rate.sleep();
		}
		for (int i = 0; i < 20; i++)
		{
			vel.angular.z = dir * 3.14;
			vel.linear.x = (3.14 * (0.75/2))/2;
			last_published = vel;
			this->tick();
			rate.sleep();
		}
		count++;
	}

	// End of user code don't delete this line
}

/**
 * tick is triggered 
 *
 * @generated
 */
void Floribot_find_goal::tick ()
{
	// Start of user code call your own code
	// TODO: fill with your code

	pub.publish(last_published);

	// End of user code don't delete this line
}

/**
 * returns the tick rate
 *
 * @generated
 */
int Floribot_find_goal::get_tick_rate ()
{
	return tick_rate;
}

// Start of user code additional members

// TODO: define your methods

void Floribot_find_goal::throughRow(const sensor_msgs::LaserScan::ConstPtr &scan)
{
	// Durch Reihe navigieren

	float searchRange = 1.0;
	int numRanges = scan->ranges.size();
	float angleIncrement = scan->angle_increment;

	float robotWidth = 0.4;
	float speed = 0.2;

	float x = 0;
	float y = 0, yr = 0, yl = 0;

	x = this->calcFieldOfAttentionX(scan, searchRange, angleIncrement, numRanges, robotWidth, x);
	y = this->calcFieldOfAttentionY(scan, searchRange, angleIncrement, numRanges, y, yr, yl);

	this->setVelocity(x, y, speed);
}

float Floribot_find_goal::calcFieldOfAttentionX(const sensor_msgs::LaserScan::ConstPtr &scan, float &searchRange, float &angleIncrement, int &numRanges, float &robotWidth, float &x)
{
	float y = 0;
	int count = 0;

	for (int i = 0; i < numRanges; i++)
	{
		if (scan->ranges[i] < searchRange)
		{
			y = sin((i-(numRanges/2)) * angleIncrement) * scan->ranges[i];

			if (y > -robotWidth/2 && y < robotWidth/2)
			{
				x += cos((i-(numRanges/2)) * angleIncrement) * scan->ranges[i];
				count++;
			}
		}
	}

	if (count != 0)
	{
		x /= count;
	}
	else
	{
		x = 1;
	}
	return x;
}

float Floribot_find_goal::calcFieldOfAttentionY(const sensor_msgs::LaserScan::ConstPtr &scan, float &searchRange, float &angleIncrement, int &numRanges, float &y, float &yr, float &yl)
{
	int countr = 0, countl = 0;

	for (int i = 0; i < numRanges; i++)
	{
		if (scan->ranges[i] < searchRange)
		{
			if (i < numRanges/2)
			{
				yr += (sin((i-(numRanges/2)) * angleIncrement) * scan->ranges[i]);
				countr++;
			}
			else
			{
				yl += (sin((i-(numRanges/2)) * angleIncrement) * scan->ranges[i]);
				countl++;
			}
		}
	}

	if (countr > 0)
	{
		yr /= countr;
	}
	if(countl > 0)
	{
		yl /= countl;
	}

	y = yr + yl;

	return y;
}

void Floribot_find_goal::setVelocity(float &x, float &y, float &speed)
{
	if(x < 0.3)
	{
		linear = 0.0;
	}
	else
	{
		linear = speed;
	}

	if (y < -0.1)
	{
		angular = -speed;
	}
	else if ((y >= -0.1 && y <= 0.1) && y != 0)
	{
		angular = 0.0;
	}
	else
	{
		angular = speed;
	}

	geometry_msgs::Twist vel;

	vel.angular.z = angular;
	vel.linear.x = linear;
	last_published = vel;
}

// End of user code don't delete this line

} // end of namespace
