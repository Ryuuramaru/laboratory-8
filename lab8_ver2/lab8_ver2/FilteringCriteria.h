#pragma once

#include "DynamicArray.h"

DynamicArray<Offer>;

// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& arr) = 0;
};

class FilteringPrice : public FilteringCriteria {
public:
	FilteringPrice();
	FilteringPrice(unsigned int price);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	unsigned int price;
};

class FilteringType : public FilteringCriteria {
public:
	FilteringType();
	FilteringType(o_type type);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	o_type type;
};

class FilteringDeparture : public FilteringCriteria
{
public:
	FilteringDeparture();
	FilteringDeparture(std::string departure);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	std::string departure;
};
