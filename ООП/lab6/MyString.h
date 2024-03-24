#pragma once
#include "Counter.h"
#include "CountersList.h"
class MyString
{
public:
	static void print();
	static void changeCase();
	static void printAlph();
	const char * getString();

	MyString(const char* str);

private:


	Counter* m_pMyCounter;
};

