#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <string>
using namespace std;


class Circle  {
	class Point {
		public:
		int m_x;
		int m_y;
	public:
		Point() :m_x(0), m_y(0) {}
		Point(int x, int y) : m_x(x), m_y(y) {}
	
		Point& operator=(const Point& other) {
			m_x = other.m_x;
			m_y = other.m_y;
			return *this;
		}
		Point& operator=(Point&& other) {
			if (this == &other) return *this;
			m_x = other.m_x;
			m_y = other.m_y;
			
			return  *this;
		}

		bool operator == (const Point& right) const;
	};

private:

  
    Point p;
    double m_r;
	double m_s;
public:
 
	
        
    Circle() 
    {
		Point p;
        m_r = 1;
		m_s = CalcS();
				      
    }

	Circle(int x, int y, double radius) :p(x, y), m_r(radius) {}
	Circle(const Circle& other);
	Circle& operator=(const Circle& other) {
		if (this != &other) {
		p = other.p;
		m_r = other.m_r;
		m_s = other.m_s;
	}
		return *this;
	}
	
	Circle& operator=(Circle&& other) {
		if (this == &other) return *this;
		p = other.p;
		m_r = other.m_r;
		m_s = other.m_s;
		return *this;
	}
	double GetS() const {
		return m_s;
	}
	double CalcS();
	friend ostream& operator<<(ostream& ost, Circle& Pt1) {

		ost << "radius = " << std::fixed << std::setprecision(2) << Pt1.m_r;
		ost<< ", center(" << Pt1.p.m_x << " ; " << Pt1.p.m_y << " )";
		return ost;
	};

	friend istream& operator>>(istream& ist, Circle& Pt1) {
		stringstream ss;
		string data;
		if (getline(ist,data)) {
			
			ss << data;
			sscanf_s(ss.str().c_str(), "radius = %lf, center(%d ; %d )", &Pt1.m_r, &Pt1.p.m_x, &Pt1.p.m_y);

		}
		return ist;
	};
	
	//bool operator == (const Circle& right) const;
	friend bool operator==(const Circle& c1, const Circle& c2) {
		return c1.p.m_x == c2.p.m_x && c1.p.m_y == c2.p.m_y && c1.GetS() == c2.GetS();
	}

};



//
//
//
//
