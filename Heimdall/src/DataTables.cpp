/*
 * DataTables.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: computer
 */


#include "DataTables.h"
#include "autoStrafe.h"

std::vector<autoStrafeData> getAutoStrafeData()
{
	std::vector<autoStrafeData> data;

	data[autoStrafe::noneSpecified].driveDistance = 0.0;
	data[autoStrafe::noneSpecified].timeForTimeout = 0.0;
	data[autoStrafe::noneSpecified].encoderSafetyTimeout = 0.0;

	return data;
}
