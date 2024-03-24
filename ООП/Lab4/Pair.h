#pragma once
#include <iostream>
#include "MyData.h"

class Pair {
	MyString m_key;//���� -�������
	MyData m_data;// ������ � ����������
	//���������, ��� �� ������������� ���� ������ ���� �������������
public:
	Pair(){}
	Pair(const char* k, const MyData& d)
		: m_key(k), m_data(d) {
		
	};




	friend class Base;

	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

	bool operator < (const Pair& right) const;
	bool operator > (const Pair& right) const;
	bool operator == (const Pair& right) const;



};
