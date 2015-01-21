// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../OI.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {

	//Robot::chassis->robotDrive->TankDrive(Robot::oi->getdriver(),
	//				                      leftY,
	//				                      Robot::oi->getdriver(),
	//				                      rightY);
	//Robot::chassis->robotDrive->MecanumDrive_Cartesian(Robot::oi->getdriver()->GetRawAxis(leftX),
	//												Robot::oi->getdriver()->GetRawAxis(leftY),
	//												Robot::oi->getdriver()->GetRawAxis(rightX));

	Robot::chassis->robotDrive->MecanumDrive_Cartesian(getJoystickTriggerValue(),
														Robot::oi->getdriver()->GetRawAxis(Drive::leftY),
														Robot::oi->getdriver()->GetRawAxis(Drive::rightX));


}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}

double Drive::getJoystickTriggerValue()
{
	int joystickRTLT = 0;
	if(Robot::oi->getdriver()->GetRawAxis(Drive::leftTrigger) > 0.0 && Robot::oi->getdriver()->
																GetRawAxis(Drive::rightTrigger) == 0.0)
	{
		joystickRTLT = Robot::oi->getdriver()->GetRawAxis(Drive::leftTrigger) * -1;
	}
	else if(Robot::oi->getdriver()->GetRawAxis(Drive::rightTrigger) > 0.0 && Robot::oi->getdriver()->
																	 GetRawAxis(Drive::leftTrigger) == 0.0)
	{
		joystickRTLT = Robot::oi->getdriver()->GetRawAxis(Drive::rightTrigger);
	}
	else
	{
		joystickRTLT = 0.0;
	}
	return joystickRTLT;
}


