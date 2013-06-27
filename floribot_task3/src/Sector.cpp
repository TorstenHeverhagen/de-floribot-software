/*
 * Sector.cpp
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#include "Sector.h"
#include <math.h>
#include <ros/ros.h>

namespace floribot_task3 {

Sector::Sector(double x, double y, double width, double height) {
	middle.x = x;
	middle.y = y;
	middle.z = 0;
	this->width = width;
	this->height = height;
	n = 0;
	max = 0;
	if (y >= 0) {
		phi_1 = atan2(middle.y + width/2, middle.x - height/2);
		phi_2 = atan2(middle.y - width/2, middle.x - height/2);
	} else {
		phi_1 = atan2(middle.y + width/2, middle.x + height/2);
		phi_2 = atan2(middle.y - width/2, middle.x - height/2);
	}
	ROS_INFO("new Sector %f %f %f %f)", x, y, phi_1, phi_2);
}

Sector::~Sector() {
}

bool Sector::add(double x, double y, double phi) {
	if (phi >= phi_2 && phi < phi_1) {
		max++;
		if (fabs(x - middle.x) <= height/2 && fabs(y - middle.y) <= width/2) {
			n++;
			return true;
		}
	}
	return false;
}

double Sector::get_prob() {
	if (max > 0) return n/(double)max;
	else return 0;
}

int Sector::getMax() const {
	return max;
}

int Sector::getN() const {
	return n;
}

Point Sector::get_middle() {
	return middle;
}

void Sector::clear() {
	max = 0;
	n = 0;
}

} /* namespace floribot_task3 */
