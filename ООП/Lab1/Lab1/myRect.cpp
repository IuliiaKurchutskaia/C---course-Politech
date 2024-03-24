#include "myRect.h"
#include <iostream>
using namespace std;


void Rect::norm() {
	if (m_right < m_left) {
		int tmp = m_left;
		m_left = m_right;
		m_right = tmp;
	}
	if (m_top > m_bottom) {
		int tmp = m_bottom;
		m_bottom = m_top;
		m_top = tmp;
	}
};
void Rect::InflateRect(int a, int b, int c, int d)
{
	m_left -= a;
	m_right += b;
	m_top -= c;
	m_bottom +=d;

	norm();

	// TODO: Добавьте сюда код реализации.
}
void Rect::InflateRect(int da, int db) {
	m_left -= da;
	m_right += da;
	m_top -= db;
	m_bottom += db;
	norm();
}

void Rect::SetAll(int left, int right, int top, int bottom) {
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	norm();
}
void Rect::Get() {
	std::cout << "left=" << m_left << std::endl;
	std::cout << "right=" << m_right << std::endl;
	std::cout << "top=" << m_top << std::endl;
	std::cout << "bottom=" << m_bottom << std::endl;

};

int Rect:: GetLeft()  const   {
	return m_left;

}
int Rect::GetRight() const 
{
	return m_right;
}

int Rect::GetTop() const {
	return m_top;

}
int Rect::GetBottom() const {
	return m_bottom;

}
//Rect Rect::GetAll() {
//
//	Rect tmp;
//
//	tmp.m_left = GetLeft();
//	tmp.m_right = GetRight();
//	tmp.m_top = GetTop();
//	tmp.m_bottom = GetBottom();
//	return tmp;
//
//}


Rect  Rect::BoundingRect3(const Rect& r1, const Rect& r2) {
//	Rect r1 = r11.GetAll();
//Rect r2 = r22.GetAll();
	int left = r1.m_left < r2.m_left ? r1.m_left : r2.m_left;
	int right = r1.m_right > r2.m_right ? r1.m_right : r2.m_right;
	int top = r1.m_top < r2.m_top ? r1.m_top : r2.m_top;
	int bottom = r1.m_bottom > r2.m_bottom ? r1.m_bottom : r2.m_bottom;
	Rect tmp(left, right, top, bottom);
	return tmp;
};
Rect BoundingRect(Rect r1, Rect r2) {

	//Rect r_1 = r1.GetAll();
	//Rect r_2 = r2.GetAll();
	
	int left = r1.GetLeft() < r2.GetLeft() ? r1.GetLeft(): r2.GetLeft();
	int right = r1.GetRight() > r2.GetRight() ? r1.GetRight() : r2.GetRight();
	int top = r1.GetTop() < r2.GetTop() ? r1.GetTop() : r2.GetTop();;
	int bottom = r1.GetBottom() > r2.GetBottom() ? r1.GetBottom() : r2.GetBottom();;
	Rect tmp(left, right, top, bottom);
	return tmp;
}

Rect BoundingRect2(const Rect &r1, const Rect &r2) {

	//Rect r_1 = r1.GetAll();
	//Rect r_2 = r2.GetAll();

	int left = r1.GetLeft() < r2.GetLeft() ? r1.GetLeft() : r2.GetLeft();
	int right = r1.GetRight() > r2.GetRight() ? r1.GetRight() : r2.GetRight();
	int top = r1.GetTop() < r2.GetTop() ? r1.GetTop() : r2.GetTop();;
	int bottom = r1.GetBottom() > r2.GetBottom() ? r1.GetBottom() : r2.GetBottom();;
	Rect tmp(left, right, top, bottom);
	return tmp;
}


