/*
 * MovingAverage.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: vandenrobotics
 */

#include "MovingAverage.h"

MovingAverage::MovingAverage(size_t size)
{
	maxSize = size;
	sum = 0.0;
}

double MovingAverage::returnAverage() //const
{
	sumOfValues();
	double average = sum / maxSize;
	return average;
}

void MovingAverage::push(double value)
{
	values.push_front(value);
}

double MovingAverage::returnSum()
{
	return sum;
}
double MovingAverage::returnIndex(int index)
{
	return values[index];
}

void MovingAverage::sumOfValues()
{
	sum = values[0];
}
