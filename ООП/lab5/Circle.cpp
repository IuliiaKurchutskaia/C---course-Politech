#include "circle.h"
#include <iostream>
using namespace std;




bool Circle::Point::Point::operator == (const Point& right) const {
	return m_x == right.m_x && m_y == right.m_y;
}


Circle::Circle(const Circle& other)  //
{
	p = other.p;
	m_r = other.m_r;
	m_s= other.m_s;
}

double Circle::CalcS() {
	return M_PI * m_r * m_r;
}
//bool Circle::operator == (const Circle& right) const {
//	return m_r == right.m_r && p == right.p;
//}
