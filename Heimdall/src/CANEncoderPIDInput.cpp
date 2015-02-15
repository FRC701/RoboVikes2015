/*
 * CANEncoderPIDInput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */
#include "CANEncoderPIDInput.h"

CANTalonEncoderPIDSource::CANTalonEncoderPIDSource(CANTalon* talon, bool isInverted)
: talon(talon), compensation(0.0), mIsInverted(isInverted)
{

}

double CANTalonEncoderPIDSource::PIDGet()
{
	if(mIsInverted)
		return -1 * (talon->GetEncPosition() - compensation);
	else
		return (talon->GetEncPosition() - compensation);
}

void CANTalonEncoderPIDSource::setCompensation(double compensationInput)
{
	compensation = compensationInput;
}
