// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
DoubleSolenoid* RobotMap::pneIntakeintakeSolenoid = NULL;
DoubleSolenoid* RobotMap::haySqueezerhaySqueezerSolenoid = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::chassisleftFrontMotor = NULL;
CANTalon* RobotMap::chassisleftRearMotor = NULL;
CANTalon* RobotMap::chassisrightFrontMotor = NULL;
CANTalon* RobotMap::chassisrightRearMotor = NULL;
RobotDrive* RobotMap::chassisRobotDrive = NULL;
/*//Slide Motors.....................................................................
CANTalon* RobotMap::slideFrontMotor1 = NULL;
CANTalon* RobotMap::slideFrontMotor2 = NULL;
CANTalon* RobotMap::slideRearMotor = NULL;
*/
CANTalon* RobotMap::intakeRightMotor = NULL;
CANTalon* RobotMap::intakeLeftMotor = NULL;
CANTalon* RobotMap::spoolLeftMotor = NULL;
CANTalon* RobotMap::spoolRightMotor = NULL;

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	pneIntakeintakeSolenoid = new DoubleSolenoid(0, 0, 7);      
	lw->AddActuator("PneIntake", "intakeSolenoid", pneIntakeintakeSolenoid);
	
	haySqueezerhaySqueezerSolenoid = new DoubleSolenoid(0, 1, 6);      
	lw->AddActuator("HaySqueezer", "haySqueezerSolenoid", haySqueezerhaySqueezerSolenoid);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	intakeLeftMotor = new CANTalon(8);
	intakeRightMotor = new CANTalon(7);
    chassisleftFrontMotor = new CANTalon(5);
    chassisleftRearMotor = new CANTalon(11);
    chassisrightFrontMotor = new CANTalon(6);
    chassisrightRearMotor = new CANTalon(12);
/*	//Slide Motors.................................................................................
    slideFrontMotor1 = new CANTalon(4);
    slideFrontMotor2 = new CANTalon(2);
    slideRearMotor = new CANTalon(10);
*/
    spoolLeftMotor = new CANTalon(2);
    spoolRightMotor = new CANTalon(4);

    chassisRobotDrive = new RobotDrive(chassisleftFrontMotor, chassisleftRearMotor,
                  chassisrightFrontMotor, chassisrightRearMotor);

    chassisRobotDrive->SetSafetyEnabled(false);
    //chassisRobotDrive->SetExpiration(0.1);
    chassisRobotDrive->SetSensitivity(0.5);
    chassisRobotDrive->SetMaxOutput(1.0);

}
