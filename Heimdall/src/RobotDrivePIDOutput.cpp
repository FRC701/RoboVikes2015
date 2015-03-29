/*
 * RobotDrivePIDOutput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#include "RobotDrivePIDOutput.h"
#include "SmartDashboard/SmartDashboard.h"

RobotDrivePIDOutput::RobotDrivePIDOutput(RobotDrive* robotDrive, bool strafe, double wallStrafeCompenstation, bool encoderIsInverted)
: robotDrive(robotDrive)
, mStrafe(strafe)
, mWallStrafeCompensation(wallStrafeCompenstation)
, mEncoderIsInverted(encoderIsInverted)
{
	// TODO Auto-generated constructor stub

}


void RobotDrivePIDOutput::PIDWrite(float output)
{
	if (mStrafe)
	{
		if (!mEncoderIsInverted)
		{
			robotDrive->MecanumDrive_Cartesian(output, mWallStrafeCompensation, 0.0);
			SmartDashboard::PutNumber("PIDWrite output", output);
		}
		else
		{
			robotDrive->MecanumDrive_Cartesian(-output, mWallStrafeCompensation, 0.0);
			SmartDashboard::PutNumber("PIDWrite output", -output);
		}
	}
	else // driving forward/backward
	{
		robotDrive->MecanumDrive_Cartesian(0.0, output * -1, 0.0);
	}
	SmartDashboard::PutNumber("PID Output", output);
}

