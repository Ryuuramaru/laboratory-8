#include "FilteringTest.h"
#include "DynamicArray.h"
#include "FilteringCriteria.h"
#include <string>
#include <iostream>
#include <cassert>

#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

using namespace std;

void FilteringTest::runAllTests()
{
	cout << CYAN << "Running Filtering tests..." << endl;
	cout << "------------------------------------" << endl;
	cout << NC;
	run_test(Filter_Price);
	run_test(Filter_Type);
	run_test(Filter_PriceAndType);
	cout << GREEN << "All tests passed!" << endl;
	cout << NC;
}

void FilteringTest::run_test(FilteringCases test)
{
	switch (test)
	{
	case Filter_Price:
	{
		DynamicArray temp; DynamicArray temp2;
		temp.append(Offer());
		temp.append(Offer());
		temp.append(Offer());
		temp.get(0).setPrice(1);
		temp.get(1).setPrice(2);
		temp.get(2).setPrice(1);
		temp2 = FilteringPrice::filter(temp, 2);
		cout << temp2.getLength();
		assert(temp2.getLength() == 2);
	}
	case Filter_Type:
	{
		DynamicArray temp;
		temp.append(Offer());
		temp.append(Offer());
		temp.append(Offer());
		temp.get(0).setType(citybreak);
		temp.get(1).setType(citybreak);
		temp = FilteringType::filter(temp, citybreak);
		assert(temp.getLength() == 2);
	}
	case Filter_PriceAndType:
	{
		DynamicArray temp;
		temp.append(Offer());
		temp.append(Offer());
		temp.append(Offer());
		temp.get(0).setType(citybreak);
		temp.get(1).setType(citybreak);
		temp.get(0).setPrice(1);
		temp.get(1).setPrice(10);
		temp = FilteringCriteriaTypeAndPrice::filter(temp, 5, citybreak);
		assert(temp.getLength() == 1);
	}
	default:
		break;
	}
}
