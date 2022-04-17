#pragma once
typedef enum
{
	Test_Operators,
	Arr_Getters,
	Test_Append,
	Test_Pop,
	Test_Remove,
	Test_Get
} TestCases;

class DynamicArrayTest
{
public:
	static void runAllTests();
	static void run_test(TestCases test);
};

