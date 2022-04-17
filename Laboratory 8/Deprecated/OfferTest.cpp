#include "OfferTest.h"
#include "Offer.h"
#include <cassert>
#include <iostream>

#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

using namespace std;

void OfferTest::runAllTests()
{
	cout << CYAN << "Running Offer tests..." << endl;
	cout << "------------------------------------" << endl;
	cout << NC;
	run_test(Offer_Getters);
	run_test(Offer_Setters);

	cout << GREEN << "All tests passed!" << endl;
	cout << NC;
}
void OfferTest::run_test(OfferCases test)
{
	switch (test)
	{
	case Offer_Getters:
	{
		{
			Offer temp = Offer();

			assert(temp.getId() == "");
			assert(temp.getDepartureLocation() == "");
			assert(temp.getDestinationLocation() == "");
			assert(temp.getPrice() == 0);
			assert(temp.getStartDate() == 0);
			assert(temp.getEndDate() == 0);
			assert(temp.getType() == circuit);
		}
	}
	case Offer_Setters:
	{
		{
			Offer temp = Offer();
			temp.setId("1");
			temp.setDepartureLocation("Cluj");
			temp.setDestinationLocation("Bucharest");
			temp.setPrice(10);
			temp.setStartDate(10);
			temp.setEndDate(10);
			temp.setType(citybreak);
			assert(temp.getId() == "1");
			assert(temp.getDepartureLocation() == "Cluj");
			assert(temp.getDestinationLocation() == "Bucharest");
			assert(temp.getPrice() == 10);
			assert(temp.getStartDate() == 10);
			assert(temp.getEndDate() == 10);
			assert(temp.getType() == citybreak);
		}
	}
	default:
		break;
	}
}
