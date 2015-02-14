// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "goToYPosition.h"

goToYPosition::goToYPosition() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void goToYPosition::Initialize() {
	Robot::chassis->pidController->SetSetpoint(Robot::prefs->GetDouble("driveDistance"));
}

// Called repeatedly when this Command is scheduled to run
void goToYPosition::Execute() {
	Robot::chassis->pidController->Enable();
	SmartDashboard::PutNumber("Left Front Motor Set", Robot::chassis->leftFront->GetSetpoint());
	SmartDashboard::PutNumber("Left Rear Motor Set", Robot::chassis->leftRear->GetSetpoint());
	SmartDashboard::PutNumber("right Front Motor Set", Robot::chassis->rightFront->GetSetpoint());
	SmartDashboard::PutNumber("right Rear Motor Set", Robot::chassis->rightRear->GetSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool goToYPosition::IsFinished() {
	return false; //Robot::chassis->pidController->OnTarget();
}

// Called once after isFinished returns true
void goToYPosition::End() {
	//Robot::chassis->pidController->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void goToYPosition::Interrupted() {
	//Robot::chassis->pidController->Disable();
}
