
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
using namespace std;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoDoNothing.h"
#include "Commands/Drive.h"
#include "Commands/PneIntakeOut.h"
#include "Commands/autoContainer.h"
#include "Commands/autoDrive.h"
#include "Commands/autoDriveIntoZone.h"
#include "Commands/autoForwardThreeTote.h"
#include "Commands/autoGrabTwoContainers.h"
#include "Commands/autoHaySqueezerOpen.h"
#include "Commands/autoHighBeforeParallelThreeTote.h"
#include "Commands/autoLeftStrafeThreeTote.h"
#include "Commands/autoLightStrafeLeft.h"
#include "Commands/autoLightStrafeRight.h"
#include "Commands/autoOneTote.h"
#include "Commands/autoStrafe.h"
#include "Commands/autoStrafeRightThreeTote.h"
#include "Commands/autoStrafeToToteLeft.h"
#include "Commands/autoStrafeToToteRight.h"
#include "Commands/autoStrafeUntilNoYellowTote.h"
#include "Commands/autoWideStack.h"
#include "Commands/breakToggle.h"
#include "Commands/canGrabberSetForward.h"
#include "Commands/canGrabberSetReverse.h"
#include "Commands/canGrabberToggle.h"
#include "Commands/chassisStopMoving.h"
#include "Commands/chuteHight.h"
#include "Commands/chuteStack.h"
#include "Commands/containerLevel.h"
#include "Commands/containerTwoLevel.h"
#include "Commands/goToYPosition.h"
#include "Commands/grabOneTote.h"
#include "Commands/haySqueezerClose.h"
#include "Commands/haySqueezerDefault.h"
#include "Commands/haySqueezerOpen.h"
#include "Commands/haySqueezerToggle.h"
#include "Commands/icePickLevel.h"
#include "Commands/intakeIn.h"
#include "Commands/intakeOff.h"
#include "Commands/intakeOut.h"
#include "Commands/lightsDefault.h"
#include "Commands/lightsOff.h"
#include "Commands/lightsOn.h"
#include "Commands/maxLevel.h"
#include "Commands/oneLevel.h"
#include "Commands/oneLevelOpenIntake.h"
#include "Commands/pneIntakeDefault.h"
#include "Commands/pneIntakeIn.h"
#include "Commands/pneIntakeToggle.h"
#include "Commands/rumble.h"
#include "Commands/spoolAboveContainer.h"
#include "Commands/spoolClockwise.h"
#include "Commands/spoolCounterClockwise.h"
#include "Commands/spoolOff.h"
#include "Commands/twoLevel.h"
#include "Commands/zeroLevel.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.

	encoderStartingValue = Robot::spool->spoolRightMotor->GetEncPosition();

    	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	coDriver = new Joystick(1);
	
	driver = new Joystick(0);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("autoLeftStrafeThreeTote", new autoLeftStrafeThreeTote());

	SmartDashboard::PutData("autoDriveIntoZone", new autoDriveIntoZone());

	SmartDashboard::PutData("autoContainer", new autoContainer());

	SmartDashboard::PutData("AutoDoNothing", new AutoDoNothing());

	SmartDashboard::PutData("autoOneTote", new autoOneTote());

	SmartDashboard::PutData("autoStrafeToToteRight", new autoStrafeToToteRight());

	SmartDashboard::PutData("autoDrive", new autoDrive());

	SmartDashboard::PutData("intakeIn", new intakeIn());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("intakeOut", new intakeOut());

	SmartDashboard::PutData("intakeOff", new intakeOff());

	SmartDashboard::PutData("haySqueezerToggle", new haySqueezerToggle());

	SmartDashboard::PutData("spoolOff", new spoolOff());

	SmartDashboard::PutData("spoolClockwise", new spoolClockwise());

	SmartDashboard::PutData("spoolCounterClockwise", new spoolCounterClockwise());

	SmartDashboard::PutData("haySqueezerClose", new haySqueezerClose());

	SmartDashboard::PutData("haySqueezerOpen", new haySqueezerOpen());

	SmartDashboard::PutData("pneIntakeDefault", new pneIntakeDefault());

	SmartDashboard::PutData("pneIntakeIn", new pneIntakeIn());

	SmartDashboard::PutData("pneIntakeToggle", new pneIntakeToggle());

	SmartDashboard::PutData("PneIntakeOut", new PneIntakeOut());

	SmartDashboard::PutData("rumble", new rumble());

	SmartDashboard::PutData("oneLevel", new oneLevel());

	SmartDashboard::PutData("twoLevel", new twoLevel());

	SmartDashboard::PutData("containerLevel", new containerLevel());

	SmartDashboard::PutData("containerTwoLevel", new containerTwoLevel());

	SmartDashboard::PutData("zeroLevel", new zeroLevel());

	SmartDashboard::PutData("maxLevel", new maxLevel());

	SmartDashboard::PutData("breakToggle", new breakToggle());

	SmartDashboard::PutData("goToYPosition", new goToYPosition());

	SmartDashboard::PutData("autoStrafe", new autoStrafe());

	SmartDashboard::PutData("chuteStack", new chuteStack());

	SmartDashboard::PutData("grabOneTote", new grabOneTote());

	SmartDashboard::PutData("chuteHight", new chuteHight());

	SmartDashboard::PutData("oneLevelOpenIntake", new oneLevelOpenIntake());

	SmartDashboard::PutData("haySqueezerDefault", new haySqueezerDefault());

	SmartDashboard::PutData("lightsOn", new lightsOn());

	SmartDashboard::PutData("lightsOff", new lightsOff());

	SmartDashboard::PutData("lightsDefault", new lightsDefault());

	SmartDashboard::PutData("autoHaySqueezerOpen", new autoHaySqueezerOpen());

	SmartDashboard::PutData("autoStrafeToToteLeft", new autoStrafeToToteLeft());

	SmartDashboard::PutData("autoStrafeRightThreeTote", new autoStrafeRightThreeTote());

	SmartDashboard::PutData("autoWideStack", new autoWideStack());

	SmartDashboard::PutData("autoLightStrafeRight", new autoLightStrafeRight());

	SmartDashboard::PutData("autoLightStrafeLeft", new autoLightStrafeLeft());

	SmartDashboard::PutData("chassisStopMoving", new chassisStopMoving());

	SmartDashboard::PutData("icePickLevel", new icePickLevel());

	SmartDashboard::PutData("spoolAboveContainer", new spoolAboveContainer());

	SmartDashboard::PutData("autoStrafeUntilNoYellowTote", new autoStrafeUntilNoYellowTote());

	SmartDashboard::PutData("canGrabberSetForward", new canGrabberSetForward());

	SmartDashboard::PutData("canGrabberSetReverse", new canGrabberSetReverse());

	SmartDashboard::PutData("canGrabberToggle", new canGrabberToggle());

	SmartDashboard::PutData("autoGrabTwoContainers", new autoGrabTwoContainers());

	SmartDashboard::PutData("autoHighBeforeParallelThreeTote", new autoHighBeforeParallelThreeTote());

	SmartDashboard::PutData("autoForwardThreeTote", new autoForwardThreeTote());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

//Auto Testing.......................................................
	SmartDashboard::PutData("autoDrive X", new autoDrive(
		autoDrive::Purpose::goToAutoZone, true, true, false));
	SmartDashboard::PutData("autoStrafe X", new autoStrafe(
		autoStrafe::Purpose::rightToAvoidContainer, false, true, false));

//Guitar..........................................................
/*
	gButtonGreen = new JoystickButton(coDriver, 1);
	gButtonGreen->WhenReleased(new PneIntakeOut());
	gButtonRed = new JoystickButton(coDriver, 2);
	gButtonRed->WhenReleased(new zeroLevel());
	gButtonYellow = new JoystickButton(coDriver, 4);
	gButtonYellow->WhenReleased(new oneLevel());
	gButtonBlue = new JoystickButton(coDriver, 3);
	gButtonBlue->WhenReleased(new twoLevel());
	gButtonOrange = new JoystickButton(coDriver, 5);
	gButtonOrange->WhenReleased(new chuteStack());
	gButtonBack = new JoystickButton(coDriver, 7);
	gButtonBack->WhileHeld(new spoolClockwise());
	gButtonStart = new JoystickButton(coDriver, 8);
	gButtonStart->WhileHeld(new spoolCounterClockwise());

*/

//Box Code.........................................................
///*
	cYellow = new JoystickButton(coDriver, 2);
	cYellow->WhenReleased(new pneIntakeToggle());
	cSmallRed = new JoystickButton(coDriver, 1);
	cSmallRed->WhileHeld(new intakeIn());
	cSmallBlack = new JoystickButton(coDriver, 3);
	cSmallBlack->WhileHeld(new intakeOut());
	cGreen = new JoystickButton(coDriver, 4);
	cGreen->WhenReleased(new haySqueezerToggle());

	cBlue = new JoystickButton(coDriver, 9);
	cBlue->WhenReleased(new canGrabberToggle());
	cWhite = new JoystickButton(coDriver, 13);
	cWhite->WhenReleased(new twoLevel());
	cBlack = new JoystickButton(coDriver, 8);
	cBlack->WhenReleased(new oneLevel());
	cRed = new JoystickButton(coDriver, 12);
	cRed->WhenReleased(new zeroLevel());
	cGreenLeft = new JoystickButton(coDriver, 15);
	cGreenLeft->WhenReleased(new icePickLevel());
//*/

//coDriver Xbox Controller................................................................
/*
	coButtonA = new JoystickButton(coDriver, 1);
	coButtonA->WhileHeld(new intakeIn());
	coButtonB = new JoystickButton(coDriver, 2);
	coButtonB->WhileHeld(new intakeOut());
	coButtonX = new JoystickButton(coDriver, 3);
	coButtonX->WhenReleased(new pneIntakeToggle());
	coButtonLB = new JoystickButton(coDriver, 5);
	coButtonLB->WhenReleased(new haySqueezerToggle());
	coButtonRB = new JoystickButton(coDriver, 6);
	coButtonRB->WhenReleased(new breakToggle());
*/

//Not really being used any more......................................
	dButtonRB = new JoystickButton(driver, 6);
	dButtonLB = new JoystickButton(driver, 5);
//....................................................................

	dButtonL3 = new JoystickButton(driver, 9);
	dButtonL3->WhenReleased(new rumble);;

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


