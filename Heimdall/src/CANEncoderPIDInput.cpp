/*
 * CANEncoderPIDInput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */
#include "CANEncoderPIDInput.h"

CANTalonEncoderPIDSource::CANTalonEncoderPIDSource(CANTalon* talon)
: talon(talon), compensation(0.0)
{

}

double CANTalonEncoderPIDSource::PIDGet()
{
	return -1.0 * (talon->GetEncPosition() - compensation);
}

void CANTalonEncoderPIDSource::setCompensation(double compensationInput)
{
	compensation = compensationInput;
}
