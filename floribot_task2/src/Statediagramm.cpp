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
	next_state = Outside_Row;
	last_state = Init;

	row_width = 0;
	left_row_y = 0;
	right_row_y = 0;
	angular = 0;
	linear = 0;
	Leaving_Row_timer = 0;
	Outside_Row_timer  =0;
	tick_rate= 0;

	Row_Counter = 0;  // Zaehlvariable für Reihen bei Passage außerhalb
	Maxi_n = 0;
	Maxi_n_erst = 0;
	Maxi_n_alt = 0;
	direct = 0;
	rows = 0;
	command_count = 0;
	midd_row_x = 0;

	left_row_prob = 0;
	right_row_prob=0;
	left_row_trashold = 0.2;
	right_row_trashold = left_row_trashold;

}

Statediagramm::~Statediagramm() {

}

void Statediagramm::switch_State() {
	//geometry_msgs::Twist vel;
	float leave_time = 2.0;


	 switch (state) {
		case Init:
			// during actions
			angular = 0;
			linear = 0;
			//transition
			next_state = Inside_Row;
			break;

	    case Inside_Row:
	    	// entry action
	    	if(state != last_state) {
	    		// do something

	    		last_state = state;
	    	}
	    	// during actions
	    	linear = 0.5;

	    	// transitions
	    	if (left_row_y>row_width/3 && right_row_y<-row_width/3 ) {
	    		//compute angular
	    		angular = (left_row_y + right_row_y)/2*1.5;
	    		}
	    	else if (left_row_y == 0 && right_row_y == 0 ) {
	    		next_state = Leaving_Row;
	    		}
	    	next_state = Outside_Row;
	    	/*else if (){

	    		}
	    	else if (){

	    		}*/
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
	    	// transitions
	    	if (Leaving_Row_timer/(double)tick_rate > leave_time and direct == 1) {
				//compute angular
				next_state = Turning_RO;
	    		}
			else if (Leaving_Row_timer/(double)tick_rate > leave_time and direct == -1) {
					//compute angular
					next_state = Turning_LO;
				}
			else if (Leaving_Row_timer/(double)tick_rate > leave_time and direct == 0) {
				//compute angular
				next_state = U_Turn;
			break;

		case Turning_LO:



			break;
		case Turning_RO:



			break;
		case Outside_Row:
			// entry action
			if(state != last_state) {
				// do something
				Outside_Row_timer = 0;
				Row_Counter = 0;
				Maxi_n_erst = 7;//Maxi_n;  // TODO übergabe von maxi_n an *_erst
				last_state = state;

			}
			// during actions
			linear = 0.2;

			if ((Maxi_n == Maxi_n_erst) and (Outside_Row_timer==0)){ // TODO if bedingung aendern
				// wenn reihe passiert
				Row_Counter++;
				printf("reihe: %i | Maxi_n %i | Maxi_n_erst %i \n ", Row_Counter, Maxi_n, Maxi_n_erst);
				printf("Reihenanzahl: %i | Richtung: %i \n", rows, direct);
				Outside_Row_timer++;
			}
			if (Maxi_n != Maxi_n_erst) Outside_Row_timer = 0;

			// transitions
			if (Row_Counter == rows+1 && direct == -1 ) {
				next_state = Turning_LI;
			} else if (Row_Counter == rows+1 && direct == 1 ) {
				next_state = Turning_RI;
			}



			break;

		case Turning_LI:
			linear = 0;
			angular = 0.2;


			break;
		case Turning_RI:
			linear = 0;
			angular = 0.2;

			break;

		case U_Turn:
			// entry action
			if(state != last_state) {
				// do something

				last_state = state;
			}
			// during actions
			linear = 0.5;
			// transitions
			if (left_row_y>row_width/3 && right_row_y<-row_width/3 ) {
				//compute angular
				angular = (left_row_y + right_row_y)/2*1.5;
			} else if (left_row_y == 0 && right_row_y == 0 ) {
				next_state = Leaving_Row;
			}

			break;


		default:
			// fehlermeldung
			break;
	 	 }


	}
state = next_state;


}

void Statediagramm::printState() {
	printf("State: %d \n", state);
}

}

/* namespace floribot_task2 */
