// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "haySqueezerDefault.h"

haySqueezerDefault::haySqueezerDefault() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::haySqueezer);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void haySqueezerDefault::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void haySqueezerDefault::Execute() {
	bool current = false;
	bool last = false;
	if(Robot::oi->getcoDriver()->GetRawAxis(4) == 1.0 && current != last)
	{
		if(Robot::haySqueezer->haySqueezerSolenoid->Get() == DoubleSolenoid::kReverse)		//Test current condition of
		{																					//	hayS. solenoid by calling Get()
			Robot::haySqueezer->haySqueezerSolenoid->Set(DoubleSolenoid::kForward);			//Set opposite to test condition
		}
		else if(Robot::haySqueezer->haySqueezerSolenoid->Get() == DoubleSolenoid::kForward)
		{
			Robot::haySqueezer->haySqueezerSolenoid->Set(DoubleSolenoid::kReverse);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool haySqueezerDefault::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void haySqueezerDefault::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void haySqueezerDefault::Interrupted() {

}
