/*
 * Statediagramm.h
 *
 *  Created on: 22.06.2013
 *      Author: jps
 */

#ifndef STATEDIAGRAMM_H_
#define STATEDIAGRAMM_H_

#include <string.h>
#include <stdio.h>
//#include "rtwtypes.h"
#include <geometry_msgs/Twist.h>


namespace floribot_task1 {

class Statediagramm {
	typedef enum {
		Init = 0,
		Inside_Row = 10,
		Leaving_Row = 20,
		Turn_Along_Row = 30,
		Move_To_Next_Row = 40,
		Turn_Into_Row = 50

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

	void setLeftRowYProb(double leftRowYMean) {
		left_row_y_prob = leftRowYMean;
	}

	void setRightRowYProb(double rightRowYMean) {
		right_row_y_prob = rightRowYMean;
	}

	void setProbTrashhold(double probTrashhold) {
		prob_trashhold = probTrashhold;
	}

	void setRowX(double rowX) {
		row_x = rowX;
	}

	void setRowXProb(double rowXProb) {
		row_x_prob = rowXProb;
	}

	Task2_States getLastState() const {
		return last_state;
	}

	void setLastState(Task2_States lastState) {
		last_state = lastState;
	}

	Task2_States getNextState() const {
		return next_state;
	}

	void setNextState(Task2_States nextState) {
		next_state = nextState;
	}

	void printState();

	void setRobotWidth(double robotWidth) {
		robot_width = robotWidth;
	}

	void setMaxSpeedAngular(double maxSpeedAngular) {
		max_speed_angular = maxSpeedAngular;
	}

	void setMaxSpeedLinear(double maxSpeedLinear) {
		max_speed_linear = maxSpeedLinear;
	}

	void setRowXMin(double rowXMin) {
		row_x_min = rowXMin;
	}

	void setLeavingTime(double leavingTime) {
		leaving_time = leavingTime;
	}

	void setAlphaMean(double alphaMean) {
		alpha_mean = alphaMean;
	}

	void setAlphaTrashhold(double alphaTrashhold) {
		alpha_trashhold = alphaTrashhold;
	}

	void setXMaxTurn(int maxTurn) {
		x_max_turn = maxTurn;
	}

	void setXMaxTurnErst(int maxTurnErst) {
		x_max_turn_erst = maxTurnErst;
	}

	void setDirection(int direction) {
		this->direction = direction;
	}

private:
	float angular, linear;
	int Leaving_Row_timer, Turn_To_Next_Row_timer, Row_Counter;
	int tick_rate;
	double row_width, robot_width;
	double max_speed_angular, max_speed_linear;
	double left_row_y, right_row_y;
	double left_row_y_prob, right_row_y_prob, prob_trashhold;
	double row_x, row_x_prob, row_x_min;
	double leaving_time;
	double alpha_mean, alpha_trashhold;
	int x_max_turn, x_max_turn_erst;
	Task2_States state, next_state, last_state;

	bool direction;

};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
