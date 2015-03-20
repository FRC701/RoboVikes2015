// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "autoHaySqueezerOpen.h"
#include "zeroLevel.h"
#include "haySqueezerClose.h"
#include "spoolAboveContainer.h"
#include "autoStrafeToToteRight.h"
#include "autoDrive.h"
#include "autoStrafe.h"
#include "autoWideStack.h"
#include "autoLightStrafeRight.h"
#include "autoStrafeToToteLeft.h"
#include "Delay.h"

#include "autoStrafeRightThreeTote.h"

autoStrafeRightThreeTote::autoStrafeRightThreeTote() {
	//Open HaySqueezer
	AddSequential(new autoHaySqueezerOpen());
	//Go Down
	AddSequential(new zeroLevel());
	//close
	AddSequential(new haySqueezerClose());
	//Delay for closing
	AddSequential(new Delay(0.1));
	//Strafe Slightly to the right to avoid knocking first container down
	AddSequential(new autoStrafe(600, 0.5));
	//Go above the container
	AddSequential(new spoolAboveContainer());
//.............................................................. Second Tote
	//Strafe to the right to tote
	AddSequential(new autoStrafeToToteRight());

		//Strafe slightly right to clear container
//***** AddSequential(new autoStrafe(500, 0.5));		//Encoder Dependent
		AddSequential(new autoLightStrafeRight());		//Banner Sensor Dependent

	//lower elevator directly above tote
	AddSequential(new autoWideStack());

		//move back over tote
//*****	AddSequential(new autoStrafe(-500, 0.5)); 		//Similar to before. !!!We can also
		AddSequential(new autoStrafeToToteLeft());		// use the strafe command as a timer
														// based strafe by ending command
														// short(decrease time out)

	//open hay squeezer
	AddSequential(new autoHaySqueezerOpen());
	//lower elevator on tote
	AddSequential(new zeroLevel());
	//close hay squeezer on tote
	AddSequential(new haySqueezerClose());
	//
	AddSequential(new Delay(0.1));
	//
	AddSequential(new autoStrafe(500, 0.5));
	//
	AddSequential(new spoolAboveContainer());
	//..............................................................Third Tote
	//Strafe to the right to tote
	AddSequential(new autoStrafeToToteRight());

		//Strafe slightly right to clear container
//*****	AddSequential(new autoStrafe(500, 0.5));
		AddSequential(new autoLightStrafeRight());

	//lower elevator directly above tote
	AddSequential(new autoWideStack());

		//move back over tote
//*****	AddSequential(new autoStrafe(-500, 0.5));
		AddSequential(new autoStrafeToToteLeft());
	/*
	//open hay squeezer
	AddSequential(new autoHaySqueezerOpen());
	//lower elevator on tote
	AddSequential(new zeroLevel());
	//close hay squeezer on tote
	AddSequential(new haySqueezerClose());
	//
	AddSequential(new autoStrafe(500, 0.5));
	//............................................................Drive
	 */

	AddSequential(new autoDrive(6700));

}
