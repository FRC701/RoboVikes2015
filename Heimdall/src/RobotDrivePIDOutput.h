/*
 * RobotDrivePIDOutput.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#ifndef SRC_ROBOTDRIVEPIDOUTPUT_H_
#define SRC_ROBOTDRIVEPIDOUTPUT_H_

#include "PIDOutput.h"
#include "RobotDrive.h"
#include "SmartDashBoard/SmartDashboard.h"

class RobotDrivePIDOutput: public PIDOutput {
public:
	RobotDrivePIDOutput(RobotDrive* robotDrive);
	virtual void PIDWrite(float output) override;
private:
	RobotDrive* robotDrive;
};

#endif /* SRC_ROBOTDRIVEPIDOUTPUT_H_ */
