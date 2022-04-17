#pragma once
typedef enum
{
	Filter_Price,
	Filter_Type,
	Filter_PriceAndType
} FilteringCases;
class FilteringTest
{
public:
	static void runAllTests();
	static void run_test(FilteringCases test);
};

