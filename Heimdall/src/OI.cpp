// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"
#include "BuiltInAccelerometer.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoPneumaticIntakeIn.h"
#include "Commands/AutoPneumaticIntakeOut.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/PneIntakeOut.h"
#include "Commands/haySqueezerToggle.h"
#include "Commands/intakeIn.h"
#include "Commands/intakeOff.h"
#include "Commands/intakeOut.h"
#include "Commands/spoolClockwise.h"
#include "Commands/spoolCounterClockwise.h"
#include "Commands/spoolOff.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	coDriver = new Joystick(1);
	
	coButtonLB = new JoystickButton(coDriver, 5);
	coButtonLB->WhileHeld(new spoolCounterClockwise());
	coButtonRB = new JoystickButton(coDriver, 6);
	coButtonRB->WhileHeld(new spoolClockwise());
	coButtonX = new JoystickButton(coDriver, 3);
	coButtonX->WhenReleased(new haySqueezerToggle());
	coButtonY = new JoystickButton(coDriver, 4);
	coButtonY->WhileHeld(new intakeIn());
	coButtonA = new JoystickButton(coDriver, 1);
	coButtonA->WhenReleased(new PneIntakeOut());
	coButtonB = new JoystickButton(coDriver, 2);
	coButtonB->WhileHeld(new intakeOut());
	driver = new Joystick(0);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("intakeOut", new intakeOut());

	SmartDashboard::PutData("intakeIn", new intakeIn());

	SmartDashboard::PutData("intakeOff", new intakeOff());

	SmartDashboard::PutData("PneIntakeOut", new PneIntakeOut());

	SmartDashboard::PutData("haySqueezerToggle", new haySqueezerToggle());

	SmartDashboard::PutData("spoolOff", new spoolOff());

	SmartDashboard::PutData("spoolClockwise", new spoolClockwise());

	SmartDashboard::PutData("spoolCounterClockwise", new spoolCounterClockwise());

	SmartDashboard::PutData("AutoPneumaticIntakeIn", new AutoPneumaticIntakeIn());

	SmartDashboard::PutData("AutoPneumaticIntakeOut", new AutoPneumaticIntakeOut());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	dButtonRB = new JoystickButton(driver, 6);
	dButtonLB = new JoystickButton(driver, 5);
	dButtonL3 = new JoystickButton(driver, 9);
	rumbleTimer = new Timer;

}

void OI::singleRumbleTime(int x)
{
	if(rumbleTimer->Get() > 0)
		{
		rumbleTimer->Stop();
		rumbleTimer->Reset();
		}
	rumbleTimer->Start();
	singleRumbleForSomeTime(x);
}

void OI::singleRumbleForSomeTime(int x)
{
	getdriver()->SetRumble(Joystick::kLeftRumble, 1.0);
	getdriver()->SetRumble(Joystick::kRightRumble, 1.0);
	if(!rumbleTimer->HasPeriodPassed(x))
		singleRumbleForSomeTime(x);
	else if(rumbleTimer->HasPeriodPassed(x))
	{
		getdriver()->SetRumble(Joystick::kLeftRumble, 0.0);
		getdriver()->SetRumble(Joystick::kRightRumble, 0.0);
	}
}

JoystickButton* OI::getdButtonRB()
{
	return dButtonRB;
}

JoystickButton* OI::getdButtonLB()
{
	return dButtonLB;
}

JoystickButton* OI::getdButtonL3()
{
	return dButtonL3;
}


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getcoDriver() {
	return coDriver;
}

Joystick* OI::getdriver() {
	return driver;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS


