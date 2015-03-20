/*
 * DataTables.h
 *
 *  Created on: Mar 20, 2015
 *      Author: computer
 */

#ifndef SRC_DATATABLES_H_
#define SRC_DATATABLES_H_


struct autoStrafeData
{
	double driveDistance;
	double timeForTimeout;
	double encoderSafetyTimeout; // maximum amount of time the encoder
	                             // can go without changing
};

std::vector<autoStrafeData> getAutoStrafeData();


#endif /* SRC_DATATABLES_H_ */
