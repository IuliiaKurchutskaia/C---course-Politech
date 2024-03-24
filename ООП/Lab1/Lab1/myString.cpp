
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.


MyString::MyString() // конструктор без параметров
{
    m_pStr = nullptr;

}

MyString::MyString(const char* str)// конструктор с параметрами
{
    //m_pStr = const_cast<char*>(str);
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
}

MyString::MyString(const MyString& other) // копирующий конструктор 
{
    if (other.m_pStr) {
        int size = strlen(other.m_pStr);
        this->m_pStr = new char[size + 1];
        strcpy(m_pStr, other.m_pStr);

        /*for (int i = 0; i < size; i++)
        {
            this->m_pStr[i] = other.m_pStr[i];
        }
        this->m_pStr[size] = '\0';*/
    }
    else {
        m_pStr = nullptr;
    }
}

// Определение деструктора.

MyString::~MyString()// деструктор
{
    delete[] m_pStr;
}

const char* MyString::GetString() const
{
    if (m_pStr == nullptr) {
        return "";
    }
    return m_pStr;
}



void MyString::SetNewString(const char* str) {
    //m_pStr = const_cast<char*>(str);
    delete[] m_pStr;
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
};
// Определение деструктора.


