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

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/SlideLeft.h"
#include "Commands/SlideOff.h"
#include "Commands/SlideRight.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	driver = new Joystick(0);
	
	dButtonRB = new JoystickButton(driver, 6);
	dButtonRB->WhileHeld(new SlideRight());
	dButtonLB = new JoystickButton(driver, 5);
	dButtonLB->WhileHeld(new SlideLeft());
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("SlideLeft", new SlideLeft());

	SmartDashboard::PutData("SlideRight", new SlideRight());

	SmartDashboard::PutData("SlideOff", new SlideOff());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	SmartDashboard::PutNumber("Right Axis Value", Robot::oi->getdriver()->GetRawAxis(1));
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getdriver() {
	return driver;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
