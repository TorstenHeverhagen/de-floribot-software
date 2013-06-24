/*
 * Statediagramm.cpp
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#include "Statediagramm.h"
#define floribot_tas_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define floribot_task3_IN_inside_row   ((uint8_T)1U)
#define floribot_task3_IN_leaving_row  ((uint8_T)2U)
#define floribot_task3_IN_turning90Lo      ((uint8_T)3U)
#define floribot_task3_IN_turning90Ro      ((uint8_T)4U)
#define floribot_task3_IN_outside_row   ((uint8_T)5U)
#define floribot_task3_IN_turning90Li      ((uint8_T)6U)
#define floribot_task3_IN_turning90Ri      ((uint8_T)7U)

namespace floribot_task2 {

Statediagramm::Statediagramm(int state) {
	// TODO Auto-generated constructor stub

	this->state = state;

}



Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State(int zustand) {
	geometry_msgs::Twist vel;

	 switch (zustand) {
		case 0:
		vel.angular.z = 0;
		vel.linear.x = 0;
		last_published = vel;



			break;

	    case 1:



			break;
		case 2:



			break;
		case 3:



			break;
		case 4:



			break;
		case 5:



			break;
		case 6:



			break;
		case 7:

			break;


		default:
			break;
	}
}



}

/* namespace floribot_task2 */
