/*
 * MovingAverage.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: vandenrobotics
 */

#include "MovingAverage.h"

MovingAverage::MovingAverage(size_t size)
: maxSize(size),
  sum(0.0)
{
}

double MovingAverage::returnAverage() const
{
	if (values.size() == 0)
		return 0;

	double average = sum / values.size();
	return average;
}

void MovingAverage::push(double value)
{
		values.push_front(value);
		sum += value;
		if(values.size() > maxSize)
		{
			sum -= values.back();
			values.pop_back();
		}
}

double MovingAverage::returnSum()
{
	return sum;
}

double MovingAverage::returnIndex(int index)
{
	return values[index];
}

double MovingAverage::returnSize()
{
	return values.size();
}
