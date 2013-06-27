/*
 * Statediagramm.cpp
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#include "Statediagramm.h"

namespace floribot_task2 {

Statediagramm::Statediagramm() {
	state = Init;
	next_state = Init;
	last_state = Init;

	row_width = 0;
	left_row_y = 0;
	front_row_x = 0;
	front_row_y = 0;
	right_row_y = 0;
	angular = 0;
	linear = 0;
	Leaving_Row_timer = 0;
	Outside_Row_timer  =0;
	tick_rate= 0;

	Row_Counter = 0;  // Zaehlvariable für Reihen bei Passage außerhalb
	Maxi_n = 0;
	Maxi_n_erst = 7;
	Maxi_n_alt = 0;
	direct = 0;
	rows = 0;
	command_count = 0;
	midd_row_x = 0;

	left_row_prob = 0;
	front_row_prob = 0;
	right_row_prob=0;
	row_trashold = 0.2;
	stop_turn = false;

// benes_adds
	row_x = 0;
	row_x_prob = 0;
	prob_trashhold = 0.2;
	leave_time = 0.7;
	alpha = 0;

}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {

	 switch (state) {
		case Init:
			if (state == Init){
				last_state = Init;
			}
			// during actions
			angular = 0;
			linear = 0;
			//transition

			next_state = Inside_Row;
			break;

	    case Inside_Row:
	    	// entry action
	    	if(state != last_state) {
	    		last_state = state;
	    		linear = 0.5;
	    	}
	    	// during actions
			if (front_row_x == 0) linear = 0.5;
			if (front_row_x > 0 and front_row_x < 0.2) linear = 0.2;
//TODO Transitions endlich mal machen!!! Eingangsvariablen berechnen
	    	// transitions
			printf(" left_row_y : %f | right_row_y: %f \n",left_row_y, right_row_y);
	    	if (left_row_y>row_width/3 && right_row_y<-row_width/3 ) {
	    		angular = (left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if (left_row_y == 0 and right_row_y == 0  and front_row_x == 0) {
	    		next_state = Leaving_Row;
	    		}
	    	else if((left_row_y + right_row_y > 0.1) and(left_row_y + right_row_y <= 0.15)  ) {
	    		linear = 0.4;
	    		angular = 0.4;//(left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if((left_row_y + right_row_y < -0.1) and (left_row_y + right_row_y >= -0.15) ) {
	    		linear = 0.4;
	    		angular = -0.4;//(left_row_y + right_row_y)/2*1.5;
	    		}

	    	else if((left_row_y + right_row_y > 0.15) and(left_row_y + right_row_y <= 0.4)  ) {
	    		linear = 0.2;
	    		angular = 0.4;//(left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if((left_row_y + right_row_y < -0.15) and(left_row_y + right_row_y >= -0.4)  ) {
	    		linear = 0.2;
	    		angular = -0.4;//(left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if((left_row_y + right_row_y > 0.15) and(left_row_y + right_row_y <= 0.4) and (front_row_x > 1)  ) {
	    		linear = 0.2;
	    		angular = 0.6;//(left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if((left_row_y + right_row_y < -0.15) and(left_row_y + right_row_y >= -0.4) and( front_row_x > 1)  ) {
	    		linear = 0.2;
	    		angular = -0.6;//(left_row_y + right_row_y)/2*1.5;
	    		}

	    	//printState();
			break;

		case Leaving_Row:
	    	// entry action
	    	if(state != last_state) {
	    		Leaving_Row_timer = 0;
	    		last_state = state;
	    	}
	    	// during actions
	    	angular = 0;
	    	linear = 0.5;
	    	Leaving_Row_timer++;
	    	//printf("Lauf: %i | Time: %f | direct: %i \n", Leaving_Row_timer,Leaving_Row_timer/(double)tick_rate, direct );
	    	// transitions
	    	if ((Leaving_Row_timer/(double)tick_rate > leave_time) && (direct == 1)) {
				next_state = Turning_LO;
	    		}
			else if (Leaving_Row_timer/(double)tick_rate > leave_time and direct == -1) {
				next_state = Turning_RO;
				}
			else if (Leaving_Row_timer/(double)tick_rate > leave_time and direct == 0) {
				next_state = U_Turn;
				}
			break;

		case Turning_LO:
			//during action
			linear = 0;
			angular = 0.3;
			printf("alpha: %f \n", alpha);
			//transitions
			/*if(stop_turn == true)*/
			/*if(left_row_y >= prob_trashhold &&
									right_row_y >= -prob_trashhold &&
									front_row_y > prob_trashhold)*/
			if (alpha >= 90)
			{
				next_state = Outside_Row;
			}

			break;
		case Turning_RO:
			linear = 0;
			angular = -0.3;
			printf("alpha: %f \n", alpha);

			//transitions
			/*if(stop_turn == true)*/
			/*if(left_row_y >= prob_trashhold &&
									right_row_y >= -prob_trashhold &&
									front_row_y > prob_trashhold)*/
			if (alpha >= 90)
			{
				next_state = Outside_Row;
			}


			break;
		case Outside_Row:
			// entry action
			if(state != last_state) {
				last_state = state;
				Outside_Row_timer = 0;
				Row_Counter = 0;
				}
			// during actions
			angular = 0;
			linear = 0.3;

			if ((Maxi_n == Maxi_n_erst) and (Outside_Row_timer==0)){ // TODO if bedingung aendern
				// wenn reihe passiert
				Row_Counter++;
				//printf("reihe: %i | Maxi_n %i | Maxi_n_erst %i \n ", Row_Counter, Maxi_n, Maxi_n_erst);
				//printf("Reihenanzahl: %i | Richtung: %i \n", rows, direct);
				Outside_Row_timer++;
			}
			if (Maxi_n != Maxi_n_erst) Outside_Row_timer = 0;

			// transitions
			if (Row_Counter == rows+1 && direct == 1 ) {
				next_state = Turning_LI;
			} else if (Row_Counter == rows+1 && direct == -1 ) {
				next_state = Turning_RI;
			}
			break;

		case Turning_LI:
			linear = 0;
			angular = 0.3;
			//transitions
			//printf(" left: %f | right: %f | front %f \n", left_row_y, right_row_y, front_row_y);
			if(left_row_prob >= prob_trashhold &&
					right_row_prob >= prob_trashhold &&
					front_row_prob <= prob_trashhold)

			/*if(left_row_y >= prob_trashhold &&
				right_row_y >= -prob_trashhold &&
				front_row_y == 0)*/
			{

				next_state = Inside_Row;
				command_count++;
				printf(" direct: %i | rows: %i \n",direct, rows);
			}
			break;

		case Turning_RI:
			linear = 0;
			angular = -0.3;
			//transitions
			//printf(" leftp: %f | rightp: %f | frontp: %f \n", left_row_prob, right_row_prob, front_row_prob);
			if(left_row_prob > prob_trashhold &&
					right_row_prob > prob_trashhold &&
					front_row_prob < prob_trashhold){

				next_state = Inside_Row;
				command_count++;
				printf(" direct: %i | rows: %i \n",direct, rows);
			}
			break;

		case U_Turn:
			// entry action
			if(state != last_state) {
				// do something

				last_state = state;
			}
			// during actions
			linear = 0;
			// transitions
			if (left_row_y == 0 or right_row_y == 0 ) {
				//compute angular
				angular = 0.4;
				}
			else if (left_row_y > 0 && right_row_y == 0 ) {
				angular = 0.2;
				}
			else if (left_row_y == 0 && right_row_y > 0 ) {
				angular = 0.2;
				}
			else if (left_row_y > 0 && right_row_y > 0 ) {
				next_state = Inside_Row;
				}
			break;


		default:
			// fehlermeldung
			break;
	 	 }
	 state = next_state;
	}




void Statediagramm::printState() {
	printf("State: %d | last_state: %d | next_state: %d \n", state, last_state, next_state);
}

}

/* namespace floribot_task2 */
