// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "chuteHight.h"

chuteHight::chuteHight() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::spool);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void chuteHight::Initialize() {
	Robot::spool->pidController->SetSetpoint(2650);
}

// Called repeatedly when this Command is scheduled to run
void chuteHight::Execute() {
	Robot::spool->pidController->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool chuteHight::IsFinished() {
	return Robot::spool->pidController->OnTarget();
}

// Called once after isFinished returns true
void chuteHight::End() {
	Robot::spool->pidController->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void chuteHight::Interrupted() {
	Robot::spool->pidController->Disable();
}
