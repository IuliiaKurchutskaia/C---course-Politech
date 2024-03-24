
#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <cstdarg>

#include <algorithm>
#include <ctype.h>
#include <cctype>
class MyString
{
    char* m_pStr;   //строка-член класса
    //  int n;
public:


    MyString(); // конструктор без параметров
    MyString(const char* str);// конструктор с параметром
    ///  MyString(char* pStr);   //конструктор с параметром в виде строковой константы
      //MyString();
    MyString(const MyString& other); // конструктор копирования
    ~MyString(); // деструктор
    const char* GetString() const;
    void SetNewString(const char* str);
    /*  void constr(string* arg1, ...);*/
     // MyString(int n_);

    MyString(MyString&& moved) {
        m_pStr = moved.m_pStr;
        moved.m_pStr = nullptr;

    }//???

    MyString& operator=(const char* pStr) {
        delete[] m_pStr;
        m_pStr = new char[strlen(pStr) + 1]; //???
        strcpy_s(m_pStr, strlen(pStr) + 1, pStr);

        return  *this;

    }

    MyString& operator=(const MyString& pStr) {
        if (this != &pStr) {
            delete[] m_pStr;
            m_pStr = new char[strlen(pStr.m_pStr) + 1];
            strcpy_s(m_pStr, strlen(pStr.m_pStr) + 1, pStr.m_pStr);
        }
        return  *this;
    };
    MyString& operator=(MyString&& pStr) {
        delete[] m_pStr;
        m_pStr = pStr.m_pStr;
        pStr.m_pStr = nullptr;

        return  *this;
    };


    MyString constr(const char* arg1, ...);
    friend std::ostream& operator<<(std::ostream& ost, const MyString& str1);


    MyString operator + (const MyString& refPt) {


        char* p = new char[strlen(refPt.m_pStr) + strlen(m_pStr) + 1];

        strcpy_s(p, strlen(refPt.m_pStr) + strlen(m_pStr) + 1, m_pStr);
        strcat(p, refPt.m_pStr);

        MyString tmp(p);
        delete[] p;
        return tmp;
    }



    MyString& operator += (const MyString& refPt) {


        char* p = new char[strlen(refPt.m_pStr) + strlen(m_pStr) + 1];

        strcpy_s(p, strlen(refPt.m_pStr) + strlen(m_pStr) + 1, m_pStr);
        strcat(p, refPt.m_pStr);
        delete[] m_pStr;
        m_pStr = p;
        return *this;

    }

    MyString operator -- (int) {
        MyString tmp(*this);

        for (size_t x = 0; x < strlen(m_pStr); x++)
            m_pStr[x] = tolower(m_pStr[x]);

        return tmp;
    }

    MyString& operator ++ () {

        for (size_t x = 0; x < strlen(m_pStr); x++)
            m_pStr[x] = toupper(m_pStr[x]);

        return *this;
    }

  bool operator < ( const MyString& right) const;
   bool operator > (const MyString& right) const;
   bool operator == (const MyString& right) const;

    friend class Base;
    friend class Pair;
    friend class MyData;





};


