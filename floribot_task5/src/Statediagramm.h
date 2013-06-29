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

namespace floribot_task5 {

class Statediagramm {
	typedef enum {
		Init = 0,
		Follow = 10,
		Wait_For_Digging = 20,
		Drive_To_Hole = 30,
		Sowing = 40
	} Task5_States;
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

	void setLeaveTime(float leaveTime) {
		leave_time = leaveTime;
	}

	void setTickRate(int tickRate) {
		tick_rate = tickRate;
	}

	void setX(double x) {
		this->x = x;
	}

	void setDistanceToHelios(double distanceToHelios);
	void setP(double p);
	void setThresholdX(double thresholdX);
	void setThresholdWaitForDigging(double thresholdWaitForDigging);
	Task5_States getState() const;

private:
	Task5_States state, next_state, last_state;
	float angular, linear;

	int tick_rate, sowing_timer;

	double x, distance_to_helios, K_P, threshold_x, threshold_Wait_For_Digging;
	float leave_time;

	void p_controller();
};

} /* namespace floribot_task2 */
#endif /* STATEDIAGRAMM_H_ */
