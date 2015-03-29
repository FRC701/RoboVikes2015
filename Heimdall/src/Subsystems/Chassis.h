// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

#include "../CANEncoderPIDInput.h"
#include "../RobotDrivePIDOutput.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
//Forward..........................................................................
	CANTalonEncoderPIDSource* pidInput;
	RobotDrivePIDOutput* pidOutput;
//Strafing.........................................................................
	CANTalonEncoderPIDSource* pidStrafeInput;
	RobotDrivePIDOutput* pidStrafeOutput;
//Strafing Wall.........................................................................
	CANTalonEncoderPIDSource* pidStrafeWallInput;
	RobotDrivePIDOutput* pidStrafeWallOutput;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* leftLightSensor;
	DigitalInput* rightLightSensor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
/*
	robovikes::Accelerometer* accelerometerX;
	robovikes::Accelerometer* accelerometerY;
	Accelerometer* builtinAccelerometer;
	Notifier* accelerometerNotifier;
*/
	CANTalon* leftFront;
	CANTalon* leftRear;
	CANTalon* rightFront;
	CANTalon* rightRear;
	RobotDrive* robotDrive;
//Forward...................................
	PIDController* pidController;
//Strafing.................................
	PIDController* pidStrafeController;
//Strafing.................................
	PIDController* pidStrafeWallController;

	Chassis();
	void InitDefaultCommand();

	//void stopFeedingCompensator();

private:
	//static void accelerometerCallback(void*);
};

#endif

