/*
 * SHMap.cpp
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#include "SHMap.h"
#include <ros/ros.h>

namespace floribot_task3 {

SH_Map::SH_Map(Point p1, Point p2, double x_hist_width, double y_hist_width) {
	this->p1.x = p1.x;
	this->p1.y = p1.y;
	this->p2.x = p2.x;
	this->p2.y = p2.y;
	this->x_hist_width = x_hist_width;
	this->y_hist_width = y_hist_width;

	n_hists = (p1.y - p2.y)/y_hist_width + 1;

	y_hists = new SectorHistogram::P_SectorHistogram[n_hists];
	for(int i = 0; i < n_hists; i++) {
		Point p_left, p_right;
		p_left.x = p1.x;
		p_right.x = p2.x;
		p_left.y = p1.y - i*y_hist_width;
		p_right.y = p_left.y - y_hist_width;
		y_hists[i] = new SectorHistogram(p_left, p_right, x_hist_width);
	}
	ROS_INFO("SHMap: x1=%f, y1=%f, x2=%f, y2=%f, n=%d", p1.x, p1.y, p2.x, p2.y, n_hists);
}

SH_Map::~SH_Map() {
	for(int i = 0; i < n_hists; i++) {
		delete y_hists[i];
	}
	delete y_hists;
}

void SH_Map::add(Point p, double phi) {
	int i = 0;
	while (i < n_hists && !y_hists[i]->add(p, phi)) {
		i++;
	}
}

double SH_Map::getYMean() {
	double weighted_sum = 0;
	int sum = 0;
	for(int i = 0; i < n_hists; i++) {
		int i_sum = y_hists[i]->getSum();
		weighted_sum += i_sum * y_hists[i]->getYMiddle();
		sum += i_sum;
	}
	float mean = 0;
	if(sum > 0) {
		mean = weighted_sum/sum;
	}
	return mean;
}

double SH_Map::getYProb(double y) {
	double prob = 0;
	if (y <= p1.y && y >= p2.y) {
		int i_SH = getSHNumber(y);
		int max = y_hists[i_SH]->getMax();
		if (y != 0 && max > 0) {
			prob = y_hists[i_SH]->getSum()/(double)max;
		}
	}
	return prob;
}

SectorHistogram::P_SectorHistogram SH_Map::getSH(double y) {
	SectorHistogram::P_SectorHistogram sh = 0;
	if (y <= p1.y && y >= p2.y) {
		sh = y_hists[getSHNumber(y)];
	}
	return sh;
}

int SH_Map::getSHNumber(double y) {
	return (y - p2.y)/y_hist_width;
}

void SH_Map::clear() {
	for(int i = 0; i < n_hists; i++) {
		y_hists[i]->clear();
	}
}

} /* namespace floribot_task3 */
