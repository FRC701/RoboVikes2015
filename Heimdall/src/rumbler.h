
#include"Joystick.h"
#include "Notifier.h"


/*
	Notifier(TimerEventHandler handler, void *param = NULL);
	virtual ~Notifier();
	void StartSingle(double delay);
	void StartPeriodic(double period);
	void Stop();
*/

class Rumbler
{
public:

	typedef Joystick::RumbleType RumbleType;

    Rumbler(Joystick *joystick);

    void start(RumbleType);
    void start(RumbleType, double seconds);
    void stop();

private:
    Joystick* joystick;
    Notifier notifier;

    static void callback(void* param);

};

