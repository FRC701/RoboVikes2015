// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "pneIntakeDefault.h"

pneIntakeDefault::pneIntakeDefault() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::pneIntake);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	//Robot::haySqueezer->haySqueezerSolenoid->Set(DoubleSolenoid::kReverse);
}

// Called just before this Command runs the first time
void pneIntakeDefault::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void pneIntakeDefault::Execute() {
	//if(Robot::oi->getcoDriver()->GetRawAxis(1) > 0.05)
		//Robot::pneIntake->intakeSolenoid->Set(DoubleSolenoid::kForward);
}

// Make this return true when this Command no longer needs to run execute()
bool pneIntakeDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void pneIntakeDefault::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run]\[
void pneIntakeDefault::Interrupted() {

}
