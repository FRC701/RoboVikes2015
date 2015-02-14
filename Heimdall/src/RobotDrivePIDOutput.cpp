/*
 * RobotDrivePIDOutput.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Vanden
 */

#include "RobotDrivePIDOutput.h"

RobotDrivePIDOutput::RobotDrivePIDOutput(RobotDrive* robotDrive)
: robotDrive(robotDrive)
{
	// TODO Auto-generated constructor stub

}


void RobotDrivePIDOutput::PIDWrite(float output)
{
	robotDrive->MecanumDrive_Cartesian(0.0, output * -1, 0.0);
	SmartDashboard::PutNumber("PID Output", output);
}
