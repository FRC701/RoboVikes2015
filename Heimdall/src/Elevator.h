

#include "TwoMotorPIDOutput.h"
#include "DoubleSolenoid.h"

class Elevator: public TwoMotorPIDOutput
{
public:
	Elevator(SpeedController* motor1, SpeedController* motor2, DoubleSolenoid* brake);
	void Set(float speed) override;
private:
	DoubleSolenoid* brake;
};
