// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "autoDrive.h"

#include <cmath>

autoDrive::autoDrive()
:	mDistance(0), mTimeout(), mTimeoutForEncoderChange(),
	mPreviousEncoderReading(0), mTimeForStop()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}


autoDrive::autoDrive(double setPoint)
:	mDistance(setPoint), mTimeout(), mTimeoutForEncoderChange(),
	mPreviousEncoderReading(0), mTimeForStop()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void autoDrive::Initialize() {
	float setPoint = Robot::chassis->leftRear->GetEncPosition();
	setPoint += mDistance;
	// SmartDashboard::PutNumber("setPoint", setPoint);
	Robot::chassis->pidController->SetSetpoint(setPoint);

	mTimeout.Start();
}

// Called repeatedly when this Command is scheduled to run
void autoDrive::Execute() {
	Robot::chassis->pidController->Enable();

	// Check if encoder enough to show progress
	if ((std::abs(Robot::chassis->leftRear->GetEncPosition())
	     - mPreviousEncoderReading)
		 < Robot::prefs->GetInt("autoDriveRequiredEncoderProgress", 0))
	{
		mTimeoutForEncoderChange.Start();
	}
	else
	{
		mTimeoutForEncoderChange.Stop();
		mTimeoutForEncoderChange.Reset();
	}

	mPreviousEncoderReading = Robot::chassis->leftRear->GetEncPosition();
	// SmartDashboard::PutNumber("Auto Drive Set Point", Robot::chassis->pidController->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool autoDrive::IsFinished() {
	if(Robot::chassis->pidController->OnTarget())
		mTimeForStop.Start();
	else
	{
		mTimeForStop.Stop();
		mTimeForStop.Reset();
	}
	return (mTimeForStop.HasPeriodPassed(0.2) ||
			mTimeout.HasPeriodPassed(Robot::prefs->GetDouble("autoDriveTimeout", 0.0)));// ||
			// mTimeoutForEncoderChange.HasPeriodPassed(0.25));
	//return Robot::chassis->pidController->OnTarget();
}

// Called once after isFinished returns true
void autoDrive::End() {
	mTimeout.Stop();
	mTimeout.Reset();
	mTimeForStop.Stop();
	mTimeForStop.Reset();
	mTimeoutForEncoderChange.Stop();
	mTimeoutForEncoderChange.Reset();
	Robot::chassis->pidController->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoDrive::Interrupted() {
	mTimeout.Stop();
	mTimeout.Reset();
	mTimeForStop.Stop();
	mTimeForStop.Reset();
	mTimeoutForEncoderChange.Stop();
	mTimeoutForEncoderChange.Reset();
	Robot::chassis->pidController->Disable();
}
