#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"

#include <iostream>
using namespace std;

#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringCriteria.h"

void displayMenu()
{
	cout << endl
		<< "Please select your option:\n";
	cout << " A|a - Add offer\n S|s - Show offers\n P|p - Filter by price\n";
	cout << " T|t - Filter by type\n B|b - Filter by type and price\n Q|q - Quit\n";
	cout << endl;
}

o_type selectType()
{
	o_type type;
	unsigned int type_input;
	bool run = true;
	cout << endl
		<< "1. circuit\n2. citybreak\n3. cruise\n4. all-inclusive\n";
	while (run)
	{
		cin >> type_input;
		run = false;
		switch (type_input)
		{
		case 1:
			type = circuit;
			break;
		case 2:
			type = citybreak;
			break;
		case 3:
			type = cruise;
			break;
		case 4:
			type = allinclusive;
			break;
		default:
			cout << "That's not a valid type!" << endl;
			run = true;
			break;
		}
	}
	cout << endl;
	return type;
}

int main()
{

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	DynamicArray arr;

	char input;
	bool run = true;
	while (run)
	{
		displayMenu();
		cin >> input;
		if (input < 97)
			input += 32;
		switch (input)
		{
		case 'a':
		{
			string id, deploc, desloc;
			unsigned int price, sd, ed;
			o_type type;
			cout << "Enter id: ";
			cin >> id;
			cout << endl
				<< "Enter departure location: ";
			cin >> deploc;
			cout << endl
				<< "Enter destination location: ";
			cin >> desloc;
			cout << endl
				<< "Enter price: ";
			cin >> price;
			cout << endl
				<< "Enter start date: ";
			cin >> sd;
			cout << endl
				<< "Enter end date: ";
			cin >> ed;
			cout << endl;
			type = selectType();
			arr.append(Offer(id, deploc, desloc, price, sd, ed, type));
			// cout << arr << endl;
		}
		case 's':
		{
			cout << arr << endl;
			break;
		}
		case 'p':
		{
			cout << "Enter price: ";
			unsigned int price;
			cin >> price;
			arr = FilteringPrice::filter(arr, price);
			cout << arr << endl;
			break;
		}
		case 't':
		{
			o_type type = selectType();
			arr = FilteringType::filter(arr, type);
			cout << arr << endl;
			break;
		}
		case 'b':
		{
			cout << "Enter price: ";
			unsigned int price;
			cin >> price;
			cout << endl;
			o_type type = selectType();
			arr = FilteringCriteriaTypeAndPrice::filter(arr, price, type);
			cout << arr << endl;
			break;
		}
		case 'q':
		{
			run = false;
			break;
		}
		default:
		{
			cout << "That's not a valid input!" << endl;
			break;
		}
		}
	}
	return 0;
}