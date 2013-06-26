/*
 * Sector.h
 *
 *  Created on: Jun 24, 2013
 *      Author: thever
 */

#ifndef SECTOR_H_
#define SECTOR_H_

#include <geometry_msgs/Point.h>
namespace floribot_task3 {
using namespace geometry_msgs;

class Sector {
public:
	typedef Sector* P_Sector;
	Sector(double x, double y, double width, double height);
	virtual ~Sector();

	/*
	 * increases n if x,y belongs to this sector
	 * increases max if phi is between phi_1 and phi_2
	 */
	bool add(double x, double y, double phi);

	/*
	 * returns n/max if max>0
	 * returna 0 if max==0
	 */
	double get_prob();
	Point get_middle();
	int getMax() const;
	int getN() const;
	void clear();

private:
	Point middle;
	double width, height, phi_1, phi_2;
	int n, max;
};

} /* namespace floribot_task3 */
#endif /* SECTOR_H_ */
