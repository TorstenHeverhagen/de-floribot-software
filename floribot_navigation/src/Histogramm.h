/*
 * Histogramm.h
 *
 *  Created on: Jun 13, 2013
 *      Author: thever
 */

#ifndef HISTOGRAMM_H_
#define HISTOGRAMM_H_

namespace floribot_navigation {

class Histogramm {
public:
	Histogramm(float width, float min, float max);
	virtual ~Histogramm();
	void print();
	void put(float value);
	float get_width();
	float get_min(int i);
	float get_max(int i);
	int get_n(int i);
	void set_n(int n, int i);

	float getMax() const {
		return max;
	}

	float getMin() const {
		return min;
	}

	int getNumClasses() const {
		return num_classes;
	}

private:
	int num_classes;
	float min, max, width;
	int *histogramm;

};

} /* namespace floribot_navigation */
#endif /* HISTOGRAMM_H_ */
