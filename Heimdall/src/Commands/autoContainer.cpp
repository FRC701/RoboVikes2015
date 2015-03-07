// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "autoContainer.h"
#include "autoHaySqueezerOpen.h"
#include "haySqueezerClose.h"
#include "containerLevel.h"
#include "twoLevel.h"
#include "Delay.h"
#include "autoDrive.h"
#include "zeroLevel.h"
#include "goToyPosition.h"
#include "autoStrafe.h"
#include "chassisStopMoving.h"

autoContainer::autoContainer() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// Drop the elevator down and pick up the container
	AddSequential(new autoHaySqueezerOpen());
	AddSequential(new containerLevel());
	AddSequential(new haySqueezerClose());

	AddSequential(new Delay(0.5));

	// Lift the container off of the ground
	AddSequential(new twoLevel());

	// Slightly strafe left to avoid hitting the yellow tote
	AddSequential(new autoStrafe(-500));

	//AddSequential(new goToYPosition());			//REMEMBER TO REMOVE!!!

	// Drive into the auto zone
	AddSequential(new autoDrive(6580));

	// Stop moving (for debugging purposes)
	AddSequential(new chassisStopMoving());

	// The following lines of code should all be commented out due
	// to the Madera regional's rules
	// Put down the container and drive backwards to
	// abandon contact with the container
	// AddSequential(new zeroLevel());
	// AddSequential(new autoHaySqueezerOpen());
	// AddSequential(new goToYPosition());			//AND REMOVE THIS!!!!
	// AddSequential(new autoDrive(-300));

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
