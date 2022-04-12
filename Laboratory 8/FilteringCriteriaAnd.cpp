#include "FilteringCriteriaAnd.h"

FilteringCriteriaAnd::FilteringCriteriaAnd() {

};

FilteringCriteriaAnd::FilteringCriteriaAnd(FilteringCriteria *crt1, FilteringCriteria *crt2) {
    this->crt1 = crt1;
    this->crt2 = crt2;
}

DynamicArray<Offer> FilteringCriteriaAnd::filter(DynamicArray<Offer> &arr) {

    DynamicArray<Offer> f1 = this->crt2->filter(arr);
    return this->crt2->filter(f1);
}