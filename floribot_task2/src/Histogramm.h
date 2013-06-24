/*
 * Histogramm.h
 *
 *  Created on: 19.06.2013
 *      Author: jps
 */

#ifndef HISTOGRAMM_H_
#define HISTOGRAMM_H_

namespace floribot_task2 {

class Histogramm {
public:
	Histogramm(double width, double min, double max);
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
		double min, max, width;
		int *histogramm;
};

} /* namespace floribot_task2 */
#endif /* HISTOGRAMM_H_ */
