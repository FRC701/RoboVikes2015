/*
 * Accelerometer.h
 *
 *  Created on: Feb 1, 2015
 *      Author: duane
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

class Accelerometer {
public:
	Accelerometer();

	double getAcceleration() const;
	double getVelocity() const;
	double getPositiion() const;

	void reset();
	void push(double value);
private:
	MovingAverage compenstation;
	MovingAverage sampler;
	double acceleration;
	Integrator velocity;
	Integrator position;
};

#endif /* ACCELEROMETER_H_ */
