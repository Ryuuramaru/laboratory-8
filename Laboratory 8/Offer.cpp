#include "Offer.h"
#include <string>
#include <iostream>

using namespace std;




Offer::Offer() {
	this->departureLocation = "";
	this->id = "";
	this->destinationLocation = "";
	this->price = 0;
	this->startDate = 0;
	this->endDate = 0;
	this->type = o_type::circuit;
}

Offer::Offer(std::string id, std::string departureLocation,
	std::string destinatioLocation, unsigned int price,
	unsigned int startDate, unsigned int endDate, o_type type) {
	this->departureLocation = departureLocation;
	this->id = id;
	this->destinationLocation = destinatioLocation;
	this->price = price;
	this->startDate = startDate;
	this->endDate = endDate;
	this->type = type;
}

Offer::~Offer() {
	this->id = "";
	this->departureLocation = "";
	this->destinationLocation = "";
	this->price = 0;
	this->startDate = 0;
	this->endDate = 0;
	this->type = o_type::circuit;
}

string Offer::getId() {
	return this->id;
}

string Offer::getDepartureLocation() {
	return this->departureLocation;
}

string Offer::getDestinationLocation() {
	return this->destinationLocation;
}

unsigned int Offer::getPrice() {
	return this->price;
}

unsigned int Offer::getStartDate() {
	return this->startDate;
}

unsigned int Offer::getEndDate() {
	return this->endDate;
}

o_type Offer::getType() {
	return this->type;
}

void Offer::setId(std::string s) {
	this->id = s;
}

void Offer::setDepartureLocation(std::string s) {
	this->departureLocation = s;
}

void Offer::setDestinationLocation(std::string s) {
	this->destinationLocation = s;
}

void Offer::setPrice(unsigned int x) {
	this->price = x;
}

void Offer::setStartDate(unsigned int x) {
	this->startDate = x;
}

void Offer::setEndDate(unsigned int x) {
	this->endDate = x;
}

void Offer::setType(o_type type) {
	this->type = type;
}

ostream& operator<<(std::ostream& out, Offer& offer) {
	out << "Offer " << offer.getId() << " from " << offer.getDepartureLocation() << " to "
		<< offer.getDestinationLocation() << " with price " << offer.getPrice()
		<< ".\nStarts at " << offer.getStartDate() << " and ends at " << offer.getEndDate() << ".\n";
	o_type type = offer.getType();
	switch (type) {
	case o_type::citybreak: {
		out << "Citybreak.\n";
		break;
	}
	case o_type::circuit: {
		out << "Circuit.\n";
		break;
	}
	case o_type::cruise: {
		out << "Cruise.\n";
		break;
	}
	case o_type::allinclusive: {
		out << "All-inclusive.\n";
		break;
	}
	}

	return out;
}