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
#include "stdio.h"

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
		Finish = 90
	} Task2_States;
public:
	Statediagramm();
	virtual ~Statediagramm();
	void switch_State();
	void printState();

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

	int getCommandCount() const {
		return command_count;
	}

	void setDirect(int direct) {
		this->direct = direct;
	}

	void setRows(int rows) {
		this->rows = rows;
	}

	void setMiddRowX(double middRowX) {
		midd_row_x = middRowX;
	}

	void setMaxiN(int maxiN) {
		Maxi_n = maxiN;
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

	void setFrontRowx(double frontRowX) {
		front_row_x = frontRowX;
	}

	void setAlpha(double alpha) {
		this->alpha = alpha;
	}

	void setLeaveTime(float leaveTime) {
		leave_time = leaveTime;
	}

	void setStopAngle(double stopAngle) {
		stop_angle = stopAngle;
	}

	void setProbThreshold(double probThreshold) {
		prob_threshold = probThreshold;
	}

	void setMaxiNErst(int maxiNErst) {
		Maxi_n_erst = maxiNErst;
	}

private:
	double left_row_y, right_row_y, front_row_x, row_width, midd_row_x,
			left_row_prob, right_row_prob, front_row_prob;
	Task2_States state, next_state, last_state;
	float angular, linear;
	int Leaving_Row_timer, Outside_Row_timer; // im constr. nullen, im Zustand inkr., in entry nullen
	int direct, rows, command_count; // Ein- und Ausgangsvariablen für das Codepattern
	int Row_Counter, Maxi_n, Maxi_n_erst;
	int tick_rate;

	double row_x, row_x_prob, prob_threshold,stop_angle;
	float leave_time;
	double alpha;
};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
