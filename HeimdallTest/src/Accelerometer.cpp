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

double Accelerometer::getVelocity() //const
{
	velocity.push(acceleration);
	return velocity.get();
}

double Accelerometer::getPositiion() //const
{
	position.push(velocity.get());
	return position.get();
}

void Accelerometer::reset()
{
	acceleration = 0.0;
}

void Accelerometer::push(double value, double test)
{
	compenstation.push(value);
	sampler.push(test);
	acceleration = sampler.returnAverage() - compenstation.returnAverage();
}

