#pragma once

#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringCriteria.h"

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
