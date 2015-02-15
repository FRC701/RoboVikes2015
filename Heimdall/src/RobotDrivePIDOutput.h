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
	static const bool kStrafe = true;
	static const bool kDontStrafe = false;

	RobotDrivePIDOutput(RobotDrive* robotDrive, bool strafe = false, double wallStafeCompensation = 0.0);
	virtual void PIDWrite(float output) override;
private:
	RobotDrive* robotDrive;
	bool mStrafe;
	double mWallStrafeCompensation;
};

#endif /* SRC_ROBOTDRIVEPIDOUTPUT_H_ */
