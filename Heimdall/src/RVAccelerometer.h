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

namespace robovikes {

class Accelerometer {
public:
	Accelerometer(size_t compensationSize = 1000, size_t samplerSize = 5);

	double getAcceleration() const;
	double getVelocity(/*double a*/) const;
	double getPosition() const;
	double getCompensation() const;

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
	double speed;
	double distance;
};

} // end namespace robovikes

#endif /* ACCELEROMETER_H_ */
