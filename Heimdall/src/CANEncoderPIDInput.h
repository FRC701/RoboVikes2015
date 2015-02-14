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
	virtual double PIDGet() override;
private:
	CANTalon* talon;
};


#endif /* SRC_CANENCODERPIDINPUT_H_ */
