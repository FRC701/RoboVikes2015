/*
 * Integrator.h
 *
 *  Created on: Feb 1, 2015
 *      Author: vandenrobotics
 */

#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

class Integrator {
public:
	Integrator();
	void push(double val);
	void reset();
	double get();
private:
	double sum;
	double previous;
};

#endif /* INTEGRATOR_H_ */
