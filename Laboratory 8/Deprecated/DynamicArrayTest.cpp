#include "DynamicArrayTest.h"
#include "DynamicArray.h"
#include <string>
#include <iostream>
#include <cassert>

#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

using namespace std;

void DynamicArrayTest::runAllTests()
{
	cout << CYAN << "Running DynamicArray tests..." << endl;
	cout << "------------------------------------" << endl;
	cout << NC;
	run_test(Test_Operators);
	run_test(Arr_Getters);
	run_test(Test_Append);
	run_test(Test_Pop);
	run_test(Test_Remove);
	run_test(Test_Get);

	cout << GREEN << "All tests passed!" << endl;
	cout << NC;
}
void DynamicArrayTest::run_test(TestCases test)
{
	switch (test)
	{
	case Arr_Getters:
	{
		{
			DynamicArray temp;

			assert(temp.getLength() == 0);
			assert(temp.getCapacity() == 100);
		}
	}
	case Test_Append:
	{
		{
			DynamicArray temp;
			temp.append(Offer());
			assert(temp.getLength() == 1);
		}
	}
	case Test_Operators:
	{
		{
			//=
			DynamicArray temp;
			temp.append(Offer());
			DynamicArray temp2;
			temp2 = temp;
			assert(temp.getLength() == 1);
		}
	}
	case Test_Pop:
	{
		{
			DynamicArray temp;
			temp.append(Offer());
			temp.popBack();
			assert(temp.getLength() == 0);
		}
	}
	case Test_Remove:
	{
		{
			DynamicArray temp;
			temp.append(Offer());
			temp.remove(0);
			assert(temp.getLength() == 0);
		}
	}

	case Test_Get:
	{
		{
			DynamicArray temp;
			temp.append(Offer());
			assert(temp.get(0).getId() == "");
		}
	}

	default:
		break;
	}
}
