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
using namespace std;

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	fullPower = 1.0;
	multiplier = 0.0;
	enableMultiplier = false;
	currentCondition = false;
	lastCondition = false;
	multiplier = Robot::prefs->GetDouble("multiplier", 0.3);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {

//Tank Drive.................................................................................................
	//Robot::chassis->robotDrive->TankDrive(Robot::oi->getdriver(),
	//				                      leftY,
	//				                      Robot::oi->getdriver(),
	//				                      rightY);


//Raw Mecanum Drive..........................................................................................
	Robot::chassis->robotDrive->MecanumDrive_Cartesian(Robot::oi->getdriver()->GetRawAxis(leftX) * getMultiplier(),
													Robot::oi->getdriver()->GetRawAxis(leftY) * getMultiplier(),
													Robot::oi->getdriver()->GetRawAxis(rightX) * getMultiplier());

//Software Shifting...........................................................................................
	toggleL3();
	//Robot::oi->getdriver()->SetRumble(Joystick::kLeftRumble, 0.0);

//Mecanum Drive Triggers...............................................................................................
	//double xInput = /*getJoystickTriggerValue()*/ Robot::oi->getdriver()->GetRawAxis(0) * getMultiplier();
	//double yInput = Robot::oi->getdriver()->GetRawAxis(Drive::leftY) * getMultiplier();
	//double rotInput = Robot::oi->getdriver()->GetRawAxis(Drive::rightX) * getMultiplier();

	//Robot::chassis->robotDrive->MecanumDrive_Cartesian(xInput, yInput, rotInput);

//Debugging SmartDashboard Outputs.............................................................................
	//SmartDashboard::PutNumber("Mulitplier", getMultiplier());
	//SmartDashboard::PutNumber("xInput", xInput);
	//SmartDashboard::PutNumber("yInput", yInput);
	//SmartDashboard::PutNumber("rotInput", rotInput);
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

double Drive::getJoystickTriggerValue()	//Combines triggers RT and LT to make one joystick for Mechanium
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

double Drive::getMultiplier()
{
	return enableMultiplier ? multiplier : fullPower;
}

void Drive::setEnableMultiplier(bool isEnable)
{
	enableMultiplier = isEnable;
}

bool Drive::getEnableMultiplier()
{
	return enableMultiplier;
}

void Drive::toggleL3()
{
	currentCondition = Robot::oi->getdButtonL3()->Get();
	if(currentCondition != lastCondition)
	{
		cout << "L3 Changed State!\n";
		if(currentCondition)
		{
			cout << "L3 Retrieved as True!\n";
			getEnableMultiplier() ? setEnableMultiplier(false) : setEnableMultiplier(true);
			//Robot::oi->driverRumbler->start(Joystick::kLeftRumble, 0.3);
		}
		else if(!currentCondition)
		{
			cout << "L3 Changed to False!\n";
			//Robot::oi->getdriver()->SetRumble(Joystick::kLeftRumble, 0.0);
			//Robot::oi->getdriver()->SetRumble(Joystick::kRightRumble, 0.0);
		}
	}
	lastCondition = currentCondition;
}

