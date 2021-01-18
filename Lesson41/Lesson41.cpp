/*
------------------------------------
41.Ders
Video başlığı: stl (Standard Template Library) 11, binary heap, priority queue, array template class, bitset class, reference_wrapper class
-----------------
Aggregate type
-----------------

binary heap (Heap algoithms):
make_heap
push_heap
pop_heap
sort_heap

#include <vector>

#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::vector<int> ivec;

    fc(ivec, 16, Irand{0, 100});
    pc(ivec);
    make_heap(ivec.begin(), ivec.end());
    pc(ivec);
    ivec.push_back(9876);
    push_heap(ivec.begin(),ivec.end());
    pc(ivec);
    pop_heap(ivec.begin(),ivec.end());
    cout << "en buyuk deger: " << ivec.back() << "\n";
    
    
    return 0;
}

Instead of using these, you can use priority_queue:
#include <queue>
#include <vector>

#include "nutility.h"
#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    // priority_queue<Date, std::vector<Date>, less<Date>> x;
    priority_queue<Date> x;
    for (int i = 0; i < 20; ++i)
    {
        x.push(Date::random());
    }


    cout << "kuyrukta " << x.size() << "tane date var. " << "\n";
    while (!x.empty())
    {
        cout << x.top();
        (void)getchar();
        x.pop();
    }
    
    return 0;
}
==============================
Arrray Template Class

#include <array>
#include <queue>
#include <vector>

#include "nutility.h"
#include "date.h"

using namespace std;

// Normal C dizisi kullanmak yerine ek bir maliyet olmadan bir sınıf nesnesi kullanmak
template<typename T, size_t n>
struct Array
{
    T ar[n];
};

int main(int argc, char* argv[])
{
    // int a[10];
    array<int, 5> ax; 
    
    return 0;
}

=================
declarations:
int main(int argc, char* argv[])
{
    // int a[10];
    array<int, 5> ax{1,2,3,4,5}; 
    array<int, 5> ay = {1,2,3,4,5}; 
    array az = {1,2,3,4,5};  //C++17 CTAD
    
    return 0;
}
==============================
Bitset Template Class

template <size_t n>
class bitset
{
    
};

using namespace std;

int main(int argc, char* argv[])
{
    unsigned long long uval;

    cout << "bir tam sayi girin: ";
    cin >> uval;

    cout << bitset<64>(uval) << "\n";
    
    return 0;
}
==============================
reference_wrapper

using namespace std;

template<typename T>
class ReferenceWrapper
{
public:
    ReferenceWrapper(T& t) : mp(&t)
    {
    }

    ReferenceWrapper& operator=(const T& t)
    {
        mp = &t;
    }
    operator T& ()
    {
        return *mp;
    }

    T& get()
    {
        return *mp;
    }
private:
    T* mp;
};

int main(int argc, char* argv[])
{
    int ival{4};
    int i = 0;
    
    ReferenceWrapper<int> r{ival};
    int y = ++r;
    
    r = i;
    
    return 0;
}
 */
#include <array>
#include <bitset>
#include <queue>
#include <vector>

#include "nutility.h"
#include "date.h"

using namespace std;

template<typename T>
class ReferenceWrapper
{
public:
    ReferenceWrapper(T& t) : mp(&t)
    {
    }

    ReferenceWrapper& operator=(const T& t)
    {
        mp = &t;
    }
    operator T& ()
    {
        return *mp;
    }

    T& get()
    {
        return *mp;
    }
private:
    T* mp;
};


int main(int argc, char* argv[])
{
    int ival{4};
    int i = 0;
    
    ReferenceWrapper<int> r{ival};
    int y = ++r;
    
    r = i;
    
    return 0;
}
