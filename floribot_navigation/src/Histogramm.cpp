/*
 * Histogramm.cpp
 *
 *  Created on: Jun 13, 2013
 *      Author: thever
 */

#include "Histogramm.h"
#include <stdio.h>

namespace floribot_navigation {

Histogramm::Histogramm(float width, float min, float max) {
	this->num_classes = (max-min)/width + 1;
	this->min = min;
	this->max = max;
	this->width = width;
	histogramm = new int[num_classes];
	for (int i = 0; i < num_classes; ++i) {
		histogramm[i] = 0;
	}
}

Histogramm::~Histogramm() {
	delete histogramm;
}

void Histogramm::put(float value)
{
	if (value < max && value > min) {
		//printf("put: %f ", value);
		float width = get_width();
		int index = -min/width + value/width;
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

void Histogramm::set_n(int n, int i) {
	histogramm[i] = n;
}

} /* namespace floribot_navigation */
