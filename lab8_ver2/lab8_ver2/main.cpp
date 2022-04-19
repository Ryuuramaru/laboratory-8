#include <iostream>
using namespace std;

#include "FilteringCriteriaAnd.h"

void displayMenu()
{
	cout << endl
		<< "Please select your option:\n";
	cout << " A|a - Add offer\n S|s - Show offers\n P|p - Filter by price\n";
	cout << " T|t - Filter by type\n D|d - Filter by Departure Location\n";
	cout << " B | b - Filter by any two criteria\n Q | q - Quit\n";
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
			type = o_type::circuit;
			break;
		case 2:
			type = o_type::citybreak;
			break;
		case 3:
			type = o_type::cruise;
			break;
		case 4:
			type = o_type::allinclusive;
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

int main(int argc, char* argv[])
{
	DynamicArray<Offer> arr;
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
			break;
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
			FilteringPrice flr = FilteringPrice(price);
			arr = flr.filter(arr);
			cout << arr << endl;
			break;
		}
		case 't':
		{
			o_type type = selectType();
			FilteringType flr = FilteringType(type);
			arr = flr.filter(arr);
			cout << arr << endl;
			break;
		}
		case 'd':
		{
			std::string ipt;
			cin >> ipt;
			FilteringDeparture flr = FilteringDeparture(ipt);
			arr = flr.filter(arr);
			cout << arr << endl;
			break;
		}
		case 'b':
		{
			cout << "Choose Criteria:\n";
			cout << "1 for price\n";
			cout << "2 for type\n";
			cout << "3 for departure location\n";
			unsigned int ipt1, ipt2;
			cin >> ipt1;
			string deploc;
			unsigned int price;
			o_type type;
			switch (ipt1)
			{
			case 1:
			{
				cout << "Enter price: ";
				cin >> price;
				cout << endl;
				FilteringPrice flr1 = FilteringPrice(price);
				break;
			}
			case 2:
			{
				type = selectType();
				FilteringType flr1 = FilteringType(type);
				break;
			}
			case 3:
			{
				cout << "Enter departure location: ";
				cin >> deploc;
				cout << endl;
				FilteringDeparture flr1 = FilteringDeparture(deploc);
				break;
			}
			default:
			{
				cout << "That's not a valid input!";
				break;
			}
			}

			cin >> ipt2;
			if (ipt2 == ipt1)
			{
				cout << "Why would you choose the same criteria *facepalm*" << endl;
				break;
			}
			switch (ipt2)
			{
			case 1:

				cout << "Enter price: ";
				unsigned int price;
				cin >> price;
				cout << endl;
				break;

			case 2:
			{
				type = selectType();
				break;
			}
			case 3:
			{
				cout << "Enter departure location: ";
				string deploc;
				cin >> deploc;
				cout << endl;
				break;
			}
			default:
			{
				cout << "That's not a valid input!";
				break;
			}
			}
			if (ipt1 == 1)
			{
				FilteringPrice flr1 = FilteringPrice(price);
				if (ipt2 == 2)
				{
					FilteringType flr2 = FilteringType(type);
					FilteringCriteriaAnd<FilteringPrice, FilteringType> flr = FilteringCriteriaAnd<FilteringPrice, FilteringType>(flr1, flr2);
					arr = flr.filter(arr);
				}
				else if (ipt2 == 3)
				{
					FilteringDeparture flr2 = FilteringDeparture(deploc);
					FilteringCriteriaAnd<FilteringPrice, FilteringDeparture> flr = FilteringCriteriaAnd<FilteringPrice, FilteringDeparture>(flr1, flr2);
					arr = flr.filter(arr);
				}
			}
			else if (ipt1 == 2)
			{
				FilteringType flr1 = FilteringType(type);
				if (ipt2 == 1)
				{
					FilteringPrice flr2 = FilteringPrice(price);
					FilteringCriteriaAnd<FilteringPrice, FilteringType> flr = FilteringCriteriaAnd<FilteringPrice, FilteringType>(flr2, flr1);
					arr = flr.filter(arr);
				}
				else if (ipt2 == 3)
				{
					FilteringDeparture flr2 = FilteringDeparture(deploc);
					FilteringCriteriaAnd<FilteringType, FilteringDeparture> flr = FilteringCriteriaAnd<FilteringType, FilteringDeparture>(flr1, flr2);
					arr = flr.filter(arr);
				}
			}
			else if (ipt1 == 3)
			{
				FilteringDeparture flr1 = FilteringDeparture(deploc);
				if (ipt2 == 2)
				{
					FilteringType flr2 = FilteringType(type);
					FilteringCriteriaAnd<FilteringDeparture, FilteringType> flr = FilteringCriteriaAnd<FilteringDeparture, FilteringType>(flr1, flr2);
					arr = flr.filter(arr);
				}
				else if (ipt2 == 1)
				{
					FilteringPrice flr2 = FilteringPrice(price);
					FilteringCriteriaAnd<FilteringDeparture, FilteringPrice> flr = FilteringCriteriaAnd<FilteringDeparture, FilteringPrice>(flr1, flr2);
					arr = flr.filter(arr);
				}
			}

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