#include "Elevator.h"
#include <cmath>

Elevator::Elevator(SpeedController* motor1, SpeedController* motor2, DoubleSolenoid* brake)
: TwoMotorPIDOutput(motor1, motor2), brake(brake)
{

}

void Elevator::Set(float speed)
{
	if( std::abs(speed) < 0.15)
	{
		brake->Set(DoubleSolenoid::kReverse);
		TwoMotorPIDOutput::Set(0.0);
	}
	else
	{
		brake->Set(DoubleSolenoid::kForward);
		TwoMotorPIDOutput::Set(speed);
	}
}
