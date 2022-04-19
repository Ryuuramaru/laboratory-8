#pragma once

#include <string>

enum class o_type {
    circuit,
    citybreak,
    cruise,
    allinclusive
};

class Offer {
public:
    Offer(); // default
    Offer(std::string id, std::string departureLocation,
          std::string destinatioLocation, unsigned int price,
          unsigned int startDate, unsigned int endDate, o_type type);

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
    void setId(std::string s);

    void setDepartureLocation(std::string s);

    void setDestinationLocation(std::string s);

    void setPrice(unsigned int x);

    void setStartDate(unsigned int x);

    void setEndDate(unsigned int x);

    void setType(o_type type);

    // bool operator==(Offer other);
    friend std::ostream &operator<<(std::ostream &out, Offer &offer);

private:
    std::string id, departureLocation, destinationLocation;
    unsigned int price, startDate, endDate;
    o_type type;
};

