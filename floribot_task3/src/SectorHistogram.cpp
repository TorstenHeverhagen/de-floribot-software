/*
 * SectorHistogramX.cpp
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#include "SectorHistogram.h"
#include <math.h>
#include <ros/ros.h>

namespace floribot_task3 {

SectorHistogram::SectorHistogram(Point p1, Point p2, double sector_height) {
	this->p1.x = p1.x;
	this->p1.y = p1.y;
	this->p2.x = p2.x;
	this->p2.y = p2.y;
	this->sector_height = sector_height;
	n_sectors = (p2.x - p1.x)/sector_height + 1;
	hist = new Sector::P_Sector[n_sectors];
	width = p1.y - p2.y;
	sum = 0;
	max = 0;

	if (p1.y >= 0 && p2.y >= 0) {
		phi_1 = atan2(p1.y, p1.x);
		phi_2 = atan2(p2.y, p2.x);
	} else if (p1.y >= 0 && p2.y < 0) {
		phi_1 = atan2(p1.y, p1.x);
		phi_2 = atan2(p2.y, p1.x);
	} else {
		phi_1 = atan2(p1.y, p2.x);
		phi_2 = atan2(p2.y, p1.x);
	}

	for(int i = 0; i < n_sectors; i++) {
		hist[i] = new Sector(p1.x + i*sector_height + sector_height/2, p1.y - width/2, width, sector_height);
	}

	ROS_INFO("x1=%f, y1=%f, x2=%f, y2=%f, phi1=%f, phi2=%f", p1.x, p1.y, p2.x, p2.y, phi_1, phi_2);
}

SectorHistogram::~SectorHistogram() {
	for(int i = 0; i < n_sectors; i++) {
		delete hist[i];
	}
	delete hist;
}

bool SectorHistogram::add(Point p, double phi) {
	if (phi >= phi_2 && phi <= phi_1) {
		max++;
		int i = 0;
		while (i < n_sectors) {
			if (hist[i]->add(p.x, p.y, phi)) {
				sum++;
				return true;
			}
			i++;
		}
	}
	return false;
}

int SectorHistogram::getMax() const {
	return max;
}

const Point& SectorHistogram::getP2() const {
	return p2;
}

int SectorHistogram::getSum() const {
	return sum;
}

const Point& SectorHistogram::getP1() const {
	return p1;
}

double SectorHistogram::getWidth() const {
	return width;
}

double SectorHistogram::getYMiddle() const {
	return (p2.y + p1.y)/2;
}

double SectorHistogram::getXMean() {
	double weighted_sum = 0;
	int sum = 0;
	for(int i = 0; i < n_sectors; i++) {
		weighted_sum += hist[i]->getN() * hist[i]->get_middle().x;
		sum += hist[i]->getN();
	}
	double mean = 0;
	if(sum > 0) {
		mean = weighted_sum/sum;
	}
	return mean;
}

double SectorHistogram::getXProb(double x) {
	if (p1.x <= x && p2.x >= x) {
		int i = (x - p1.x)/sector_height;

		return hist[i]->get_prob();
	}
	return 0;
}

void SectorHistogram::clear() {
	for(int i = 0; i < n_sectors; i++) {
			hist[i]->clear();
	}
	sum = 0;
	max = 0;
}

void SectorHistogram::print() {
	for(int i = 0; i < n_sectors; i++) {
		ROS_DEBUG("S%d: n(%d), max(%d), p(%f,%f)", i, hist[i]->getN(), hist[i]->getMax(), hist[i]->get_middle().x, hist[i]->get_middle().y);
	}
}

} /* namespace floribot_task3 */
