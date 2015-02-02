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
#include "../OI.h"
#include "Joystick.h"

rumble::rumble() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	timeForRumble = new Timer();
}

// Called just before this Command runs the first time
void rumble::Initialize() {
	cout << "Starting Commmand\n";
	timeForRumble->Start();

}

// Called repeatedly when this Command is scheduled to run
void rumble::Execute() {
	Robot::oi->getdriver()->SetRumble(Joystick::kRightRumble, 1.0);
	cout << "Running Execute!\n";
}

// Make this return true when this Command no longer needs to run execute()
bool rumble::IsFinished() {
	cout << "Testing for finish conditions\n";
	return timeForRumble->HasPeriodPassed(0.5);
}

// Called once after isFinished returns true
void rumble::End() {
	timeForRumble->Stop();
	timeForRumble->Reset();
	cout << "Finishing Rumble!\n";
	Robot::oi->getdriver()->SetRumble(Joystick::kRightRumble, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void rumble::Interrupted() {

}
