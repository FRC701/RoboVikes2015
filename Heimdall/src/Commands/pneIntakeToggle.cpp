// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "pneIntakeToggle.h"

pneIntakeToggle::pneIntakeToggle() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::pneIntake);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void pneIntakeToggle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void pneIntakeToggle::Execute() {
	if(RobotMap::pneIntakeintakeSolenoid->Get() == DoubleSolenoid::kForward)		//Test current condition calling
	{																				// Get(), inverts current state
		Robot::pneIntake->intakeSolenoid->Set(DoubleSolenoid::kReverse);
	}
	else if(RobotMap::pneIntakeintakeSolenoid->Get() == DoubleSolenoid::kReverse)
	{
		Robot::pneIntake->intakeSolenoid->Set(DoubleSolenoid::kForward);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool pneIntakeToggle::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void pneIntakeToggle::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void pneIntakeToggle::Interrupted() {

}
