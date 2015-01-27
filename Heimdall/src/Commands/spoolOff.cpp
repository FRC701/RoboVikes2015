// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "spoolOff.h"

spoolOff::spoolOff() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::spool);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void spoolOff::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void spoolOff::Execute() {
	if(Robot::prefs->GetString("coDriver") == "Fish")
	{
		Robot::spool->spoolLeftMotor->Set(Robot::oi->getcoDriver()->GetRawAxis(1) * -1);
		Robot::spool->spoolRightMotor->Set(Robot::oi->getcoDriver()->GetRawAxis(1) * -1);
	}
	else
	{
		Robot::spool->spoolLeftMotor->Set(0.0);
		Robot::spool->spoolRightMotor->Set(0.0);
	}
}


// Make this return true when this Command no longer needs to run execute()
bool spoolOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void spoolOff::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void spoolOff::Interrupted() {

}
