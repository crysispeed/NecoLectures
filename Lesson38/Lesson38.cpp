/*
------------------------------------
38.Ders
Video başlığı: stl (Standard Template Library) 8, vector container class, deque container class, list container class, forward_list container class
-----------------
-----------------

I didn't feel like taking notes today, sorry :'(

list                (doubly linked-list)
forward_list(C++11) (singly linked-list)

 */

#include <deque>

#include "nutility.h"
#include "date.h"
using namespace std;

int main(int argc, char* argv[])
{
    deque<Date> dx;   // CTAD, C++17

    for (int i = 0;i<20;++i)
    {
        auto date = Date::random();
        if(date.month_day() % 2 == 0)
            dx.push_front(date);
        else
            dx.push_back(date);
        // pc(dx, "\n");
        getchar();
        
        
    }
    
    return 0;
}
