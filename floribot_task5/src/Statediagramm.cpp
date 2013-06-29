/*
 * Statediagramm.cpp
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#include "Statediagramm.h"

namespace floribot_task5 {

Statediagramm::Statediagramm() {
	state = Init;
	next_state = Init;
	last_state = Init;

	angular = 0;
	linear = 0;
	tick_rate= 0;

	leave_time = 0.7;
	sowing_timer  = 0;
	x = 0;

}

Statediagramm::~Statediagramm() {

}

void Statediagramm::setDistanceToHelios(double distanceToHelios) {
	distance_to_helios = distanceToHelios;
}

void Statediagramm::setThresholdWaitForDigging(double thresholdWaitForDigging) {
	threshold_Wait_For_Digging = thresholdWaitForDigging;
}

void Statediagramm::setThresholdX(double thresholdX) {
	threshold_x = thresholdX;
}

void Statediagramm::setP(double p) {
	K_P = p;
}

Statediagramm::Task5_States Statediagramm::getState() const {
	return state;
}

void Statediagramm::p_controller() {
	linear = K_P * (distance_to_helios - x);
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

		next_state = Follow;
		break;

	case Follow:
		// entry action
		if(state != last_state) {
			last_state = state;
		}
		// during actions
		p_controller();

		//TODO Transitions endlich mal machen!!! Eingangsvariablen berechnen
		// transitions
		if (fabs(x - distance_to_helios) < threshold_x) {
			next_state = Wait_For_Digging;
		}

		//printState();
		break;

	case Wait_For_Digging:
		// entry action
		if(state != last_state) {
			last_state = state;
		}
		// during actions
		angular = 0;
		linear = 0;
		// transitions
		if ((x - distance_to_helios) > threshold_Wait_For_Digging) {
			next_state = Drive_To_Hole;
		}
		break;

	case Drive_To_Hole:
		// entry action
		if(state != last_state) {
			last_state = state;
		}
		//during action
		p_controller();

		//transition
		if (fabs(x - distance_to_helios) < threshold_x) {
			next_state = Sowing;
		}
		break;

	case Sowing:
		// entry action
		if(state != last_state) {
			sowing_timer = 0;
			last_state = state;
		}
		linear = 0.0;
		angular = 0;
		sowing_timer++;

		if (sowing_timer/(double)tick_rate > leave_time)
		{
			next_state = Follow;
		}
		break;

	default:
		// fehlermeldung
		break;
	}
	state = next_state;
}

}
/* namespace floribot_task2 */
