#include "FilteringCriteria.h"

DynamicArray FilteringCriteria::filter(DynamicArray &other)
{
    return data;
}

DynamicArray FilterByPrice::filter(DynamicArray &data)
{
    DynamicArray filteredData;
    for (int i = 0; i < data.getLength(); i++)
}

DynamicArray FilterByType::filter(DynamicArray &data)
{
    DynamicArray filteredData;
}