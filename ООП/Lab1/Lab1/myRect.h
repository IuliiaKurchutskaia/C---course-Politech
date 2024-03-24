#pragma once
#include <iostream>
using namespace std;

class Rect{
private:
    int m_left, m_right, m_top, m_bottom;
public:
    Rect() 
        :m_left(0), m_right(0), m_top(0), m_bottom(0)
    {}
    Rect(int left, int right, int top, int bottom)
        :m_left(left), m_right(right), m_top(top), m_bottom(bottom)
    {
        norm();
    
    }

    Rect(const Rect& r)
    {
        m_left = r.m_left;
        m_right = r.m_right;  
        m_top = r.m_top;
        m_bottom = r.m_bottom;    // для примера
    }

    ~Rect()
    {
        std::cout << "дексруктор" << std::endl;

    }
    void norm();
    void InflateRect(int a, int b, int c, int d);
    void InflateRect(int da=1, int db=1);

    void SetAll(int left, int right, int top, int bottom);
 

   void Get();
   int GetLeft() const;
   int GetRight() const;
   int GetTop() const;
   int GetBottom() const;
   Rect GetAll();

   Rect  BoundingRect3(const Rect& r1, const Rect& r2);



};
//
Rect BoundingRect(Rect r1, Rect r2);
Rect BoundingRect2(const Rect& r1, const Rect& r2);

//Rect BoundingRect(Rect r1, Rect r2);