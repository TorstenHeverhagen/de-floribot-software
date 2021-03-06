/*
 * Histogramm.h
 *
 *  Created on: Jun 13, 2013
 *      Author: thever
 */

#ifndef HISTOGRAMM_H_
#define HISTOGRAMM_H_

namespace floribot_task1 {

class Histogramm {
public:
	Histogramm(float min, float max, float width);
	virtual ~Histogramm();
	void print();
	void put(float value);
	float get_width();
	float get_min(int i);
	float get_max(int i);
	int get_n(float value);
	float get_mean(float border1, float border2);
	int get_sum(float border1, float border2);
	int get_class_num(float value);
	int get_class_sice();
	float get_class_middle(int index);
	int get_Maxi_n(float border1, float border2);
	void clear();

	float getMax() const {
		return max;
	}

	float getMin() const {
		return min;
	}

	int getNumClasses() const {
		return num_classes;
	}

	int *histogramm;
private:
	int num_classes;
	float min, max, width;

};

} /* namespace floribot_navigation */
#endif /* HISTOGRAMM_H_ */
