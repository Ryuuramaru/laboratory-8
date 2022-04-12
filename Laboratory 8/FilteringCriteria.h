#pragma once
#include "DynamicArray.h"
#include "Offer.h"

// you can add all your filtering classes in this module
class FilteringCriteria
{
	DynamicArray filter(DynamicArray& data);
};

class FilteringPrice : public FilteringCriteria
{
public:
	static DynamicArray filter(DynamicArray& data, unsigned int price);
};

class FilteringType : public FilteringCriteria
{
public:
	static DynamicArray filter(DynamicArray& data, o_type type);
};

class FilteringCriteriaTypeAndPrice : public FilteringCriteria
{
public:
	static DynamicArray filter(DynamicArray& data, unsigned int price, o_type type);
};
