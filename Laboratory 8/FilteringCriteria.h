#pragma once
#include "DynamicArray.h"

// you can add all your filtering classes in this module
class FilteringCriteria
{
    DynamicArray filter(DynamicArray &data);
};

class FilterByPrice : public FilteringCriteria
{
public:
    DynamicArray filter(DynamicArray &data);

private:
    unsigned int price;
};

class FilterByType : public FilteringCriteria
{
public:
    DynamicArray filter(DynamicArray &data);

private:
    unsigned int price;
};

