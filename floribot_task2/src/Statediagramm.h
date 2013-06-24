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



	geometry_msgs::Twist last_published;
		float angular, linear;




private:
	int state;



};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
