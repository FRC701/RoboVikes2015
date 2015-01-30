// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "rumble.h"

rumble::rumble() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	timeForRumble = 0;
}

// Called just before this Command runs the first time
void rumble::Initialize() {
	timeForRumble->Start();
}

// Called repeatedly when this Command is scheduled to run
void rumble::Execute() {
	Robot::oi->getdriver()->SetRumble(Joystick::kLeftRumble, 1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool rumble::IsFinished() {
	return timeForRumble->HasPeriodPassed(Robot::prefs->GetDouble("Rumble", 1.0));
}

// Called once after isFinished returns true
void rumble::End() {
	Robot::oi->getdriver()->SetRumble(Joystick::kLeftRumble, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void rumble::Interrupted() {

}
