/*
 * SHMap.cpp
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#include "SHMap.h"

namespace floribot_task3 {

SH_Map::SH_Map(Point p1, Point p2, double x_hist_width, double y_hist_width) {
	this->p1.x = p1.x;
	this->p1.y = p1.y;
	this->p2.x = p2.x;
	this->p2.y = p2.y;
	this->x_hist_width = x_hist_width;
	this->y_hist_width = y_hist_width;

	if (p1.y >= 0 && p2.y >= 0) n_hists = (p1.y - p1.y)/y_hist_width + 1;
	else if (p1.y >= 0 && p2.y < 0) n_hists = (p1.y - p1.y)/y_hist_width + 1;
	else n_hists = (p1.y - p1.y)/y_hist_width + 1;

	y_hists = new SectorHistogram::P_SectorHistogram[n_hists];
	for(int i = 0; i < n_hists; i++) {
		Point p_left, p_right;
		p_left.x = p1.x;
		p_right.x = p2.x;
		p_left.y = p1.y + i*y_hist_width;
		p_right.y = p_left.y - y_hist_width;
		y_hists[i] = new SectorHistogram(p_left, p_right, x_hist_width);
	}
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
	for(int i = 0; i <= n_hists; i++) {
		weighted_sum += y_hists[i]->getSum() * y_hists[i]->getYMiddle();
		sum += y_hists[i]->getSum();
	}
	float mean = 0;
	if(sum > 0) {
		mean = weighted_sum/sum;
	}
	return mean;
}

double SH_Map::getYProb(double y) {
	int i_SH = (y_hists[0]->getP2().y + y)/y_hist_width;
	int max = y_hists[i_SH]->getMax();
	double prob = 0;
	if (y != 0 && max > 0) {
		prob = y_hists[i_SH]->getSum()/max;
	}
	return prob;
}

void SH_Map::clear() {
	for(int i = 0; i < n_hists; i++) {
		y_hists[i]->clear();
	}
}

} /* namespace floribot_task3 */
