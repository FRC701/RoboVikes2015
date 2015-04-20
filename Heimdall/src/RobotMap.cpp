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
DigitalInput* RobotMap::chassisleftLightSensor = NULL;
DigitalInput* RobotMap::chassisrightLightSensor = NULL;
Ultrasonic* RobotMap::chassisrightUltra = NULL;
Ultrasonic* RobotMap::chassisleftUltra = NULL;
DoubleSolenoid* RobotMap::pneIntakeintakeSolenoid = NULL;
DoubleSolenoid* RobotMap::haySqueezerhaySqueezerSolenoid = NULL;
DigitalInput* RobotMap::haySqueezerrightPneSensor = NULL;
DigitalInput* RobotMap::haySqueezerleftPneSensor = NULL;
DoubleSolenoid* RobotMap::spoolbreakSolenoid = NULL;
Relay* RobotMap::lightsfeatureLights = NULL;
Relay* RobotMap::lightsSpike2 = NULL;
Relay* RobotMap::lightsSpike3 = NULL;
DoubleSolenoid* RobotMap::canGrabberscanGrabbersSolenoid = NULL;

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

	chassisleftLightSensor = new DigitalInput(0);
	lw->AddSensor("Chassis", "leftLightSensor", chassisleftLightSensor);
	
	chassisrightLightSensor = new DigitalInput(1);
	lw->AddSensor("Chassis", "rightLightSensor", chassisrightLightSensor);
	
	chassisrightUltra = new Ultrasonic(6, 7);
	lw->AddSensor("Chassis", "rightUltra", chassisrightUltra);
	
	chassisleftUltra = new Ultrasonic(4, 5);
	lw->AddSensor("Chassis", "leftUltra", chassisleftUltra);
	
	pneIntakeintakeSolenoid = new DoubleSolenoid(0, 0, 7);      
	lw->AddActuator("PneIntake", "intakeSolenoid", pneIntakeintakeSolenoid);
	
	haySqueezerhaySqueezerSolenoid = new DoubleSolenoid(0, 1, 6);      
	lw->AddActuator("HaySqueezer", "haySqueezerSolenoid", haySqueezerhaySqueezerSolenoid);
	
	haySqueezerrightPneSensor = new DigitalInput(2);
	lw->AddSensor("HaySqueezer", "rightPneSensor", haySqueezerrightPneSensor);
	
	haySqueezerleftPneSensor = new DigitalInput(3);
	lw->AddSensor("HaySqueezer", "leftPneSensor", haySqueezerleftPneSensor);
	
	spoolbreakSolenoid = new DoubleSolenoid(0, 2, 5);      
	lw->AddActuator("Spool", "breakSolenoid", spoolbreakSolenoid);
	
	lightsfeatureLights = new Relay(0);
	lw->AddActuator("Lights", "featureLights", lightsfeatureLights);
	
	lightsSpike2 = new Relay(1);
	lw->AddActuator("Lights", "Spike 2", lightsSpike2);
	
	lightsSpike3 = new Relay(2);
	lw->AddActuator("Lights", "Spike 3", lightsSpike3);
	
	canGrabberscanGrabbersSolenoid = new DoubleSolenoid(0, 3, 4);      
	lw->AddActuator("CanGrabbers", "canGrabbersSolenoid", canGrabberscanGrabbersSolenoid);
	


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	intakeLeftMotor = new CANTalon(8);
	intakeRightMotor = new CANTalon(7);

	spoolLeftMotor = new CANTalon(2);
    spoolRightMotor = new CANTalon(4);
    spoolRightMotor->SetSensorDirection(true);

    chassisleftFrontMotor = new CANTalon(5);
    chassisleftRearMotor = new CANTalon(11);
    chassisrightFrontMotor = new CANTalon(6);
    chassisrightRearMotor = new CANTalon(12);

    chassisRobotDrive = new RobotDrive(chassisleftFrontMotor, chassisleftRearMotor,
                  chassisrightFrontMotor, chassisrightRearMotor);

    chassisRobotDrive->SetSafetyEnabled(false);
    //chassisRobotDrive->SetExpiration(0.1);
    chassisRobotDrive->SetSensitivity(0.5);
    chassisRobotDrive->SetMaxOutput(1.0);

}
