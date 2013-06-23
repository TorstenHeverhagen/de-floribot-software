/*
 * Statediagramm.cpp
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#include "Statediagramm.h"

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
