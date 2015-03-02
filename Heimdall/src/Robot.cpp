// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/haySqueezerOpen.h"
#include "Commands/PneIntakeOut.h"
#include "Commands/autoContainer.h"
#include "Commands/autoDriveIntoZone.h"
#include "Commands/autoOneTote.h"
#include "PowerDistributionPanel.h"


Preferences* Robot::prefs = 0;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Chassis* Robot::chassis = 0;
Intake* Robot::intake = 0;
PneIntake* Robot::pneIntake = 0;
HaySqueezer* Robot::haySqueezer = 0;
Spool* Robot::spool = 0;
Lights* Robot::lights = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	PDP = new PowerDistributionPanel();
	prefs = Preferences::GetInstance();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	chassis = new Chassis();
	intake = new Intake();
	pneIntake = new PneIntake();
	haySqueezer = new HaySqueezer();
	spool = new Spool();
	lights = new Lights();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	accel = new BuiltInAccelerometer(Accelerometer::kRange_4G);
	// add the multiple autonomous modes to the sendable chooser
//Autos......................................................................................
	autonomousModeChooser = new SendableChooser();
	autonomousModeChooser->AddDefault("AutoDriveIntoZone", new autoDriveIntoZone());
	autonomousModeChooser->AddObject("AutoOneTote", new autoOneTote());
	autonomousModeChooser->AddObject("AutoContainer", new autoContainer());

	SmartDashboard::PutData("Autonomous modes", autonomousModeChooser);

//StartUp....................................................................................

	haySqueezer->haySqueezerSolenoid->Set(DoubleSolenoid::kReverse);
	pneIntake->intakeSolenoid->Set(DoubleSolenoid::kReverse);
	spool->breakSolenoid->Set((DoubleSolenoid::kForward));
	//lights->featureLights->Set(Relay::kForward);

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();

	Robot::chassis->leftFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);
	Robot::chassis->leftRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);
	Robot::chassis->rightFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);
	Robot::chassis->rightRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);

	Robot::spool->spoolLeftMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);
	Robot::spool->spoolRightMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);

	Robot::intake->intakeLeftMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);
	Robot::intake->intakeRightMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Jumper);

}

void Robot::AutonomousInit() {
	// instantiate the command used for the autonomous period
	Robot::spool->spoolLeftMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::spool->spoolRightMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);

	Robot::chassis->leftFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->leftRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->rightFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->rightRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);

	autonomousCommand = (Command*) (autonomousModeChooser->GetSelected());

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	Robot::spool->spoolLeftMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::spool->spoolRightMotor->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);

	Robot::chassis->leftFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->leftRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->rightFront->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	Robot::chassis->rightRear->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);

	//chassis->stopFeedingCompensator();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
// Built in Accelerometer..............................................................................
	if(Robot::prefs->GetBoolean("debug", false))
	{

		SmartDashboard::PutNumber("Accelerometer: X", accel->GetX());
		SmartDashboard::PutNumber("Accelerometer: Y", accel->GetY());
		SmartDashboard::PutNumber("Accelerometer: Z", accel->GetZ());
		/*
		SmartDashboard::PutNumber("Acceleration X", 	chassis->accelerometerX->getAcceleration());
		SmartDashboard::PutNumber("Velocity X", 	chassis->accelerometerX->getVelocity());
		SmartDashboard::PutNumber("Position X", 	chassis->accelerometerX->getPosition());

		SmartDashboard::PutNumber("Acceleration Y", 	chassis->accelerometerY->getAcceleration());
		SmartDashboard::PutNumber("Velocity Y", 	chassis->accelerometerY->getVelocity());
		SmartDashboard::PutNumber("Position Y", 	chassis->accelerometerY->getPosition());

		SmartDashboard::PutNumber("Compensation X", chassis->accelerometerX->getCompensation());
		SmartDashboard::PutNumber("Compensation Y", chassis->accelerometerY->getCompensation());
		*/
	//PDP.....................................................................................................
		SmartDashboard::PutNumber("Right Plot Motor", PDP->GetCurrent(12));
		SmartDashboard::PutNumber("Left Plot Motor", PDP->GetCurrent(3));
		SmartDashboard::PutNumber("Right Motor", PDP->GetCurrent(12));
		SmartDashboard::PutNumber("Left Motor", PDP->GetCurrent(3));
	//Talons Current...............................................................................................
		SmartDashboard::PutNumber("Spool Left Motor", Robot::spool->spoolLeftMotor->GetOutputCurrent());
		SmartDashboard::PutNumber("Spool Right Motor",  Robot::spool->spoolRightMotor->GetOutputCurrent());

		SmartDashboard::PutNumber("Intake Left Motor", Robot::intake->intakeLeftMotor->GetOutputCurrent());
		SmartDashboard::PutNumber("Intake Right Motor",  Robot::intake->intakeRightMotor->GetOutputCurrent());

		SmartDashboard::PutNumber("Chassis Front Left Motor", Robot::chassis->leftFront->GetOutputCurrent());
		SmartDashboard::PutNumber("Chassis Front Right Motor",  Robot::chassis->rightFront->GetOutputCurrent());
		SmartDashboard::PutNumber("Chassis Rear Right Motor", Robot::chassis->rightRear->GetOutputCurrent());
		SmartDashboard::PutNumber("Chassis Rear Left Motor",  Robot::chassis->leftRear->GetOutputCurrent());

	//POV................................................................................................
		SmartDashboard::PutNumber("POV CoDriver", Robot::oi->getcoDriver()->GetPOV());
		SmartDashboard::PutNumber("POV Driver", Robot::oi->getdriver()->GetPOV());
	}
//JoySticks.............................................................................................
	SmartDashboard::PutNumber("Joystick 4 Value", Robot::oi->getcoDriver()->GetRawAxis(4));

//Encoder...............................................................................................
	SmartDashboard::PutNumber("Elevator Encoder", Robot::spool->spoolRightMotor->GetEncPosition());

	SmartDashboard::PutNumber("Forward Encoder", Robot::chassis->leftRear->GetEncPosition());

	SmartDashboard::PutNumber("Strafing Encoder", Robot::chassis->rightRear->GetEncPosition());


	SmartDashboard::PutNumber("Encoder Vel", Robot::chassis->rightFront->GetEncVel());
	SmartDashboard::PutNumber("Forward Limit Switch", Robot::chassis->rightFront->IsFwdLimitSwitchClosed());
	SmartDashboard::PutNumber("Starting Encoder Value", Robot::oi->encoderStartingValue);
//LightSensor............................................................................................
	SmartDashboard::PutBoolean("Left LightSensor", Robot::chassis->leftLightSensor->Get());
	SmartDashboard::PutBoolean("Right LightSensor", Robot::chassis->rightLightSensor->Get());

	SmartDashboard::PutBoolean("Left HaySqueezer", Robot::haySqueezer->leftPneSensor->Get());
	SmartDashboard::PutBoolean("Right HaySqueezer", Robot::haySqueezer->rightPneSensor->Get());

	SmartDashboard::PutBoolean("UserButton", GetUserButton());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

