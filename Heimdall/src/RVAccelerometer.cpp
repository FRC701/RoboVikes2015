/*
 * Accelerometer.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: duane
 */

#include "RVAccelerometer.h"

static const size_t kCompensationSize = 1000;
static const size_t kSamplerSize = 5;

namespace robovikes {

Accelerometer::Accelerometer(size_t compensationSize, size_t samplerSize)
	: compensation(compensationSize)
	, sampler(samplerSize)
	, acceleration(0.0)
	, feedCompensator(true)
	, compensate(0.0)
	, speed(0.0)
	, distance(0.0)
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

double Accelerometer::getVelocity(/*double a /*This is the variable for average acceleration.*/) const
{
	//This is assuming that the average acceleration is of a time interval of 1 second.
	//double speed;
	//speed = speed + a;
	return speed;
}

double Accelerometer::getPosition(/*double v*/) const
{
	//This is assuming that the the velocity is the current velocity.
	//THis takes all the assumptions in the acceleration method as well.
	//double distance;
	//distance = distance + v;
	return distance;
}

double Accelerometer::getCompensation() const
{
	return compensate;
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

	speed = speed + acceleration;
	distance = distance + speed;

	//velocity.push(acceleration);
	//position.push(velocity.get());
}

} // end namespace robovikes
