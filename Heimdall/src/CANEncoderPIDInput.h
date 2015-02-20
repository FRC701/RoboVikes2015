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
	static const bool kInverted = true;
	CANTalonEncoderPIDSource(CANTalon* talon, bool isInverted = false);
	CANTalonEncoderPIDSource(CANTalon* talon, double compensation, bool isInverted = false);
	virtual double PIDGet() override;
	void setCompensation(double compensationInput);
private:
	CANTalon* talon;
	double compensation;
	bool mIsInverted;
};


#endif /* SRC_CANENCODERPIDINPUT_H_ */
