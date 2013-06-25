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
	typedef enum {
		Init = 0,
		Inside_Row = 10,
		Leaving_Row = 20,
		Turning_LO = 30,
		Turning_RO = 40,
		Outside_Row = 50,
		Turning_LI = 60,
		Turning_RI = 70,
		U_Turn = 80,

	} Task2_States;
public:
	Statediagramm();
	virtual ~Statediagramm();
	void switch_State();

	float getAngular() const {
		return angular;
	}

	float getLinear() const {
		return linear;
	}

	void setLeftRowY(double leftRowY) {
		left_row_y = leftRowY;
	}

	void setRightRowY(double rightRowY) {
		right_row_y = rightRowY;
	}

	void setRowWidth(double rowWidth) {
		row_width = rowWidth;
	}

	void setTickRate(int tickRate) {
		tick_rate = tickRate;
	}

	void setFrontRowX(double frontRowX) {
		front_row_x = frontRowX;
	}

	void setLeftRowProb(double leftRowProb) {
		left_row_prob = leftRowProb;
	}

	void setRightRowProb(double rightRowProb) {
		right_row_prob = rightRowProb;
	}

	void setFrontRowProb(double frontRowProb) {
		front_row_prob = frontRowProb;
	}

	void setStopTurn(bool stopTurn){
		stop_turn = stopTurn;
	}

private:
	double left_row_y, right_row_y, row_width, front_row_x;
	Task2_States state, next_state, last_state;
	double left_row_prob, right_row_prob, front_row_prob;
	float angular, linear;
	int Leaving_Row_timer; // im constr. nullen, im Zustand inkr., in entry nullen
	int tick_rate;
	bool stop_turn;


};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
