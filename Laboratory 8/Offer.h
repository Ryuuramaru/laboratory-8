#pragma once
#include <string>

enum o_type
{
    circuit,
    citybreak,
    cruise,
    allinclusive
};
class Offer
{
public:
    Offer(); // default

    ~Offer(); // yeet-inator

    // getters
    std::string getId();
    std::string getDepartureLocation();
    std::string getDestinationLocation();
    unsigned int getPrice();
    unsigned int getStartDate();
    unsigned int getEndDate();
    o_type getType();

    // setters
    std::string setId(std::string s);
    std::string setDepartureLocation(std::string s);
    std::string setDestinationLocation(std::string s);
    unsigned int setPrice(unsigned int x);
    unsigned int setStartDate(unsigned int x);
    unsigned int setEndDate(unsigned int x);
    o_type setType(o_type type);

private:
    std::string id, departureLocation, destinationLocation;
    unsigned int price, startDate, endDate;
    o_type type;
};

