#pragma once
#include "Offer.h"
typedef enum
{
	Offer_Getters,
	Offer_Setters
} OfferCases;
class OfferTest
{
public:
	static void runAllTests();
	static void run_test(OfferCases test);
};

