#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"

#include <iostream>
using namespace std;

#include "DynamicArray.h"

void displayMenu() {
}

int main() {

	OfferTest::runAllTests();
	FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	DynamicArray arr;
	arr.append("DynamicArray class");
	arr.append("NOT");
	arr.append("tested");
	
	cout << arr << endl;
	
	displayMenu();
	
	return 0;
}