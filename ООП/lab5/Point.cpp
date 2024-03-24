#include "Point.h"

Point& operator -= (Point& refPt1, const Point& refPt2) {
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
	tmp.m_x = x + refPt2.m_x;
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
	tmp.m_x = refPt1.m_x - x;
	tmp.m_y = refPt1.m_y - x;
	return tmp;
}

Point operator - (const Point refPt1, const Point refPt2) {
	Point tmp;
	tmp.m_x = refPt1.m_x - refPt2.m_x;
	tmp.m_y = refPt1.m_y - refPt2.m_y;
	return tmp;
}


Point operator-(const Point Pt1) {
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


ostream& operator<<(ostream& ost, Point& Pt1)
{
	ost << "operator vivoda: " << endl << "x= " << Pt1.m_x << endl << "y= " << Pt1.m_y;
	return ost;
}