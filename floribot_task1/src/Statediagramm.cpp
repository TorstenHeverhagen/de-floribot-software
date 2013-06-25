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
	left_row_y_prob = 0;
	right_row_y = 0;
	right_row_y_prob = 0;
	row_x = 0;
	row_x_prob = 0;
	prob_trashhold = 0;

	tick_rate = 0;

	angular = 0;
	linear = 0;
	Leaving_Row_timer = 0;


}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {

	 switch (state) {
		case Init:
			linear = 0;
			angular = 0;

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
	    	if (left_row_y>row_width/3 && right_row_y<-row_width/3 && left_row_y_prob > prob_trashhold && right_row_y_prob > prob_trashhold) {
	    		//compute angular
	    		angular = (left_row_y + right_row_y);
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

		default:
			break;
	}
	 state = next_state;
}



}

/* namespace floribot_task2 */
