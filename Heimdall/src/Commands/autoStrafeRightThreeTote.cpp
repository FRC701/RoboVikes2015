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
#include "twoLevel.h"
#include "autoStrafeToToteRight.h"
#include "autoDrive.h"
#include "autoStrafe.h"
#include "oneLevel.h"

#include "autoStrafeRightThreeTote.h"

autoStrafeRightThreeTote::autoStrafeRightThreeTote() {
	//Open HaySqueezer
		AddSequential(new autoHaySqueezerOpen());
		//Go Down
		AddSequential(new zeroLevel());
		//close
		AddSequential(new haySqueezerClose());
		//Go above the container
		AddSequential(new twoLevel());
	//.............................................................. Second Tote
		//Strafe to the right to tote
		AddSequential(new autoStrafeToToteRight());
		//Strafe slightly right to clear container
		AddSequential(new autoStrafe(500));
		//lower elevator directly above tote
		AddSequential(new oneLevel());
		//move back over tote
		AddSequential(new autoStrafe(-500));
		//open hay squeezer
		AddSequential(new autoHaySqueezerOpen());
		//lower elevator on tote
		AddSequential(new zeroLevel());
		//close hay squeezer on tote
		AddSequential(new haySqueezerClose());
		//
		AddSequential(new autoStrafe(500));
		//
		AddSequential(new twoLevel());
	//..............................................................Third Tote
		//Strafe to the left to tote
		AddSequential(new autoStrafeToToteRight());
		//Strafe slightly right to clear container
		AddSequential(new autoStrafe(500));
		//lower elevator directly above tote
		AddSequential(new oneLevel());
		//move back over tote
		AddSequential(new autoStrafe(-500));
		//open hay squeezer
		AddSequential(new autoHaySqueezerOpen());
		//lower elevator on tote
		AddSequential(new zeroLevel());
		//close hay squeezer on tote
		AddSequential(new haySqueezerClose());
		//
		AddSequential(new autoStrafe(500));
		//............................................................Drive
		//
		AddSequential(new autoDrive(7600));

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
