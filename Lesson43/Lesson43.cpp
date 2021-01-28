/*
------------------------------------
Lesson 43
Title: stl (Standard Template Library) 13, sorted range algorithms, [[nodiscard]] attribute, Member function pointers, std::invoke, dynamic life objects and smart pointers 1
-----------------
Sorted range algorithms
Algorithms that can executed on sorted containers.

#include <vector>
#include <algorithm>
#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> ivec;
    fc(ivec, 100, Irand{0, 1000});

    sort(ivec.begin(), ivec.end());
    pc(ivec);

    int ival;

    cout << "bir deger girin: ";
    cin >> ival;

    auto [iter_lower, iter_upper] = equal_range(ivec.begin(), ivec.end(), ival);
    
    // auto iter_lower = lower_bound(ivec.begin(), ivec.end(), ival);
    // auto iter_upper = upper_bound(ivec.begin(), ivec.end(), ival);

    cout << "distance for lower bound: " << distance(ivec.begin(), iter_lower) << "\n";
    cout << "distance for upper bound: " << distance(ivec.begin(), iter_upper) << "\n";
    
    return 0;
}

/////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> svec;

    while(svec.size() != 12)
    {
        auto s = rtown();
        auto iter_upper = upper_bound(svec.begin(), svec.end(), s);
        svec.insert(iter_upper, s);
        pc(svec);
        (void)getchar();
    }
     
    return 0;
}

/////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <list>

#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> svec;
    list<string> slist;
    vector<string> destvec;
    
    fc(svec, 5, rname());
    fc(slist, 5, rname());
    
    sort(svec.begin(), svec.end());
    slist.sort();
    
    pc(svec);
    pc(slist);

    merge(svec.begin(), svec.end(), slist.begin(), slist.end(), back_inserter(destvec));

    pc(destvec);
    
    return 0;
}

/////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <list>

#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> svec;

    fc(svec, 20, rname);
    sort(svec.begin(), svec.end());
    pc(svec);

    string name;

    cout << "aranacak isim girin: ";
    cin >> name;

    if(binary_search(svec.begin(), svec.end(), name))
        cout << "\nEvet var";
    else
        cout << "\nHayir yok.";
    
    return 0;
}

============

set_intersection (AnB)
set_union (AUB)
set_difference (A - B)
set_symmetric_difference (AUB - AnB)

#include <vector>
#include <algorithm>
#include <list>

#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vec_x;
    vector<int> vec_y;
    vector<int> destvec;
    
    fc(vec_x, 10, Irand{0, 30});
    fc(vec_y, 10, Irand{0, 30});
    sort(vec_x.begin(), vec_x.end());
    sort(vec_y.begin(), vec_y.end());
    pc(vec_x);
    pc(vec_y);

    //set_intersection(vec_x.begin(), vec_x.end(), vec_y.begin(), vec_y.end(), back_inserter(destvec));
    // set_union(vec_x.begin(), vec_x.end(), vec_y.begin(), vec_y.end(), back_inserter(destvec));
    // set_difference(vec_x.begin(), vec_x.end(), vec_y.begin(), vec_y.end(), back_inserter(destvec));
    set_symmetric_difference(vec_x.begin(), vec_x.end(), vec_y.begin(), vec_y.end(), back_inserter(destvec));

    pc(destvec);
    
    return 0;
}

============

[[nodiscard]]
(void)getchar(); // Why casted to void? because I do not want to and will not use the return value of the function.
                 // Prevents compiler to give warning messages about unused return value

// Unused result of a function with a nodiscard attribute
// [C4834] discarding return value of function with 'nodiscard' attribute
[[nodiscard]] int func()
{
    return 1;
}

int main(int argc, char* argv[])
{
    func();
    return 0;
}

====================================
// Member function pointers

using namespace std;

class Myclass
{
public:
    static int foo(int x)
    {
        cout << "foo cagrildi x = " << x << "\n";
        return x * x;
    }
};

int main(int argc, char* argv[])
{
    int (*fp)(int) = &Myclass::foo;

    auto np = fp(12);
    
    return 0;
}

/////////////////////////////////////////////

using namespace std;

class Myclass
{
public:
    int foo(int x)
    {
        cout << "foo cagrildi x = " << x << "\n";
        return x * x;
    }
};

int main(int argc, char* argv[])
{
    int (Myclass::*fp)(int) = &Myclass::foo;
    auto fp = &Myclass::foo; // Modern C++
    // int (*fp)(int) = &Myclass::foo; //Syntax Error

    auto np = fp(12);
    
    return 0;
}

/////////////////////////////////////////////

using namespace std;

class Myclass
{
public:
    int foo(int x)
    {
        cout << "foo cagrildi x = " << x << "\n";
        return x * x;
    }
};

int main(int argc, char* argv[])
{
    auto fp = &Myclass::foo;
    // int (*fp)(int) = &Myclass::foo; //Syntax Error
    Myclass temp{};

    (temp.*fp)(21);
    
    return 0;
}
====================================
std::invoke

#include <vector>
#include <algorithm>
#include <list>

#include "nutility.h"
using namespace std;

int func(int x, int y)
{
    return x * x + y * y;
}

int main(int argc, char* argv[])
{
    // auto n = func(10, 20);
    auto n = invoke(func, 1, 2); // C++17
    cout << "n = " << n << "\n";
    return 0;
}
====================================
dynamic life objects and smart pointers

static lifetime
    - global
    - static local

automatic lifetime

dynamic lifetime
    - not used if it is necessary
        -- high cost
        --

new operators
new T
new[] T
.
.
.

Factory funtions (Creates an object and returns the address of that object)
T *create_object()
{

}

/////////////////////////////////////////////

#include <algorithm>
#include <list>

#include "nutility.h"
using namespace std;

int func(int x, int y)
{
    return x * x + y * y;
}

int main(int argc, char* argv[])
{
    tuple<int>* p1 = new tuple<int>;
    tuple<int>* p2 = new tuple<int>();
    tuple<int>* p3 = new tuple<int>{};
    tuple<int, int, int>* p4 = new tuple<int, int, int>(1, 2, 3);
    tuple<int, int, int>* p5 = new tuple<int, int, int>{1, 2, 3};

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    
    return 0;
}
============
new operator
new expression ===> operator new function
                    ctor

delete operator
delete expression ===> dtor
                       operator delete
============

#include <new>

#include "nutility.h"

// typedef void (*new_handler)(void);
using new_handler = void(*)(void);

new_handler get_new_handler();
new_handler set_new_handler();

void myfoo()
{
    
}

int main(int argc, char* argv[])
{
    std::cout << "&myfoo = " << &myfoo << "\n";
    // cout << boolalpha << (get_new_handler() == nullptr);
    std::set_new_handler(&myfoo);

    std::cout << std::get_new_handler() << "\n";
    return 0;
}


*/

#include <functional>
#include <new>

#include "nutility.h"

// typedef void (*new_handler)(void);
using new_handler = void(*)(void);

new_handler get_new_handler();
new_handler set_new_handler();

void myfoo()
{
    
}

int main(int argc, char* argv[])
{
    std::cout << "&myfoo = " << &myfoo << "\n";
    // cout << boolalpha << (get_new_handler() == nullptr);
    std::set_new_handler(&myfoo);

    std::cout << std::get_new_handler() << "\n";
    return 0;
}
