//
// Created by user on 12.04.2022.
//
#include "FilteringCriteria.h"

class FilteringCriteriaAnd: public FilteringCriteria {
private:
    FilteringCriteria *crt1;
    FilteringCriteria *crt2;
public:
    FilteringCriteriaAnd();

    FilteringCriteriaAnd(FilteringCriteria *crt1, FilteringCriteria *crt2);

    DynamicArray<Offer> filter(DynamicArray<Offer> &arr);

};

