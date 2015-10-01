// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "zeroLevel.h"

zeroLevel::zeroLevel() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::spool);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void zeroLevel::Initialize() {
	//Robot::spool->pidController->SetSetpoint(
		//Robot::prefs->GetDouble("zeroLevel", 20.0));
}

// Called repeatedly when this Command is scheduled to run
void zeroLevel::Execute() {
	//Robot::spool->pidController->Enable();
	Robot::spool->pidOutput->Set(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool zeroLevel::IsFinished() {
	return !Robot::spool->spoolLeftMotor->GetReverseLimitOK();

			//Robot::spool->pidController->OnTarget();
}

// Called once after isFinished returns true
void zeroLevel::End() {
	//Robot::spool->pidController->Disable();
	Robot::spool->pidOutput->Set(0.0);

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void zeroLevel::Interrupted() {
	//Robot::spool->pidController->Disable();
	Robot::spool->pidOutput->Set(0.0);
}
