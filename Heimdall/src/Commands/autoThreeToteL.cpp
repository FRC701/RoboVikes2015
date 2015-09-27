// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "autoThreeToteL.h"
#include "zeroLevel.h"
#include "oneLevel.h"
#include "Drive.h"
#include "PneIntakeOut.h"
#include "pneIntakeIn.h"
#include "intakeIn.h"
#include "Delay.h"
#include "intakeOff.h"
#include "autoStrafe.h"
#include "haySqueezerOpen.h"
#include "autoDrive.h"

autoThreeToteL::autoThreeToteL() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	AddSequential(new zeroLevel());
	AddSequential(new oneLevel());
	AddSequential(new autoDrive(autoDrive::Purpose::drivePastSecondTote, false, true, false));
/*	AddSequential(new PneIntakeOut());
	AddSequential(new pneIntakeIn());
	AddSequential(new intakeIn());
	AddSequential(new Delay(1));
	AddSequential(new intakeOff());
	AddSequential(new zeroLevel());
	AddSequential(new PneIntakeOut());
	AddSequential(new Drive());
	AddSequential(new pneIntakeIn());
	AddSequential(new intakeIn());
	AddSequential(new autoStrafe());					//TODO: SortOut
	AddSequential(new zeroLevel());
	AddSequential(new haySqueezerOpen());
	AddSequential(new PneIntakeOut());
	AddSequential(new Drive()); */

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
