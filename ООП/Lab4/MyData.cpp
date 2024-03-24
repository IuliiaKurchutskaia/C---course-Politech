#pragma once
#include "MyData.h"

#include <iostream>

using namespace std;

MyData::MyData():m_job("no")// конструктор без параметров
{
	sex = UNDEF;
	m_age = 0;
	
	m_salary = 0;
};
MyData::MyData(Sex s, size_t age, const char* job, float sal):m_job(job) {
	sex = s;
	m_age = age;
	
	m_salary = sal;
}

std::ostream& operator<<(std::ostream& ost, const MyData& d) {
	ost << "Sex: ";
	switch (d.sex)
	{
	case MyData::MALE:
		ost << "MALE" << endl;
		break;
	case MyData::FMALE:
		ost << "FMALE" << endl;
		break;

	default:
		ost << "UNDEF" << endl;
		break;
	}

	return  ost
		<< "Age: " << d.m_age << endl
		<< "Job: " << d.m_job << endl
		<< "Salary: " << d.m_salary << endl;
}