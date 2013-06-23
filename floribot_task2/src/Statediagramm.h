/*
 * Statediagramm.h
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#ifndef STATEDIAGRAMM_H_
#define STATEDIAGRAMM_H_

#include <string.h>
//#include "rtwtypes.h"
#include <geometry_msgs/Twist.h>


namespace floribot_task2 {

class Statediagramm {
public:
	Statediagramm(int state);
	virtual ~Statediagramm();
	void switch_State(int state);

#define START 0
#define INROW 1
#define ENDROW 2
#define LEFTTURN 3
#define RIGHTURN 4
#define CROSSRIGHT 5
#define CROSSLEFT 6
#define FULLTURN 7

	geometry_msgs::Twist last_published;
		float angular, linear;




private:
	int state;


};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
