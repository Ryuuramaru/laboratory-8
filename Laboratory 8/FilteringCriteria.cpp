#include "FilteringCriteria.h"

DynamicArray FilteringCriteria::filter(DynamicArray &other)
{
    return other;
}

DynamicArray FilteringPrice::filter(DynamicArray &data, unsigned int price)
{
    DynamicArray filteredData;
    for (int i = 0; i < data.getLength(); i++)
        if (data.get(i).getPrice() < price)
            filteredData.append(data.get(i));
    return filteredData;
}

DynamicArray FilteringType::filter(DynamicArray &data, o_type type)
{
    DynamicArray filteredData;
    for (int i = 0; i < data.getLength(); i++)
        if (data.get(i).getType() == type)
            filteredData.append(data.get(i));
    return filteredData;
}

DynamicArray FilteringCriteriaTypeAndPrice::filter(DynamicArray &data, unsigned int price, o_type type)
{
    DynamicArray filteredPrice = FilteringPrice::filter(data, price);
    DynamicArray filteredData = FilteringType::filter(filteredPrice, type);
    return filteredData;
}