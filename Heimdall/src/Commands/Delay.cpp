#include "Delay.h"

// For testing purposes:
#include "SmartDashboard/SmartDashboard.h"

Delay::Delay(double delayTime)
: mDelayTime(delayTime)
, mTimer()
{
}

void Delay::Initialize()
{
	if (mDelayTime < 0.0)
		mDelayTime = Robot::prefs->GetDouble("autoGrabContainersDelay", 0.3);

	mTimer.Start();
}

void Delay::Execute()
{
	// Do nothing but delay
}

bool Delay::IsFinished()
{
	return mTimer.HasPeriodPassed(mDelayTime);
}

void Delay::End()
{
	mTimer.Stop();
	mTimer.Reset();
}

void Delay::Interrupted()
{
	mTimer.Stop();
	mTimer.Reset();
}
