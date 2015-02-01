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

double MovingAverage::returnAverage() const
{
	double average = sum / maxSize;
	return average;
}

void MovingAverage::push(double value)
{
		values.push_front(value);
		if(values.size() > maxSize)
			values.pop_back();
		sumOfValues();
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
	sum = 0.0;
	for(size_t i = 0; i <= maxSize; i++)
		sum += values[i];
}

double MovingAverage::returnSize()
{
	return values.size();
}
