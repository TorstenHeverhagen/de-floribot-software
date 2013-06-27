/*
 * SectorHistogram.h
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#ifndef SECTORHISTOGRAM_H_
#define SECTORHISTOGRAM_H_
#include <geometry_msgs/Point.h>
#include "Sector.h"
#include <string.h>

namespace floribot_task3 {
using namespace geometry_msgs;
class SectorHistogram {
public:
	typedef SectorHistogram* P_SectorHistogram;
	SectorHistogram(Point p1, Point p2, double sector_height);
	virtual ~SectorHistogram();
	bool add(Point p, double phi);
	int getMax() const;
	const Point& getP2() const;
	int getSum() const;
	double getWidth() const;
	const Point& getP1() const;
	double getYMiddle() const;
	double getXMean();
	double getXProb(double x);
	int getSectorNumber(double x);
	void clear();
	void print();

private:
	Sector::P_Sector *hist;
	Point p1, p2;
	double sector_height, width, phi_1, phi_2;
	int n_sectors, sum, max;
};

} /* namespace floribot_task3 */
#endif /* SECTORHISTOGRAM_H_ */
