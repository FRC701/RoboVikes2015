// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "autoOneTote.h"
#include "haySqueezerOpen.h"
#include "haySqueezerClose.h"
#include "zeroLevel.h"
#include "oneLevel.h"
#include "twoLevel.h"
#include "autoDrive.h"
#include "autoStrafe.h"
#include "Delay.h"


autoOneTote::autoOneTote() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	AddSequential(new haySqueezerOpen());
	AddSequential(new zeroLevel());
	AddSequential(new haySqueezerClose());
	AddSequential(new autoStrafe(1000));
	AddSequential(new Delay(0.5));
	AddSequential(new oneLevel());
	AddSequential(new autoDrive(1000));
	AddSequential(new zeroLevel());
	AddSequential(new haySqueezerOpen());
	AddSequential(new twoLevel());
	AddSequential(new autoDrive(-300));

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
