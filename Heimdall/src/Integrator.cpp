/*
 * Integrator.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: vandenrobotics
 */

#include "Integrator.h"

Integrator::Integrator()
: sum(0.0),
  previous(0.0)
{
}

void Integrator::push(double val)
{
	sum += (previous + val) / 2;
	previous = val;
}

void Integrator::reset()
{
	sum = 0.0;
}

double Integrator::get() const
{
	return sum;
}



