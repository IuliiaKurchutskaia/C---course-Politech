#pragma once
#include <string>

#include "MyString.h"

class MyData {
public:
	enum Sex { UNDEF, MALE, FMALE };
private:
	Sex sex;
	size_t m_age;
	MyString m_job;

	float m_salary;

public: //Подумайте, все ли перечисленные ниже методы надо реализовывать
	MyData();
	MyData(Sex s, size_t age, const char* job, float sal);


	friend std::ostream& operator<<(std::ostream& ost, const MyData& d);
};