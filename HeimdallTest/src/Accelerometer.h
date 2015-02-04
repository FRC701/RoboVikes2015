/*
 * Accelerometer.h
 *
 *  Created on: Feb 1, 2015
 *      Author: duane
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "MovingAverage.h"
#include "Integrator.h"

class Accelerometer {
public:
	Accelerometer(size_t compensationSize = 1000, size_t samplerSize = 5);

	double getAcceleration() const;
	double getVelocity() const;
	double getPositiion() const;

	void stopFeedingCompensator();

	void reset();
	void push(double value);
private:
	MovingAverage compensation;
	MovingAverage sampler;
	double acceleration;
	Integrator velocity;
	Integrator position;
	bool feedCompensator;
	double compensate;
};

#endif /* ACCELEROMETER_H_ */
