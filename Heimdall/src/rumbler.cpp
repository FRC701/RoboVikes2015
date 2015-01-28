
#include "rumbler.h"

Rumbler::Rumbler(Joystick *inJoystick)
 : joystick(inJoystick), notifier(callback, this)
{
}

void Rumbler::start(RumbleType type)
{
    joystick->SetRumble(type, 1.0);
}

void Rumbler::start(RumbleType type, double seconds)
{
    notifier.StartSingle(seconds);
    start(type);
}

void Rumbler::stop()
{
    notifier.Stop();
    joystick->SetRumble(Joystick::kLeftRumble, 0.0);
}

void Rumbler::callback (void* param)
{
    Rumbler* rumbler = reinterpret_cast<Rumbler*>(param);
    rumbler->stop();
}

