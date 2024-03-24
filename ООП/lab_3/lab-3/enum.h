#pragma once
#include <iostream>
using namespace std;
enum  Day
{
 
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

Day& operator++(Day& day)
{
    int i = static_cast<int>(day) + 1;

   
    if (i > 6)   // Saturday = 6
        i = 0;  // Sunday = 0

    day = static_cast<Day>(i);

    return day;
}

ostream& operator<<(ostream& os, const Day day)
{
    switch (day)
    {
    
    case Day::Monday:    return os << "Monday";
    case Day::Tuesday:   return os << "Tuesday";
    case Day::Wednesday: return os << "Wednesday";
    case Day::Thursday:  return os << "Thursday";
    case Day::Friday:    return os << "Friday";
    case Day::Saturday:  return os << "Saturday";
    case Day::Sunday:    return os << "Sunday";
    }

    return os;
}
Day operator+(const Day& day, int x)
{
    int i = (static_cast<int>(day) + x) % 7;

  
    //if (i > 6)   // Saturday = 6
    //    i = 0;  // Sunday = 0

    return static_cast<Day>(i);

    
}

Day& operator+=(Day& day, int x)
{
    
   int i=   + static_cast<int>(day) + x;


    if (i > 6)   // Saturday = 6
        i = 0;  // Sunday = 0

    day = static_cast<Day>(i);

    return day;
}
