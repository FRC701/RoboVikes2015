/*
 * Accelerometer.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: duane
 */

#include "Accelerometer.h"

static const size_t kCompenstionSize = 1000;
static const size_t kSamplerSize = 5;

Accelerometer::Accelerometer()
	: compenstation(kCompenstionSize)
	, sampler(kSamplerSize)
	, acceleration(0.0)
{
}

void Accelerometer::stopFeedingCompensator()
{

}

double Accelerometer::getAcceleration() const
{
	return acceleration;
}

double Accelerometer::getVelocity() const
{
	return 	velocity.get();
}

double Accelerometer::getPositiion() const
{
	return 0.0;
}

void Accelerometer::reset()
{

}

void Accelerometer::push(double value)
{
	compenstation.push(value);
	sampler.push(value);
	acceleration = sampler.returnAverage() - compenstation.returnAverage();
}

