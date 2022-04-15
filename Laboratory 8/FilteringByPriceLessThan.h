#pragma once
#include "FilteringCriteria.h"

class FilteringByPriceLessThan: public FilteringCriteria{
private:
    int price;
public:
    FilteringByPriceLessThan(int p);
    DynamicArray<Offer> filter(DynamicArray<Offer>& arr);
};