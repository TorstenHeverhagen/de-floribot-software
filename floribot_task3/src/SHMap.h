/*
 * SHMap.h
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#ifndef SHMAP_H_
#define SHMAP_H_

#include "SectorHistogram.h"

namespace floribot_task3 {

class SH_Map {
public:
	SH_Map(Point p1, Point p2, double x_hist_width, double y_hist_width);
	virtual ~SH_Map();
	void add(Point p, double phi);
	double getYMean();
	double getYProb(double y);
	SectorHistogram::P_SectorHistogram getSH(double y);
	int getSHNumber(double y);
	void clear();

private:
	SectorHistogram::P_SectorHistogram *y_hists;
	int n_hists;
	Point p1, p2;
	double x_hist_width, y_hist_width;
};

} /* namespace floribot_task3 */
#endif /* SHMAP_H_ */
