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
	Accelerometer();

	double getAcceleration() const;
	double getVelocity(); //const;
	double getPositiion(); //const;

	void stopFeedingCompensator();

	void reset();
	void push(double value, double test);
private:
	MovingAverage compenstation;
	MovingAverage sampler;
	double acceleration;
	Integrator velocity;
	Integrator position;
};

#endif /* ACCELEROMETER_H_ */
