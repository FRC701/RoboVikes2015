#include "Delay.h"

// For testing purposes:
#include "SmartDashboard/SmartDashboard.h"

Delay::Delay(double delayTime)
: mDelayTime(delayTime)
, counter(0)
, mTimer()
{
}

void Delay::Initialize()
{
	counter = 0;
	// if (mDelayTime < 0.0)
		//mDelayTime = Robot::prefs->GetDouble("autoGrabContainersDelay", 0.3);

	//mTimer.Start();
}

void Delay::Execute()
{
	counter = counter + 1;
	// Do nothing but delay
}

bool Delay::IsFinished()
{
	bool isDone = false;
	if(mDelayTime <= counter)
		isDone = true;
	return isDone;


	//return mTimer.HasPeriodPassed(mDelayTime);
}

void Delay::End()
{
	counter = 0;
	//mTimer.Stop();
	//mTimer.Reset();
}

void Delay::Interrupted()
{
	counter = 0;
	//mTimer.Stop();
	//mTimer.Reset();
}
