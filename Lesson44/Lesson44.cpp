/*
------------------------------------
Lesson 44
Title: stl (Standard Template Library) 14, dynamic allocations and smart pointers 2
-----------------

void* operator new(size_t n)
{
    for (;;)
    {
        void* vp = std::malloc(n);
        if(vp)
            return vp;
        
        if(auto fp = std::get_new_handler(); !fp)
        {
            throw std::bad_alloc{};
        }
        else
        {
            fp();
        }
    }
}

/////////////////////////////////////////////

#include <iostream>
#include <new>
#include <vector>

using namespace std;

struct Nec
{
    char buffer[1024 * 1024]{};
};

void myhandler()
{
    static int cnt = 0;

    cout << "myhandler islevine yapilan " << ++cnt << ". cagri\n";
    (void*)getchar();
}

int main(int argc, char* argv[])
{
    int cnt{};
    vector<Nec*> vnec;

    // auto handler = set_new_handler(myhandler); // If uncommented, program will not throw exception, except it will call myhandler() until new function is successful.
    
    try
    {
        for (;;)
        {
            vnec.push_back(new Nec);
        }
    }
    catch (const exception& ex)
    {
        cout << "hata yakalandi : " << ex.what() << "\n";
        cout << "vec.size() = " << vnec.size() << "\n";
    }


    return 0;
}

////////////////////////////////////////////////
#include <iostream>
#include <new>
#include <vector>

using namespace std;

// Array new
int main(int argc, char* argv[])
{

    int n;

    cout << "Kac nesne? : ";
    cin >> n;

    auto p = new int[n]; // Array allocation

    delete []p; // Deleting dynamically allocated array

    return 0;
}

////////////////////////////////////////////////
#include <iostream>
#include <new>
#include <vector>

#include "date.h"

using namespace std;

//placement new operator
int main(int argc, char* argv[])
{

    unsigned char buffer [sizeof(Date)];

    cout << "Buffer address = " << static_cast<void *>(buffer);
    auto pt = new (buffer)Date();

    pt->~Date();

    return 0;
}

////////////////////////////////////////////////
#include <new>

#include "date.h"

using namespace std;

//placement new operator
int main(int argc, char* argv[])
{

    auto pd = new(nothrow) Date{}; // Throws no exception. If allocation fails, nullptr is returned.
    if(pd == nullptr)
    {
        
    }
    
    return 0;
}

===================================================
smart pointers

raw pointer (Naked pointer);
Triple *ptr

smart pointer:

// Exclusive ownership
unique_ptr

// Shared ownership
shared_ptr

weak_ptr (helper class for shared_ptr)

*p
p.operator*()

auto_ptr (Deprecated in C++11 and deleted in C++17)
////////////////////////////////////////////////

Implementation:

template <typename T>
struct Default_Delete
{
    void operator()(T* p)
    {
        delete p;
    }
};

template<typename T, typename D = Default_Delete<T>>
class Unique_Ptr
{
public:
    ~Unique_Ptr()
    {
        if(mp)
        {
            //delete mp;
            D{}(mp); // delete mp;
        }
    }
private:
    T *mp = nullptr;
    
};

////////////////////////////////////////////////
#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<Date> date_ptr; //Default init
    unique_ptr<Date> date_ptr2{}; //Default init 2
    unique_ptr<Date> date_ptr3 = new Date{}; // explicit

    if(date_ptr) // Operator bool func
    {
        cout << "dolu\n";
    }
    else
    {
        cout << "bos\n";
    }

    return 0;
}
////////////////////////////////////////////////
Making a pointer unique:

#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

template<typename T, typename ...Args>
unique_ptr<T> MakeUnique(Args && ...args)
{
   return unique_ptr<T>(new T(forward<Args>(args)...));
}

////////////////////////////////////////////////
#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{

    // unique_ptr<Date> date_ptr {new Date{1,1,2020}};
    auto date_ptr2 = make_unique<Date>(1,1,2020);
    return 0;
}

////////////////////////////////////////////////
#include <memory>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{

    unique_ptr<Date> ptr{new Date};
    // auto ptr2 = ptr; // Error (Copy constructor and copy assignment are deleted.)
    auto ptr2 = move(ptr); // Valid (Move assignment and move constructor are implemented)
    return 0;
}

////////////////////////////////////////////////
reset function:

#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<Date> ptr{new Date{1, 2, 2020}};

    cout << "ptr: " << (ptr ? "dolu" : "bos") << "\n";

    unique_ptr<Date> ptr{new Date{1, 2, 2020}};
    unique_ptr<Date> ptr2{new Date{2, 4, 1018}};

    ptr == ptr2; // compare pointers, not the data that points

    // ptr.reset(); //1: Delete your resource if not null
    // ptr.reset(nullptr); //2
    ptr = nullptr; //3

    // ptr.reset(new Date{5,5,2001}); // Deletes previous resource and assign argument

    cout << "ptr: " << (ptr ? "dolu" : "bos") << "\n";
    return 0;
}
*/

////////////////////////////////////////////////
#include <iostream>
#include <memory>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<Date> ptr{new Date{1, 2, 2020}};
    static_cast<void*>(ptr.get());
    cout << "ptr: " << (ptr ? "dolu" : "bos") << "\n";

    ptr.reset(new Date{5,5,2001}); // Deletes previous resource and assign this
    
    cout << "ptr: " << (ptr ? "dolu" : "bos") << "\n";
    return 0;
}
