#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MyString.h"
#include <iostream>

using namespace std;

// Определение конструктора.


MyString::MyString() // конструктор без параметров
{
  
    m_pStr = new char[1];
    m_pStr[0] = '\0';


}

MyString::MyString(const char* str)// конструктор с параметрами
{
    //m_pStr = const_cast<char*>(str);
    m_pStr = new char[strlen(str) + 1];
    strcpy_s(m_pStr, strlen(str) + 1, str);
}
//MyString::MyString(char*pStr) :m_pStr(new char[strlen(m_pStr) + 1])
//{
//    strcpy(this->m_pStr, pStr);
//}
//MyString::MyString() :m_pStr(new char[1]) { m_pStr[0] = 0; }
MyString::MyString(const MyString& other) // копирующий конструктор 
{

    int size = strlen(other.m_pStr);
    this->m_pStr = new char[size + 1];
    std::cout << strlen(other.m_pStr) << std::endl;
    m_pStr[strlen(m_pStr)] = '\0';

    strcpy_s(m_pStr, strlen(other.m_pStr),other.m_pStr);




}

// Определение деструктора.

MyString::~MyString()// деструктор
{
    delete[] m_pStr;
}

const char* MyString::GetString() const
{


    return m_pStr;
}

//MyString::MyString(int n_) : n(n_) { //конструктор с указанной размерностью
//    m_pStr = new char[n];  //выделяем память - понадобится деструктор для освобождения
//
//}
//MyString::MyString(MyString&& moved)
//{
//
//
//    m_pStr = moved.m_pStr;  // перемещаем текст 
//  
//    moved.m_pStr = nullptr;
//    std::cout << "Move string " <<  std::endl;
//}
void MyString::SetNewString(const char* str) {
    //m_pStr = const_cast<char*>(str);
    delete[] m_pStr;
    m_pStr = new char[strlen(str) + 1];
    strcpy_s(m_pStr, strlen(str) + 1, str);
}






//Задание 9. Создайте глобальную функцию, которая будет принимать любое
    //количество указателей на строки, а возвращать объект MyString,
    //в котором строка будет конкатенацией параметров
//
MyString constr(const char* arg1, ...)
{
    const char** p = &arg1;

    // 


    int number = 0;


    while (*p != 0) {


        number += strlen(*p);
        p++;

    };
    char* pTmp = new char[number + 1] {};
    //MyString tmp;
    //for (int i; i < number; i++) {
    //   // pTmp[i] =+ *p[i];

    //}
    p = &arg1;

    while (*p != 0) {

        strcat(pTmp, *p);
        p++;


    };
    MyString tmp(pTmp);
    delete[] pTmp;
    return tmp;
};

std::ostream& operator<<(std::ostream& ost, const MyString& str1) {
    /*  ost << "string: " << endl << str1.GetString() << endl;
      return ost;*/

    return  ost <<  str1.GetString() << endl;
};
//
//int operator == (const MyString& left, const MyString& right) {
//    return strcmp(left.GetString(), right.GetString()) == 0;
//}
bool MyString::operator == (const MyString& right) const {
    return strcmp(this->GetString(), right.GetString()) == 0;
}

bool MyString::operator < (const MyString& right) const {

    return  strcmp(this->GetString(), right.GetString()) < 0;
}

bool MyString::operator > (const MyString& right) const {

    return  strcmp(this->GetString(), right.GetString()) > 0;
}

