// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Spool.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/spoolOff.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

static float kP = 0.0015;
static float kI = 0.0;
static float kD = 0.0;


Spool::Spool() : Subsystem("Spool") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	spoolLeftMotor = RobotMap::spoolLeftMotor;
	spoolRightMotor = RobotMap::spoolRightMotor;
	pidInput = new CANTalonEncoderPIDSource(spoolLeftMotor, true); //kInverted TODO be added
	pidOutput = new TwoMotorPIDOutput(spoolLeftMotor, spoolRightMotor);
	pidController = new PIDController(kP, kI, kD, pidInput, pidOutput);
	pidController->SetInputRange(0.0, 4000.0);
	pidController->SetOutputRange(-1.0, 1.0);
	pidController->SetTolerance(5.0);
}
    
void Spool::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new spoolOff());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

