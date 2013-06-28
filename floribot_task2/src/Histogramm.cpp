/*
 * Histogramm.cpp
 *
 *  Created on: Jun 13, 2013
 *      Author: thever
 */

#include "Histogramm.h"
#include <stdio.h>

namespace floribot_task2 {

Histogramm::Histogramm(float min, float max, float width) {
	this->num_classes = (max-min)/width + 1;
	this->min = min;
	this->max = max;
	this->width = width;
	histogramm = new int[num_classes];
	clear();
	//printf("Histogram %d, %f, %f, %f\n", num_classes, min, max, width);
}

Histogramm::~Histogramm() {
	delete histogramm;
}

void Histogramm::put(float value)
{
	if (value <= max && value >= min) {
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
	return get_min(i) + get_width();
}

float Histogramm::get_width() {
	return width;
}

void Histogramm::print() {
	for (int i = 0; i < num_classes; ++i) {
		printf("%d ", histogramm[i]);
	}
	printf( "\n");
}

int Histogramm::get_class_num(float value) {
	return (value - min)/width;
}

float Histogramm::get_class_middle(int index) {
	return min + index*width + width/2;
}

float Histogramm::get_mean(float border1, float border2) {
	float weighted_sum = 0;
	for(int i = get_class_num(border1); i <= get_class_num(border2); i++) {
		weighted_sum += histogramm[i] * get_class_middle(i);
	}
	int sum = get_sum(border1, border2);
	float mean = 0;
	if(sum > 0) {
		mean = weighted_sum/sum;
	}
	return mean;
}

int Histogramm::get_sum(float border1, float border2) {
	int sum = 0;
	for(int i = get_class_num(border1); i <= get_class_num(border2); i++) {
		sum += histogramm[i];
	}
	return sum;
}

int Histogramm::get_n(float value) {
	return histogramm[get_class_num(value)];
}

int Histogramm::get_Maxi_n(float border1, float border2) {
	int max_n = 0;
	int maximum = 0;
	for (int i = get_class_num(border1); i < get_class_num(border2);i++){
		if (histogramm[i]> maximum) {
			maximum = histogramm[i];
			max_n = i;
		}
	}
	return max_n;
}

void Histogramm::clear() {
	for (int i = 0; i < num_classes; ++i) {
		histogramm[i] = 0;
	}
}

} /* namespace floribot_navigation */
