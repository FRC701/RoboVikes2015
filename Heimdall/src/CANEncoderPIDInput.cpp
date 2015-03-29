/*
 * CANEncoderPIDInput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */
#include "CANEncoderPIDInput.h"
#include "SmartDashboard/SmartDashboard.h"

CANTalonEncoderPIDSource::CANTalonEncoderPIDSource(CANTalon* talon, bool isInverted)
: talon(talon), compensation(0.0), mIsInverted(isInverted)
{

}

double CANTalonEncoderPIDSource::PIDGet()
{
	double returnValue = 0;

	if(mIsInverted)
		returnValue = -1 * (talon->GetEncPosition() - compensation); // e.g. -1 * (7 - 5) = -2
	else
		returnValue = (talon->GetEncPosition() - compensation); // e.g. 3 - 5 = -2

	SmartDashboard::PutNumber("PIDGet return", returnValue);
	return returnValue;
}

void CANTalonEncoderPIDSource::setCompensation(double compensationInput)
{
	compensation = compensationInput;
}
