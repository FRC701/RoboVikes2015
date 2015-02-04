/*
 * Accelerometer.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: duane
 */

#include "Accelerometer.h"

static const size_t kCompensationSize = 1000;
static const size_t kSamplerSize = 5;

Accelerometer::Accelerometer(size_t compensationSize, size_t samplerSize)
	: compensation(compensationSize)
	, sampler(samplerSize)
	, acceleration(0.0)
	, feedCompensator(true)
	, compensate(0.0)
{
}

void Accelerometer::stopFeedingCompensator()
{
	feedCompensator = false;
}

double Accelerometer::getAcceleration() const
{
	return acceleration;
}

double Accelerometer::getVelocity() const
{
	return velocity.get();
}

double Accelerometer::getPositiion() const
{
	return position.get();
}

void Accelerometer::reset()
{
	acceleration = 0.0;
	sampler.reset();
	velocity.reset();
	position.reset();
}

void Accelerometer::push(double value)
{
	if (feedCompensator)
	{
		compensation.push(value);
		compensate = compensation.returnAverage();
	}
	sampler.push(value);
	acceleration = sampler.returnAverage() - compensate;
	velocity.push(acceleration);
	position.push(velocity.get());
}


