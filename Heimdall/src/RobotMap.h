// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DoubleSolenoid* pneIntakeintakeSolenoid;
	static DoubleSolenoid* haySqueezerhaySqueezerSolenoid;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANTalon* spoolLeftMotor;
	static CANTalon* spoolRightMotor;
	static CANTalon* chassisleftFrontMotor;
	static CANTalon* chassisleftRearMotor;
	static CANTalon* chassisrightFrontMotor;
	static CANTalon* chassisrightRearMotor;
	static RobotDrive* chassisRobotDrive;
	static CANTalon* slideFrontMotor1;
	static CANTalon* slideFrontMotor2;
	static CANTalon* slideRearMotor;
	static CANTalon* intakeRightMotor;
	static CANTalon* intakeLeftMotor;
	static void init();
};
#endif
