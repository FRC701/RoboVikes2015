/*
 * MovingAverage.h
 *
 */

#ifndef MOVINGAVERAGE_H_
#define MOVINGAVERAGE_H_

#include <cstddef>
#include <deque>

class MovingAverage {
public:
	explicit MovingAverage(size_t size);
	double	returnSize();
	double returnAverage() const;
	double returnSum();
	void sumOfValues();
	void push(double value);
	double returnIndex(int index);
private:
	size_t maxSize;
	std::deque<double> values;
	double sum;
};

#endif /* MOVINGAVERAGE_H_ */
