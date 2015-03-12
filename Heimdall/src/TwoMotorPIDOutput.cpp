/*
 * TwoMotorPIDOutput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#include "TwoMotorPIDOutput.h"

TwoMotorPIDOutput::TwoMotorPIDOutput(SpeedController* motor1, SpeedController* motor2)
: motor1(motor1), motor2(motor2)
{

}

void TwoMotorPIDOutput::PIDWrite(float output)
{
	Set(output);
}

void TwoMotorPIDOutput::Set(float speed)
{
	motor1->Set(speed);
	motor2->Set(speed);
}

TwoMotorPIDOutput::~TwoMotorPIDOutput()
{

}



