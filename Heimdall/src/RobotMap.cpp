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
CANJaguar* RobotMap::slideCANJaguar1 = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANTalon* RobotMap::chassisleftFrontMotor = NULL;
CANTalon* RobotMap::chassisleftRearMotor = NULL;
CANTalon* RobotMap::chassisrightFrontMotor = NULL;
CANTalon* RobotMap::chassisrightRearMotor = NULL;
RobotDrive* RobotMap::chassisRobotDrive = NULL;
CANTalon* RobotMap::slideFrontMotor1 = NULL;
CANTalon* RobotMap::slideFrontMotor2 = NULL;
CANTalon* RobotMap::slideRearMotor = NULL;

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	slideCANJaguar1 = new CANJaguar(2);
	
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    chassisleftFrontMotor = new CANTalon(2);
    chassisleftRearMotor = new CANTalon(3);
    chassisrightFrontMotor = new CANTalon(4);
    chassisrightRearMotor = new CANTalon(5);
    slideFrontMotor1 = new CANTalon(6);
    slideFrontMotor2 = new CANTalon(7);
    slideRearMotor = new CANTalon(8);

    chassisRobotDrive = new RobotDrive(chassisleftFrontMotor, chassisleftRearMotor,
                  chassisrightFrontMotor, chassisrightRearMotor);

    //chassisRobotDrive->SetSafetyEnabled(true);
    //chassisRobotDrive->SetExpiration(0.1);
    //chassisRobotDrive->SetSensitivity(0.5);
    //chassisRobotDrive->SetMaxOutput(1.0);

//    chassisrobotDrive = new RobotDrive(chassisleftFrontMotor, chassisleftRearMotor,
//    					chassisrightFrontMotor, chassisrightRearMotor);

}
