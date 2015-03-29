// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef AUTOSTRAFE_H
#define AUTOSTRAFE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class autoStrafe: public Command {
public:
	enum Purpose
	{
		noneSpecified, // indicates error
		rightToAvoidContainer,
		leftToAvoidYellowTote,
		leftFromLandfillZone,
	};
public:
	autoStrafe();
	autoStrafe(Purpose purpose, bool distanceBased,
				bool timerBased, bool encoderSafety);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	Purpose mPurpose;

	bool mDistanceBased;
	bool mTimerBased;
	bool mEncoderSafety;

	int mDriveDistance;

	// Handles timeout for the entire command
	Timer mCommandTimeoutTimer;
	double mCommandTimeoutAmount; // required time before timing out

	// Handles timeout for change in encoder value
	Timer mTimeoutForEncoderChangeTimer;
	int mPreviousEncoderReading;
};

#endif
