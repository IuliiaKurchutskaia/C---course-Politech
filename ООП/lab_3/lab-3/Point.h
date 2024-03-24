#pragma once

#include <iostream>
using namespace std;
class Point {
	//public:
	int m_x;
	int m_y;
public:
	Point() {
		m_x = 0;
		m_y = 0;
	};
	Point(int x, int y) {
		m_x = x;
		m_y = y;
	};

	Point& operator += (const Point& refPt) {
		m_x += refPt.m_x;
		m_y += refPt.m_y;
		return *this;
	}
	Point& operator += (int x) {
		m_x += x;
		m_y += x;
		return *this;
	}

	Point operator + (const Point& refPt) const {
		Point tmp;
		tmp.m_x = m_x + refPt.m_x;
		tmp.m_y = m_y + refPt.m_y;
		return tmp;
	}
	Point operator + (int x) const {
		Point tmp;
		tmp.m_x = m_x + x;
		tmp.m_x = m_y + x;

		return tmp;
	}
	Point& operator+(const Point& Pt1) {
		m_x = +m_x;
		m_y = +m_y;
		return *this;
	}

	//Point operator+(const Point Pt1) const {
	//	Point tmp;
	//	tmp.m_x = +Pt1.m_x;
	//	tmp.m_y = +Pt1.m_y;
	//	return tmp;
	//}

	//Point operator+() const;
	friend Point operator + (const int x, const Point refPt2);


	friend Point& operator -= (Point& refPt1, const Point& refPt2);
	friend Point& operator -= (Point& refPt1, int x);

	friend Point operator - (const Point refPt1, const Point refPt2);
	friend Point operator - (const Point refPt1, const int x);
	friend Point operator - (const int x, const Point refPt2);

	friend Point operator-(const Point Pt1);
	friend Point operator+(const Point Pt1);


	//void operator << (const Point& Pt1) const;

	friend ostream& operator<<(ostream& ost, Point& Pt1);

	//Перегрузите операторы « -- »(префиксный и постфиксный декременты) для класса
//	Point

//ЭКЗАМЕН
/*
		// Перегрузка префиксного декремента "--" методом класса
	Point operator--() {
		--m_x;
		--m_y;
		return *this;
	}

	// Перегрузка постфиксного декремента "--"методом класса
	Point operator--(int) {	
		Point temp(m_x, m_y); // создаем копию текущего объекта
		--m_x;
		--m_y;
		return temp; // возвращаем копию объекта
	}

*/
protected:
	friend Point& operator--(Point& p);

	friend Point& operator--(Point& p, int);





};


