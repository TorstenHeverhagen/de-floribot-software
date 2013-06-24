/*
 * Statediagramm.cpp
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#include "Statediagramm.h"

namespace floribot_task1 {

Statediagramm::Statediagramm() {
	state = Init;
	next_state = Init;
	last_state = Init;

	row_width = 0;
	left_row_y = 0;
	right_row_y = 0;
	angular = 0;
	linear = 0;
	Leaving_Row_timer = 0;
}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {
	geometry_msgs::Twist vel;

	 switch (state) {
		case Init:
			vel.angular.z = 0;
			vel.linear.x = 0;

			next_state = Inside_Row;
			break;

	    case Inside_Row:
	    	// entry action
	    	if(state != last_state) {
	    		// do something

	    		last_state = state;
	    	}
	    	// during actions

	    	// transitions
	    	if (left_row_y>row_width/3 && right_row_y<-row_width/3 ) {
	    		//compute angular
	    		angular = (left_row_y + right_row_y)/2*1.5;
	    	} else if (left_row_y == 0 && right_row_y == 0 ) {
	    		next_state = Leaving_Row;
	    	}


			break;
		case Leaving_Row:
	    	// entry action
	    	if(state != last_state) {
	    		Leaving_Row_timer = 0;
	    		last_state = state;
	    	}
	    	// during actions
	    	Leaving_Row_timer++;
	    	// transitions
	    	if (Leaving_Row_timer/(double)tick_rate > 1.0) {
				//compute angular
				next_state = Inside_Row;
			}
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
	 state = next_state;
}



}

/* namespace floribot_task2 */
