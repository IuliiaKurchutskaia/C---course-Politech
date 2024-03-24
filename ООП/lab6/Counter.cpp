#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Counter.h"
#include <iostream>

using namespace std;

Counter::Counter() // конструктор без параметров
{
    m_pStr = new char[1];
    m_pStr[0] = '\0';
}

Counter::Counter(const char* str)
{
    
}




Counter::Counter(Counter&& moved) {
    m_pStr = moved.m_pStr;
    moved.m_pStr = nullptr;
}

Counter::Counter(const Counter& other)
{
    int size = strlen(other.m_pStr);
    this->m_pStr = new char[size + 1];
    std::cout << strlen(other.m_pStr) << std::endl;
    m_pStr[strlen(m_pStr)] = '\0';

    strcpy_s(m_pStr, strlen(other.m_pStr),other.m_pStr);
}

Counter::~Counter()
{
    delete[] m_pStr;
}

std::ostream& operator<<(std::ostream& ost, Counter& str1) {
   return  ost <<  str1.m_pStr << endl;
};
