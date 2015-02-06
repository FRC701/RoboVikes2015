// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoRightForwardDrive.h"

AutoRightForwardDrive::AutoRightForwardDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void AutoRightForwardDrive::Initialize() {
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoRightForwardDrive::Execute() {
	Robot::chassis->robotDrive->MecanumDrive_Cartesian(0.5,0.0,0.0);
	//Robot::chassis->robotDrive->Drive(Robot::prefs->GetDouble ("RightForwardDriveDistance" , 0.0),0.0);
}


// Make this return true when this Command no longer needs to run execute()
bool AutoRightForwardDrive::IsFinished() {
	return timer.HasPeriodPassed(Robot::prefs->GetDouble("TimeToDriveRightForward",0.0));
}
// Called once after isFinished returns true
void AutoRightForwardDrive::End() {
	timer.Stop();
	timer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightForwardDrive::Interrupted() {
	timer.Stop();
	timer.Reset();
}