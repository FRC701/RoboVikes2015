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

// Red, Green, Refactor

TEST(MovingAverage, average_with_no_samples)
{
	// Arrange
	MovingAverage average(1);
	// Act
	average.push(3.0);
	double result = average.returnAverage();
	// Assert
	EXPECT_EQ(0.0, result);
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
}

int main(int argc, char **argv) {
	std::cout << ".....................Starting Testing....................." << std::endl;
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	return result;
}
