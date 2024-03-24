
#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <cstdarg>

#include <algorithm>

struct Counter
{
    char* m_pStr;   //строка-член класса
    size_t m_nOwners = 0;
    Counter* pNext = nullptr;
    static CountersList m_countersList;
    Counter(); // конструктор без параметров
    Counter(const char* str);// конструктор с параметром
    Counter(const Counter& other); // конструктор копирования
    ~Counter(); // деструктор
    //const char* GetString() ;
    void SetNewString(const char* str);
    Counter(Counter&& moved);

    Counter& operator=(const char* pStr) {
        delete[] m_pStr;
        m_pStr = new char[strlen(pStr) + 1]; //
        strcpy_s(m_pStr, strlen(pStr) + 1, pStr);

        return  *this;

    }

    Counter& operator=(const Counter& pStr) {
        if (this != &pStr) {
            delete[] m_pStr;
            m_pStr = new char[strlen(pStr.m_pStr) + 1];
            strcpy_s(m_pStr, strlen(pStr.m_pStr) + 1, pStr.m_pStr);
        }
        return  *this;
    };
    Counter& operator=(Counter&& pStr) {
        delete[] m_pStr;
        m_pStr = pStr.m_pStr;
        pStr.m_pStr = nullptr;

        return  *this;
    }
       
};


