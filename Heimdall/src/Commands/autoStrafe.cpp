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
:	mPurpose(Purpose::noneSpecified),
	mDistanceBased(true),
	mTimerBased(true),
	mEncoderSafety(true),
	mDriveDistance(0),
	mCommandTimeoutTimer(),
	mCommandTimeoutAmount(0.0),
	mTimeoutForEncoderChangeTimer(),
	mPreviousEncoderReading(0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

autoStrafe::autoStrafe(Purpose purpose, bool distanceBased,
		bool timerBased, bool encoderSafety)
:	mPurpose(purpose),
	mDistanceBased(distanceBased),
	mTimerBased(timerBased),
	mEncoderSafety(encoderSafety),
	mDriveDistance(0),
	mCommandTimeoutTimer(),
	mCommandTimeoutAmount(0.0),
	mTimeoutForEncoderChangeTimer(),
	mPreviousEncoderReading(0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void autoStrafe::Initialize() {


	switch (mPurpose)
	{
	case rightToAvoidContainer:
		mDriveDistance = 500;
		mCommandTimeoutAmount = 0.5;
		break;
	case leftToAvoidYellowTote:
		mDriveDistance = -500;
		mCommandTimeoutAmount = 0.5;
		break;
	case leftFromLandfillZone:
		mDriveDistance = -680;
		mCommandTimeoutAmount = 2.0;
		break;
	default:
		mDriveDistance = 0;
		mCommandTimeoutAmount = 0;
		break;
	}

	// Tell the robot where it's going
	int setPoint = Robot::chassis->rightRear->GetEncPosition();
	setPoint += mDriveDistance;
	Robot::chassis->pidStrafeWallController->SetSetpoint(setPoint);

	mCommandTimeoutTimer.Start();

	mPreviousEncoderReading = Robot::chassis->rightRear->GetEncPosition();
}

// Called repeatedly when this Command is scheduled to run
void autoStrafe::Execute() {
	Robot::chassis->pidStrafeWallController->Enable();

	if (mEncoderSafety)
	{
		// Check if encoder enough to show progress
		if ((std::abs(Robot::chassis->rightRear->GetEncPosition())
		     - mPreviousEncoderReading) < 50)
		{
			mTimeoutForEncoderChangeTimer.Start();
		}
		else
		{
			mTimeoutForEncoderChangeTimer.Stop();
			mTimeoutForEncoderChangeTimer.Reset();
		}

		mPreviousEncoderReading = Robot::chassis->rightRear->GetEncPosition();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool autoStrafe::IsFinished() {
	return ((mDistanceBased &&
			 Robot::chassis->pidStrafeWallController->OnTarget()) ||
			(mTimerBased &&
			 mCommandTimeoutTimer.HasPeriodPassed(mCommandTimeoutAmount)) ||
			(mEncoderSafety &&
			 mTimeoutForEncoderChangeTimer.HasPeriodPassed(0.25)));
}

// Called once after isFinished returns true
void autoStrafe::End() {
	mCommandTimeoutTimer.Stop();
	mCommandTimeoutTimer.Reset();
	mTimeoutForEncoderChangeTimer.Stop();
	mTimeoutForEncoderChangeTimer.Reset();
	Robot::chassis->pidStrafeWallController->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoStrafe::Interrupted() {
	mCommandTimeoutTimer.Stop();
	mCommandTimeoutTimer.Reset();
	mTimeoutForEncoderChangeTimer.Stop();
	mTimeoutForEncoderChangeTimer.Reset();
	Robot::chassis->pidStrafeWallController->Disable();
}
