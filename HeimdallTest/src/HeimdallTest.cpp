//============================================================================
// Name        : HeimdallTest.cpp
// Author      : KillerAsuna
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "gtest/gtest.h"


#include "MovingAverage.h"
#include "Integrator.h"
#include "Accelerometer.h"

// Red, Green, Refactor

TEST(MovingAverage, average_of_none)
{
	// Arrange
	MovingAverage average(3);
	// Act
	double result = average.returnAverage();
	// Assert
	EXPECT_EQ(0.0, result);
}

TEST(MovingAverage, average_of_1)
{
	// Arrange
	MovingAverage average(1);
	// Act
	average.push(3.0);
	double result = average.returnAverage();
	// Assert
	EXPECT_EQ(3.0, result);
}

TEST(MovingAverage, sum_of_values)
{
	// Arrange
	MovingAverage average(1);
	average.push(1.0);

	// Act
	double result = average.returnSum();

	// Assert
	EXPECT_EQ(1.0, result);
}

TEST(MovingAverage, average_of_less_than)
{
	// Arrange
	MovingAverage average(5);
	// Act
	average.push(3.0);
	average.push(5.0);
	average.push(7.0);
	double result = average.returnAverage();
	// Assert
	EXPECT_EQ(5.0, result);
}

TEST(MovingAverage, average_of_3)
{
	// Arrange
	MovingAverage average(3);
	// Act
	average.push(3.0);
	average.push(5.0);
	average.push(7.0);
	double result = average.returnAverage();
	// Assert
	EXPECT_EQ(5.0, result);
}

TEST(MovingAverage, pushing_more_average_then_buffer)
{
	// Arrange
	MovingAverage average(3);
	// Act
	for(double x = 1; x < 10; x++)
		average.push(x);
	double result = average.returnSize();

	// Assert
	EXPECT_EQ(3, result);
	EXPECT_EQ(8, average.returnAverage());
}

//.........................................Integrator......................................

TEST(Integrator, integrating_one_values)
{
	// Arrange
	Integrator integrator;
	// Act
	integrator.push(1);
	double result = integrator.get();
	// Assert
	EXPECT_EQ(0.5, result);
}

TEST(Integrator, integrating_two_values)
{
	// Arrange
	Integrator integrator;
	// Act
	integrator.push(1);
	integrator.push(2);
	double result = integrator.get();
	// Assert
	EXPECT_EQ(2.0, result);
}

TEST(Integrator, integrating_no_values)
{
	// Arrange
	Integrator integrator;
	// Act
	double result = integrator.get();
	// Assert
	EXPECT_EQ(0.0, result);
}

TEST(Integrator, integrating_test_rest_values)
{
	// Arrange
	Integrator integrator;
	// Act
	integrator.push(1);
	integrator.push(2);
	double result = integrator.get();
	// Assert
	EXPECT_EQ(2.0, result);
	integrator.reset();
	result = integrator.get();
	EXPECT_EQ(0.0, result);
}

//.........................................Accelerometer......................................

TEST(Accelerometer, Accelerometer_GetAccel_GetVel_GetPos_no_values)
{
	// Arrange
	Accelerometer heimAccel;
	// Act
	double result = heimAccel.getAcceleration();
	// Assert
	EXPECT_EQ(0.0, result);
	result = heimAccel.getVelocity();
	// Assert
	EXPECT_EQ(0.0, result);
	result = heimAccel.getPositiion();
	// Assert
	EXPECT_EQ(0.0, result);
}

TEST(Accelerometer, Accelerometer_GetAccel_GetVel_GetPos_one_value)
{
	// Arrange
	Accelerometer heimAccel(1,1);
	// Act
	heimAccel.push(0.1);
	heimAccel.stopFeedingCompensator();
	heimAccel.push(1.1);
	double result = heimAccel.getAcceleration();
	EXPECT_EQ(1.0, result);

	result = heimAccel.getVelocity();
	EXPECT_EQ(0.5, result);

	result = heimAccel.getPositiion();
	EXPECT_EQ(0.25, result);
	heimAccel.reset();
}

TEST(Accelerometer, Accelerometer_GetAccel_GetVel_GetPos_two_value)
{
	// Arrange
	Accelerometer heimAccel(1,1);
	// Act
	heimAccel.push(0.1);
	heimAccel.stopFeedingCompensator();
	heimAccel.push(1.1);
	heimAccel.push(2.1);
	double result = heimAccel.getAcceleration();
	// Assert
	EXPECT_EQ(2, result);
	result = heimAccel.getVelocity();
	// Assert
	EXPECT_EQ(2, result);
	result = heimAccel.getPositiion();
	// Assert
	EXPECT_EQ(1.5, result);
}

TEST(Accelerometer, Accelerometer_GetAccel_GetVel_GetPos_five_value)
{
	// Arrange
	Accelerometer heimAccel(1,1);
	// Act
	heimAccel.push(0.1);
	heimAccel.stopFeedingCompensator();
	heimAccel.reset();
	heimAccel.push(1);
	heimAccel.push(2);
	heimAccel.push(3);
	heimAccel.push(4);
	heimAccel.push(5);
	double result = heimAccel.getAcceleration();
	// Assert
	EXPECT_EQ(5, result);
	result = heimAccel.getVelocity();
	// Assert
	EXPECT_EQ(12.5, result);
	result = heimAccel.getPositiion();
	// Assert
	EXPECT_EQ(21.25, result);
}

TEST(Accelerometer, Accelerometer_Compensator)
{
	// Arrange
	Accelerometer heimAccel(3,1);
	// Act
	heimAccel.push(1.1);
	heimAccel.push(0.9);
	heimAccel.push(1);
	heimAccel.stopFeedingCompensator();
	heimAccel.push(2);
	heimAccel.push(3);
	heimAccel.push(4);
	heimAccel.push(5);
	heimAccel.push(6);
	double result = heimAccel.getAcceleration();
	// Assert
	EXPECT_EQ(5, result);
	result = heimAccel.getVelocity();
	// Assert
	EXPECT_EQ(12.4, result);
	result = heimAccel.getPositiion();
	// Assert
	EXPECT_EQ(20.65, result);
}

TEST(Accelerometer, Accelerometer_Sampler)
{
	// Arrange
	Accelerometer heimAccel(3,3);
	// Act
	heimAccel.push(1.1);
	heimAccel.push(0.9);
	heimAccel.push(1);
	heimAccel.stopFeedingCompensator();
	heimAccel.push(2);
	heimAccel.push(3);
	heimAccel.push(4);
	heimAccel.push(5);
	heimAccel.push(6);
	heimAccel.push(7);
	double result = heimAccel.getAcceleration();
	// Assert
	EXPECT_EQ(5, result);
	result = heimAccel.getVelocity();
	// Assert
	EXPECT_EQ(12.8, result);
	result = heimAccel.getPositiion();
	// Assert
	EXPECT_EQ(22.75, result);
}

int main(int argc, char **argv) {
	std::cout << ".....................Starting Testing....................." << std::endl;
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	return result;
}
