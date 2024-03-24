#pragma once
#define _CRT_SECURE_NO_WARNINGS
class MyString
{
    char* m_pStr;   //строка-член класса

public:


    MyString(); // конструктор без параметров
    MyString(const char* str);// конструктор с параметром
    MyString(const MyString& other); // конструктор копирования
    ~MyString(); // деструктор
    const char* GetString() const;
    void SetNewString(const char* str);
};
