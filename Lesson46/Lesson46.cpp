/*
------------------------------------
Lesson 46
Title: stl (Standard Template Library) 16, dynamic allocations and smart pointers 4, shared_ptr 2, CRTP: Curiously Recurring Template Pattern, weak_ptr, i/o stream 1
-----------------
CRTP: Curiously Recurring Template Pattern
-----------------
Aliasing constructor
////////////////////////////////////////////////

CRTP: Curiously Recurring Template Pattern

template <typename T>
class Base
{
    // Artık Base<Myclass> açılımı Myclass'ın taban açılımı olacak.
public:
    void foo();
};

//CRTP
class Myclass : public Base<Myclass>
{
    
};


int main(int argc, char* argv[])
{
    Myclass mx;
    mx.foo();
    return 0;
}

////////////////////////////////////////////////
Eğer bir sınıfın üye fonksiyonu içinde shared_ptr ile hayatı kontrol edilen *this nesnesini gösteren
shared_ptr'nin kopyasını çıkartmak isterseniz, sınıfınızı CRTP örüntüsü ile kalıtım yoluyla std::enable_shared_from_this
sınıfından elde etmelisiniz

EN:
If you want to duplicate shared_ptr, which shows the *this object whose life is controlled by shared_ptr within the member function of a class,
you must inherit your class from the std :: enable_shared_from_this class with the CRTP pattern.

#include <memory>

#include "nutility.h"
#include "date.h"

using namespace std;

class Neco : public enable_shared_from_this<Neco> // CRTP
{
public:
    Neco()
    {
        cout << "Neco ctor this : " << this << "\n";
    }

    void func()
    {
        cout << "Neco::func() islevi : " << this << "\n";
        auto sptr = shared_from_this();
        cout << "sptr.use_count() = " << sptr.use_count() << "\n";
    }

    ~Neco()
    {
        cout << "Neco destructor : " << this << "\n";
    }
};

int main(int argc, char* argv[])
{
    auto sp = make_shared<Neco>();
    sp->func();
    cout << "after func: sp.use_count() = " << sp.use_count() << "\n";
    return 0;
}

====================================
weak_ptr

#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
    auto spx = make_shared<string>("necati");

    cout << spx.use_count() << "\n";
    weak_ptr<string> wp(spx); // Used for if the resource that is used in spx is deleted or not
    cout << spx.use_count() << "\n";

    spx.reset();

    //*wp; // syntax error

    if(wp.expired())
    {
        cout << "Resources are no more\n";
    }
    else
    {
        cout << "Resources are still there\n";
    }
    
    return 0;
}
////////////////////////////////////////////////
#include <memory>

#include "nutility.h"
#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    auto spx = make_shared<string>("necati");

    weak_ptr<string> wp(spx); 
    spx.reset();

    -------
    auto sp = wp.lock();
    if(sp != nullptr)
    {
       cout << "Object is alive. Length: " << sp->length() << "\n"; 
    }
    else
    {
       cout << "Object is not alive"; 
        
    }
    -------
    OR
    -------
    if(auto sp = wp.lock();)
    {
       cout << "Object is alive. Length: " << sp->length() << "\n"; 
    }
    else
    {
       cout << "Object is not alive"; 
        
    }
    -------
====================================
I/O

ostream cout;
istream cin;

//ostream
//basic_ostream<char, char_traits<char>>
//wostream
//basic_ostram<wchar_t, char_traits<wchar_t>>

Topics:

formatlı giriş çıkış işlemleri
formatsız giriş çıkış işlemleri

formatlama
stream errors
akımın sağlık durumu / condition state
giriş çıkış işlemleri & exception handling

bellek üstünde okuma yazma işlemleri

dosya işlemleri

////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "alican\n"; // Global operator function
    // operator<<(cout, "alican");

    cout.operator<<("alican"); // This will write the RAM location of the temp object
    
    return 0;
}
*/

////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "alican\n"; // Global operator function
    // operator<<(cout, "alican");

    cout.operator<<("alican"); // This will write the RAM location of the temp object
    
    return 0;
}
