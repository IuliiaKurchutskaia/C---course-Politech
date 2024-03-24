#pragma once
#include <iostream>
using namespace std;
class Shape
{
public:
    enum class Color { red, green, blue };

protected:
    Color m_color;


public:
    Shape() {

    }
    Shape(Color c) {
        m_color = c;
    }
    virtual  void Inflate(int dl) {} // = 0;
    //  virtual   void Inflate(int a, int b, int c) = 0;
    //  virtual void Inflate(int a, int b) = 0;
     // virtual  void Inflate(int a, int b, int c, int d) = 0;
     /* void WhereAmI();*/
    virtual void WhereAmIVirtual();
    virtual ~Shape()
    {
        std::cout << "Now I am in Shape's destructor!" << std::endl;

    }
};
#pragma once
