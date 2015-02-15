/*
 * RobotDrivePIDOutput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#include "RobotDrivePIDOutput.h"

RobotDrivePIDOutput::RobotDrivePIDOutput(RobotDrive* robotDrive, bool strafe)
: robotDrive(robotDrive)
, mStrafe(strafe)
{
	// TODO Auto-generated constructor stub

}


void RobotDrivePIDOutput::PIDWrite(float output)
{
	if (mStrafe)
		robotDrive->MecanumDrive_Cartesian( output, 0.0, 0.0);
	else
		robotDrive->MecanumDrive_Cartesian(0.0, output * -1, 0.0);
	SmartDashboard::PutNumber("PID Output", output);
}

