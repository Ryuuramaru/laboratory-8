#pragma once

#include "DynamicArray.h"
#include "Offer.h"

DynamicArray<Offer>;

// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& arr) = 0;
};

class FilteringPrice : public FilteringCriteria {
public:
	FilteringPrice(unsigned int price);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	unsigned int price;
};

class FilteringType : public FilteringCriteria {
public:
	FilteringType(o_type type);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	o_type type;
};

class FilteringDeparture : public FilteringCriteria
{
public:
	FilteringDeparture(std::string departure);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);

private:
	std::string departure;
};


template <typename Criteria1, typename Criteria2>
class FilteringCriteriaAnd : public FilteringCriteria
{
public:
	FilteringCriteriaAnd(Criteria1 criteria1, Criteria2 criteria2)
	{
		this->crt1 = criteria1;
		this->crt2 = criteria2;
	}
	DynamicArray<Offer> filter(DynamicArray<Offer>& data)
	{
		DynamicArray<Offer> temp = crt1.filter(data);
		temp = crt2.filter(temp);
		return temp;
	}

private:
	Criteria1 crt1;
	Criteria2 crt2;
};
