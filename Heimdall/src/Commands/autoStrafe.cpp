// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "autoStrafe.h"

#include <cmath>

autoStrafe::autoStrafe()
:	mDistance(0), mTimeoutTimer(), mTimeout(),
	mTimeoutForEncoderChange(), mPreviousEncoderReading(0.0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

autoStrafe::autoStrafe(double setPoint, double timeoutInSeconds)
:	mDistance(setPoint), mTimeoutTimer(), mTimeout(timeoutInSeconds),
	mTimeoutForEncoderChange(), mPreviousEncoderReading(0.0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void autoStrafe::Initialize() {

	float setPoint = Robot::chassis->rightRear->GetEncPosition();
	setPoint += mDistance;
	Robot::chassis->pidStrafeWallController->SetSetpoint(setPoint);
	// SmartDashboard::PutNumber("Strafe actual setPoint", setPoint);
	// SmartDashboard::PutNumber("Get Set Point", Robot::chassis->pidStrafeWallController->GetSetpoint());

	//TimeOut Timer starting
	mTimeoutTimer.Start();
	//Setting Previous Encoder Position to Current
	mPreviousEncoderReading = Robot::chassis->rightRear->GetEncPosition();
}

// Called repeatedly when this Command is scheduled to run
void autoStrafe::Execute() {

	Robot::chassis->pidStrafeWallController->Enable();

	// Check if encoder enough to show progress
	if ((std::abs(Robot::chassis->rightRear->GetEncPosition()) - mPreviousEncoderReading)
			< Robot::prefs->GetInt("autoStrafeRequiredEncoderProgress", 0))
	{
		mTimeoutForEncoderChange.Start();
	}
	else
	{
		mTimeoutForEncoderChange.Stop();
		mTimeoutForEncoderChange.Reset();
	}

	mPreviousEncoderReading = Robot::chassis->rightRear->GetEncPosition();

	// SmartDashboard::PutNumber("Strafe Set Point", Robot::chassis->pidStrafeWallController->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool autoStrafe::IsFinished() {
/*
	if(Robot::chassis->pidStrafeController->OnTarget())
		mTimeForStop.Start();
	else
	{
		mTimeForStop.Stop();
		mTimeForStop.Reset();
	}
	return (mTimeForStop.HasPeriodPassed(0.2));
*/
	return (Robot::chassis->pidStrafeWallController->OnTarget() ||
			// mTimeoutTimer.HasPeriodPassed(Robot::prefs->GetDouble("autoStrafeTimeout", 0.0)) ||
			mTimeoutTimer.HasPeriodPassed(mTimeout)); // ||
			// mTimeoutForEncoderChange.HasPeriodPassed(0.25));
}

// Called once after isFinished returns true
void autoStrafe::End() {
	mTimeoutTimer.Stop();
	mTimeoutTimer.Reset();
	mTimeoutForEncoderChange.Stop();
	mTimeoutForEncoderChange.Reset();
	Robot::chassis->pidStrafeWallController->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoStrafe::Interrupted() {
	mTimeoutTimer.Stop();
	mTimeoutTimer.Reset();
	mTimeoutForEncoderChange.Stop();
	mTimeoutForEncoderChange.Reset();
	Robot::chassis->pidStrafeWallController->Disable();
}
