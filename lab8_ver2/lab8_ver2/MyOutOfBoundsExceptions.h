#pragma once
#include <exception>

class MyOutOfBoundsexceptions : public std::exception
{
public:
	MyOutOfBoundsexceptions();
	MyOutOfBoundsexceptions(int lowerBound, int upperBound);

private:
	const char* what() const throw();
	int lowerBound;
	int upperBound;
	int index;
};
