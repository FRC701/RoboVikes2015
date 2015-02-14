// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Chassis.h"

#include "../Commands/Drive.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

static float kP = 0.0005;
static float kI = 0.0;
static float kD = 0.0;

Chassis::Chassis() : Subsystem("Chassis") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftLightSensor = RobotMap::chassisleftLightSensor;
	rightLightSensor = RobotMap::chassisrightLightSensor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	leftFront = RobotMap::chassisleftFrontMotor;
	leftRear = RobotMap::chassisleftRearMotor;
	rightFront = RobotMap::chassisrightFrontMotor;
	rightRear = RobotMap::chassisrightRearMotor;
	robotDrive = RobotMap::chassisRobotDrive;

	pidInput = new CANTalonEncoderPIDSource(leftRear);
	pidOutput = new RobotDrivePIDOutput(robotDrive);
	pidController = new PIDController(kP, kI, kD, pidInput, pidOutput);
	pidController->SetInputRange(0.0, 10000.0);
	pidController->SetOutputRange(-1.0, 1.0);
	pidController->SetAbsoluteTolerance(150);
/*
	accelerometerX = new robovikes::Accelerometer();
	accelerometerY = new robovikes::Accelerometer();
	builtinAccelerometer = new BuiltInAccelerometer();
	accelerometerNotifier = new Notifier(accelerometerCallback, this);

	accelerometerNotifier->StartPeriodic(0.1);
*/
}

void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
/*
void Chassis::stopFeedingCompensator()
{
	accelerometerX->stopFeedingCompensator();
	accelerometerY->stopFeedingCompensator();
}

void Chassis::accelerometerCallback(void* param)
{
	Chassis* This = reinterpret_cast<Chassis*>(param);
	// These 4 lines are in a specific order to ensure that the samples
	// from the accelerometer are always on the same time interval.
	double x = This->builtinAccelerometer->GetX();
	double y = This->builtinAccelerometer->GetY();
	This->accelerometerX->push(x);
	This->accelerometerY->push(y);
}
*/
