// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef AUTOSTRAFEUNTILYELLOWTOTE_H
#define AUTOSTRAFEUNTILYELLOWTOTE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class autoStrafeUntilYellowTote: public Command {
public:
	autoStrafeUntilYellowTote();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	void detection();
private:
	Timer* lightSensorTimer;
	bool finish;
	int numberOfDetections;
	bool lastLightSensorCondition;
	bool currentLightSensorCondition;
};

#endif
