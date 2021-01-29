/*
------------------------------------
Lesson 45
Title: stl (Standard Template Library) 15, dynamic allocations and smart pointers 3, shared_ptr 1
-----------------
release: (Gives the address, but not deletes the data)

#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    auto uptr = make_unique<string>("necati");
    std::cout << (uptr ? "dolu" : "bos") << "\n";
    auto ptr = uptr.release();
    std::cout << (uptr ? "dolu" : "bos") << "\n";
    return 0;
}
////////////////////////////////////////////////

// If we want to unique_ptr to use our own written delete funtion:

#include <iostream>
#include <memory>
#include <string>

#include "date.h"
using namespace std;

struct DateDeleter
{
    void operator()(Date* p)
    {
        cout << *p << " date is being deleted.\n";
        delete p;
    }
};

int main(int argc, char* argv[])
{
    cout << "main started\n";
    
    {
        unique_ptr<Date, DateDeleter> uptr (new Date(1, 3, 2010));
        cout << *uptr <<"\n";
    }

    cout << "main continues\n";
    
    
    return 0;
}

////////////////////////////////////////////////

// Instead of creating class, you can also do this:

#include <memory>
#include <string>

using namespace std;

struct Data
{
    int x, y;
};

Data* createData(void);
void f1(Data*);
void f3(Data*);
void f2(Data*);
void closeData(Data*);


int main(int argc, char* argv[])
{
    auto f = [](Data* p) {closeData(p);};
    unique_ptr<Data, decltype(f)> uptr(createData(), f);
    return 0;
}

////////////////////////////////////////////////
To create unique_ptr, there are 3 ways:

// Sink model
#include <iostream>
#include <memory>
#include <string>

#include "date.h"

using namespace std;

void func_sink(unique_ptr<Date> uptr)
{
    cout << *uptr <<"\n";
}

int main(int argc, char* argv[])
{
    func_sink(make_unique<Date>(1,2, 2010));
    cout << "............\n";
    return 0;
}

////////////////////////////////////////////////

// Factory model
#include <iostream>
#include <memory>
#include <string>

#include "date.h"

using namespace std;

// unique_ptr<Date> create_date(int d, int m, int y)
// {
//     return unique_ptr<Date>{new Date{d, m, y}};
// }

// unique_ptr<Date> create_date(int d, int m, int y)
// {
//     return make_unique<Date>(d, m, y);
// }

unique_ptr<Date> create_date(int d, int m, int y)
{
    unique_ptr<Date> uptr{new Date{d,m,y}};
    return uptr;
}

int main(int argc, char* argv[])
{
    auto uptr = create_date(1, 2, 2020);
    return 0;
}

////////////////////////////////////////////////

// pass through
#include <iostream>
#include <memory>
#include <string>

#include "date.h"

using namespace std;

unique_ptr<Date> func(unique_ptr<Date> uptr)
{
    cout << *uptr << "\n";
    return uptr;
}

int main(int argc, char* argv[])
{
    auto up = func(make_unique<Date>(2,2,2010));

    cout << *up << "\n";
    
    return 0;
}

////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>

#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    // unique_ptr<Date> uptr{new Date [10]}; // Will use delete instead delete[].
    unique_ptr<Date[]> uptr{new Date [10]}; // Will use delete[].(C++14. Before that, we needed to use deleter function)
    return 0;
}

////////////////////////////////////////////////

// Using unique_ptr in containers

#include <iostream>
#include <memory>
#include <string>
#include <vector>


#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<unique_ptr<Date>> myvec;

    unique_ptr<Date> date{new Date(1, 2, 2020)};

    myvec.push_back(make_unique<Date>(1, 2, 2010));
    myvec.push_back(make_unique<Date>(1, 2, 2011));
    myvec.push_back(make_unique<Date>(1, 2, 2012));
    myvec.push_back(move(date));
    myvec.emplace_back(new Date(1, 2, 2021));

    myvec.erase(myvec.begin() + 1);

    return 0;
}

====================================

// shared_ptr

#include <iostream>
#include <memory>
#include <string>


#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    //shared_ptr does not have deleter template type parameter
    shared_ptr<Date> sp (new Date(1,2,2020), [](Date *p){delete p;});

    cout << *sp << "\n";
    
    return 0;
}

////////////////////////////////////////////////

// shared_ptr

#include <iostream>
#include <memory>
#include <string>


#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    auto sp1 = make_shared<Date>(1, 2, 2020);
    auto sp2 = sp1;
    auto sp3 = sp1;
    {
        auto sp4(sp1);
        cout << "sp4.use_count() = " << sp4.use_count() <<"\n";
        
    }

    cout << "sp1.use_count() = " << sp1.use_count() <<"\n";
    cout << "sp2.use_count() = " << sp2.use_count() <<"\n";
    cout << "sp3.use_count() = " << sp3.use_count() <<"\n";
    
    return 0;
}
////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>


#include "date.h"

using namespace std;

void* operator new(size_t n)
{
    void* vp = std::malloc(n);
    cout << "operator new called n : " << n << "\n";
    if (!vp)
        throw std::bad_alloc{};
    cout << "Address of allocated block : " << vp << "\n";
    return vp;
}

int main(int argc, char* argv[])
{
    cout << "sizeof(Date)" << sizeof(Date) << "\n";
    auto sp1 = make_shared<Date>(1, 2, 2020); // Size is bigger than raw Date or unique_ptr<Date> because shared_ptr holds extra data (count etc.)

    return 0;
}
*/

////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include <string>


#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    auto sp1 = make_shared<Date>(1, 2, 2020);
    
    return 0;
}
