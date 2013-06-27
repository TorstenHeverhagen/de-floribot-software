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
	robot_width = 0;

	max_speed_angular = 0;
	max_speed_linear = 0;

	angular = 0;
	linear = 0;

	left_row_y = 0;
	left_row_y_prob = 0;
	right_row_y = 0;
	right_row_y_prob = 0;
	row_x = 0;
	row_x_prob = 0;
	prob_trashhold = 0;

	tick_rate = 0;

	Leaving_Row_timer = 0;
	Turn_Along_Row_timer = 0;
	Turn_Too_Row_timer = 0;

}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {

	bool isSideRowBoth = left_row_y_prob >= prob_trashhold
					&& right_row_y_prob >= prob_trashhold;
	switch (state) {
	case Init:
		linear = 0;
		angular = 0;

		next_state = Inside_Row;
		break;

	case Inside_Row:
		// entry action
		if (state != last_state) {
			last_state = state;
		}
		// during actions

		// transitions

		if (isSideRowBoth) {
			linear = (1 - (fabs(left_row_y + right_row_y) / row_width))
					* max_speed_linear;
			angular = (left_row_y + right_row_y) / row_width
					* max_speed_angular;

		} else if (left_row_y_prob < prob_trashhold
				&& right_row_y_prob < prob_trashhold) {
			next_state = Leaving_Row;
		}

		break;

	case Leaving_Row:
		// entry action
		if (state != last_state) {
			Leaving_Row_timer = 0;
			last_state = state;
		}
		// during actions
		Leaving_Row_timer++;
		// transitions
		if (Leaving_Row_timer / (double) tick_rate < 0.5) {
			//compute angular
			linear = max_speed_linear;
			angular = 0.0;

		} else  {
			//compute angular
			next_state = Turn_Along_Row;
		}
		break;
/*
	case Turn_Along_Row:
		// entry action
		if (state != last_state) {
			Turn_Along_Row_timer = 0;
			last_state = state;
		}
		// during actions
		Turn_Along_Row_timer++;
		// transitions
		if (left_row_y_prob < prob_trashhold
						&& right_row_y_prob < prob_trashhold) {
			//compute angular
			linear = 0.0;
			angular = max_speed_angular;
		} else if (isSideRowBoth) {
			//compute angular
			next_state = Inside_Row;
		}
		break;

	case Turn_Too_Row:
		// entry action
		if (state != last_state) {
			Turn_Too_Row_timer = 0;
			last_state = state;
		}
		// during actions
		Turn_Too_Row_timer++;
		// transitions
		if ((Turn_Too_Row_timer / (double) tick_rate < 0.5)
				&& (left_row_y_prob < prob_trashhold
						&& right_row_y_prob < prob_trashhold)) {
			//compute angular
			linear = max_speed_linear;
			angular = 0.0;
		} else if ((Turn_Too_Row_timer / (double) tick_rate < 1.5)
				&& (left_row_y_prob < prob_trashhold
						&& right_row_y_prob < prob_trashhold)) {
			//compute angular
			linear = 0.0;
			angular = max_speed_angular;
		} else if (isSideRowBoth) {
			//compute angular
			next_state = Inside_Row;
		}
		break;
*/
	default:
		break;
	}
	state = next_state;
}

void Statediagramm::printState() {
	printf("State = %i\n", state);
}

}

/* namespace floribot_task2 */
