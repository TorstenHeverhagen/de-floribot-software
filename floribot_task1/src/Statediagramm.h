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


namespace floribot_task1 {

class Statediagramm {
	typedef enum {
		Init = 0,
		Inside_Row = 10,
		Leaving_Row = 20
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

	void setProbTrashhold(double meanTrashhold) {
		prob_trashhold = meanTrashhold;
	}

	void setRowX(double rowX) {
		row_x = rowX;
	}

	void setRowXProb(double rowXProb) {
		row_x_prob = rowXProb;
	}

private:
	double left_row_y, right_row_y, row_width;
	double left_row_y_prob, right_row_y_prob, prob_trashhold;
	double row_x, row_x_prob;
	Task2_States state, next_state, last_state;
	float angular, linear;
	int Leaving_Row_timer;
	int tick_rate;


};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
