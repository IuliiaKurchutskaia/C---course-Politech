#pragma once
#define _CRT_SECURE_NO_WARNINGS
class MyString
{
    char* m_pStr;   //������-���� ������

public:


    MyString(); // ����������� ��� ����������
    MyString(const char* str);// ����������� � ����������
    MyString(const MyString& other); // ����������� �����������
    ~MyString(); // ����������
    const char* GetString() const;
    void SetNewString(const char* str);
};
