/*
]\[ * TwoMotorPIDOutput.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#ifndef SRC_TWOMOTORPIDOUTPUT_H_
#define SRC_TWOMOTORPIDOUTPUT_H_

#include "PIDOutput.h"
#include "SpeedController.h"

class TwoMotorPIDOutput: public PIDOutput {
public:
	TwoMotorPIDOutput(SpeedController* motor1, SpeedController* motor2);
	virtual void PIDWrite(float output) override;
private:
	SpeedController* motor1;
	SpeedController* motor2;
};

#endif /* SRC_TWOMOTORPIDOUTPUT_H_ */
