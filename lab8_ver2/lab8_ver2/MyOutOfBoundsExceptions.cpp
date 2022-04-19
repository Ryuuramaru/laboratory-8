#include "MyOutOfBoundsExceptions.h"
#include <string>

const char* MyOutOfBoundsexceptions::what() const throw()
{
    std::string msg = "Out of bound: upper bound " + std::to_string(this->upperBound)   
        + " lower bound " + std::to_string(this->lowerBound);
    return msg.c_str();
}
