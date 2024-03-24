#pragma once
#include "MyString.h"
class CountersList
{
public:
	Counter* m_pHead;
	unsigned int m_curCounters=0;
	Counter* addString(const char* str);
	
};

