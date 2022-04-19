#include "FilteringCriteria.h"

DynamicArray<Offer> FilteringCriteria::filter(DynamicArray<Offer>& other)
{
	return other;
}

FilteringPrice::FilteringPrice(unsigned int price)
{
	this->price = price;
}
FilteringPrice::FilteringPrice()
{
	this->price = 0;
}
FilteringDeparture::FilteringDeparture(std::string departure)
{
	this->departure = departure;
}
FilteringDeparture::FilteringDeparture()
{
	this->departure = "";
}
FilteringType::FilteringType(o_type type)
{
	this->type = type;
}
FilteringType::FilteringType()
{
	this->type = o_type::circuit;
}
DynamicArray<Offer> FilteringPrice::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getPrice() < price)
			filteredData.append(data.get(i));
	return filteredData;
}

DynamicArray<Offer> FilteringType::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getType() == type)
			filteredData.append(data.get(i));
	return filteredData;
}

DynamicArray<Offer> FilteringDeparture::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> filteredData;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getDepartureLocation() == departure)
			filteredData.append(data.get(i));
	return filteredData;
}