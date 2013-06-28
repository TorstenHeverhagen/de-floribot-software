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

	direction = 0;

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
	row_x_min = 0;
	prob_trashhold = 0;

	alpha_mean = 0;
	alpha_trashhold = 0;

	tick_rate = 0;
	leaving_time = 0;

	Leaving_Row_timer = 0;
	Turn_To_Next_Row_timer = 0;
	Row_Counter = 0;
	x_max_turn = 0;
	x_max_turn_erst = 7;

}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {

	bool isSideRowBoth = left_row_y_prob >= prob_trashhold
					&& right_row_y_prob >= prob_trashhold;
	bool isSideRowLeft = left_row_y_prob >= prob_trashhold
					&& !(right_row_y_prob >= prob_trashhold);
	bool isSideRowRight = !(left_row_y_prob >= prob_trashhold)
					&& right_row_y_prob >= prob_trashhold;
	bool isFrontRow = (row_x_prob >= prob_trashhold);
	bool isAlpha = alpha_mean > 0 && alpha_trashhold > alpha_mean;

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
		if (isSideRowBoth) {
			if (!isFrontRow) {
				linear = (1 - (fabs(left_row_y + right_row_y) / row_width))
						* max_speed_linear;
				angular = (left_row_y + right_row_y) / row_width
						* max_speed_angular;
			}
			else if (isFrontRow && row_x < row_x_min) {
				linear = (1 - (fabs(left_row_y + right_row_y) / row_width))
						* max_speed_linear * row_x;
				angular = (left_row_y + right_row_y) / row_width
						* max_speed_angular;
			}

		} else if (isSideRowRight && !isSideRowLeft) {
			if (!isFrontRow) {
				linear = (1 - (fabs(row_width + 2 * right_row_y) / row_width))
						* max_speed_linear;
				angular = (row_width + 2 * right_row_y) / row_width
						* max_speed_angular;
			}
			else if (isFrontRow && row_x < row_x_min) {
				linear = (1 - (fabs(row_width + 2 * right_row_y) / row_width))
						* max_speed_linear * row_x;
				angular = (row_width + 2 * right_row_y) / row_width
						* max_speed_angular;
			}

		} else if (isSideRowLeft && !isSideRowRight) {
			if (!isFrontRow) {
				linear = (1 - (fabs(-row_width + 2 * left_row_y)) / row_width)
								* max_speed_linear * row_x;
				angular = (-row_width + 2 * left_row_y) / row_width
						* max_speed_angular;
			}
			else if (isFrontRow && row_x < row_x_min) {
				linear = (1 - (fabs(-row_width + 2 * left_row_y)) / row_width)
										* max_speed_linear;
				angular = (-row_width + 2 * left_row_y) / row_width
						* max_speed_angular;
			}
		}
		// transitions
		else if (!isFrontRow && !isSideRowBoth && !isSideRowLeft && !isSideRowRight) {
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

		//compute angular
		linear = max_speed_linear;
		angular = 0.0;

		// transitions


		if (isSideRowBoth || isSideRowLeft || isSideRowRight) {
			next_state = Inside_Row;

		} else if (Leaving_Row_timer / (double) tick_rate > leaving_time) {
			next_state = Turn_Along_Row;
		}

		break;

	case Turn_Along_Row:
		// entry action
		if (state != last_state) {
			last_state = state;
		}

		// during actions
		linear = 0.0;
		angular = direction * max_speed_angular;

		// transitions
		if (isAlpha || isSideRowBoth || isSideRowLeft || isSideRowRight) {
			next_state = Move_To_Next_Row;
		}
		break;

	case Move_To_Next_Row:
		if(state != last_state) {
			last_state = state;
			Turn_To_Next_Row_timer = 0;
			Row_Counter = 0;
		}
		// during actions
		angular = 0.0;
		linear = max_speed_linear;

		if ((x_max_turn == x_max_turn_erst) and (Turn_To_Next_Row_timer==0)) {
			Row_Counter++;
			Turn_To_Next_Row_timer++;
		} else if (x_max_turn != x_max_turn_erst) {
			Turn_To_Next_Row_timer = 0;
		} else if (Row_Counter == 2) {
			next_state = Turn_Into_Row;
		}

		break;

	case Turn_Into_Row:
		// entry action
		if (state != last_state) {
			last_state = state;
		}
		// during actions
		if (!isSideRowBoth) {
			linear = 0.0;
			angular = direction * max_speed_angular;
			if (direction == 1){
				direction = -1;
			} else if (direction == -1) {
				direction = 1;
			}
		// transitions
		} else if (isSideRowBoth || isSideRowLeft || isSideRowRight) {
			next_state = Inside_Row;
		}
		break;

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
