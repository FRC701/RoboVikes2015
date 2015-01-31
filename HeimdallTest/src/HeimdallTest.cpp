//============================================================================
// Name        : HeimdallTest.cpp
// Author      : KillerAsuna
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "gtest/gtest.h"
using namespace std;

TEST(MovingAverage, average)
{
	EXPECT_EQ(1, 0);
}

int main(int argc, char **argv) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	return result;
}
