/*
 * Histogramm.cpp
 *
 *  Created on: Jun 13, 2013
 *      Author: thever
 */

#include "Histogramm.h"
#include <stdio.h>

namespace floribot_task3 {

Histogramm::Histogramm(float min, float max, float width) {
	this->num_classes = (max-min)/width + 1;
	this->min = min;
	this->max = max;
	this->width = width;
	histogramm = new int[num_classes];
	clear();
	printf("Histogram %d, %f, %f, %f\n", num_classes, min, max, width);
}

Histogramm::~Histogramm() {
	delete histogramm;
}

void Histogramm::put(float value)
{
	if (value < max && value > min) {
		//printf("put: %f ", value);
		int index = get_class_num(value);
		histogramm[index]++;
		//printf("histogramm[%d]: %d\n", index, histogramm[index]);
	}
}

float Histogramm::get_min(int i) {
	return i*get_width() + min;
}

float Histogramm::get_max(int i) {
	return i*get_width() + min + get_width();
}

float Histogramm::get_width() {
	return width;
}

int Histogramm::get_n(int i) {
	return histogramm[i];
}

void Histogramm::print() {
	for (int i = 0; i < num_classes; ++i) {
		printf("%d ", histogramm[i]);
	}
	printf( "\n");
}

Histogramm::MeanProb_T Histogramm::get_mean_and_prob(float border1, float border2) {
	float weighted_sum = 0;
	float sum = 0;
	for(int i = get_class_num(border1); i <= get_class_num(border2); i++) {
		weighted_sum += get_n(i) * get_class_middle(i);
		sum += get_n(i);
	}
	Histogramm::MeanProb_T result;
	if(sum > 0) {
		result.mean = weighted_sum/sum;
		result.prob = get_n(get_class_num(result.mean)) / sum;
	} else {
		result.mean = 0;
		result.prob = 0;
	}
	return result;
}

int Histogramm::get_class_num(float value) {
	return -min/width + value/width;
}

float Histogramm::get_class_middle(int index) {
	return min + index*width + width/2;
}

void Histogramm::clear() {
	for (int i = 0; i < num_classes; ++i) {
		histogramm[i] = 0;
	}
}

} /* namespace floribot_navigation */
