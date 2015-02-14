/*
 * CANEncoderPIDInput.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#ifndef SRC_CANENCODERPIDINPUT_H_
#define SRC_CANENCODERPIDINPUT_H_

#include "PIDSource.h"
#include "CANTalon.h"

class CANTalonEncoderPIDSource : public PIDSource
{
public:
	CANTalonEncoderPIDSource(CANTalon* talon);
	CANTalonEncoderPIDSource(CANTalon* talon, double compensation);
	virtual double PIDGet() override;
	void setCompensation(double compensationInput);
private:
	CANTalon* talon;
	double compensation;
};


#endif /* SRC_CANENCODERPIDINPUT_H_ */
