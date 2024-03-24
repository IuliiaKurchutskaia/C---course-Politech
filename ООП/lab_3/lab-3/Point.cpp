#include "Point.h"

Point& operator -= ( Point& refPt1, const Point& refPt2) {
	refPt1.m_x -= refPt2.m_x;
	refPt1.m_y -= refPt2.m_y;
	return refPt1;
}

Point& operator -= (Point& refPt1, int x) {
	refPt1.m_x -= x;
	refPt1.m_y -= x;
	return refPt1;
}



Point operator + (const int x, const Point refPt2) {
	Point tmp;
	tmp.m_x = x+ refPt2.m_x;
	tmp.m_y = x + refPt2.m_y;
	return tmp;
}

Point operator - (const int x, const Point refPt2) {
	Point tmp;
	tmp.m_x = x - refPt2.m_x;
	tmp.m_y = x - refPt2.m_y;
	return tmp;
}

Point operator - (const Point refPt1, const int x) {
	Point tmp;
	tmp.m_x = refPt1.m_x-x;
	tmp.m_y = refPt1.m_y-x;
	return tmp;
}

Point operator - (const Point refPt1, const Point refPt2) {
	Point tmp;
	tmp.m_x = refPt1.m_x - refPt2.m_x;
	tmp.m_y = refPt1.m_y - refPt2.m_y;
	return tmp;
}


Point operator-(const Point Pt1){
Point tmp;
tmp.m_x = -Pt1.m_x;
tmp.m_y = -Pt1.m_y;
	return tmp;
}


Point operator+(const Point Pt1) {
	Point tmp;
	tmp.m_x = +Pt1.m_x;
	tmp.m_y = +Pt1.m_y;
	return tmp;
}
//void Point::operator << (const Point& Pt1) const {
//	string str;
//
//	std::cout << "x= " << m_x << "y= " << m_y << std::endl;
//}
//Point Point::operator+() const
//{
//	return Point(+m_x, +m_y);
//}

ostream& operator<<(ostream& ost, Point& Pt1)
{
	ost << "operator vivoda: "<<endl<<"x= " << Pt1.m_x << endl<<"y= " << Pt1.m_y;
	return ost;
}


Point& operator--(Point& p) {
	--p.m_x;
	--p.m_y;
	return p;

 }

Point& operator--(Point& p, int) {
	Point temp(p.m_x, p.m_y); // создаем копию текущего объекта
	--temp.m_x;
	--temp.m_y;
	return temp; // возвращаем копию объекта
}