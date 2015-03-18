// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "autoStrafeToToteRight.h"

autoStrafeToToteRight::autoStrafeToToteRight(double timeForStable)
:timeForStable(timeForStable), timer(0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

}

// Called just before this Command runs the first time
void autoStrafeToToteRight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void autoStrafeToToteRight::Execute() {

	SmartDashboard::PutNumber("Auto Strafing", Robot::chassis->rightRear->GetEncPosition());

	if(!Robot::chassis->leftLightSensor->Get() && !Robot::chassis->rightLightSensor->Get())
	{
		Robot::chassis->robotDrive->MecanumDrive_Cartesian(1.0, 0.3, 0);
		Robot::chassis->pidStrafeController->SetSetpoint(Robot::chassis->rightRear->GetEncPosition());
	}
	else
	{
		Robot::chassis->pidStrafeController->Enable();
		timer->Start();
	}

/*
	bool strafe = true;
	if(Robot::chassis->leftLightSensor->Get() && Robot::chassis->rightLightSensor->Get())
	{
		strafe = false;
		Robot::chassis->pidStrafeWallController->SetSetpoint(Robot::chassis->rightRear->GetEncPosition());
		Robot::chassis->pidStrafeController->Enable();
	}
	if(strafe)
			Robot::chassis->robotDrive->MecanumDrive_Cartesian(1.0, 0.3, 0.0);
	SmartDashboard::PutNumber("SetPoint", Robot::chassis->pidStrafeController->GetSetpoint());
*/

	/*
	if(Robot::chassis->leftLightSensor->Get() && Robot::chassis->rightLightSensor->Get())
	{
		Robot::chassis->pidStrafeController->SetSetpoint(Robot::chassis->rightRear->GetEncPosition());
	}
	else
	 */

}

// Make this return true when this Command no longer needs to run execute()
bool autoStrafeToToteRight::IsFinished() {
	return timer->HasPeriodPassed(timeForStable);
}

// Called once after isFinished returns true
void autoStrafeToToteRight::End() {
	//Robot::chassis->pidStrafeWallController->Disable();
	timer->Stop();
	timer->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoStrafeToToteRight::Interrupted() {
	//Robot::chassis->pidStrafeWallController->Disable();
	timer->Stop();
	timer->Reset();
}
