/*
------------------------------------
33.Ders
Video başlığı: stl (Standard Template Library) 3, algorithms 2
-----------------
-----------------
- Algoritmalar, eğer işlem fail olmuşsa, end iterator'ını döndürür.
_if algorithms
copy_if

//UnPred -> Unary Predict
template <typename InIter, typename OutIter, typename UnPred>
OutIter CopyIf(InIter beg, InIter end, OutIter destbeg, UnPred f)
{
    while (beg != end)
    {
        if(f (*beg))
        {
            *destbeg++ = *beg;
        }
        ++beg;
    }

    return destbeg;
}
==================
generic programlamada compile-time'da kod seçimi yapabilmek için:

-tag-dispatch
-sfinae
-if constexpr (C++ 17)

iteratörler üzerinde işlem yapan global fonksiyon şablonları

advance
distance
next (C++ 11)
prev (C++ 11)
iter_swap

advance: (Bir iterator'ı arttırıp eksiltmek için var)
int main(int argc, char* argv[])
{
    int a []= {12, 45, 12 ,65, 2, 6, 34, 8, 3};


    list<string> slist{"ali", "fatma", "selim", "erkan", "huriye"};

    auto iter = slist.begin();
    cout << *iter << "\n";
    advance(iter, 4);   // iter'i 4 arttırır
    cout << *iter << "\n";
    advance(iter, -3); // iter'i 3 azaltır
    cout << *iter << "\n";
    // vector<int> vec;
    // vector<int>::reverse_iterator ba = vec.rend();
    // ++ba;
    // begin(vec);
    return 0;
}

distance(iter1, iter2): (iki iter arasındaki öge sayısını verir)
int main(int argc, char* argv[])
{
    int a []= {12, 45, 12 ,65, 2, 6, 34, 8, 3};
    vector<int> svel{1,2,3,4,5,6,7,8,9};
    cout << distance(svel.begin(), svel.end());
    auto iter_first = svel.begin();
    auto iter_sec = svel.end();
    cout << distance(iter_first, iter_sec);
    return 0;
}
*/

#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
bool has_len_5 (const string& s)
{
    return s.size() == 5;
}

//UnPred -> Unary Predict
template <typename InIter, typename OutIter, typename UnPred>
OutIter CopyIf(InIter beg, InIter end, OutIter destbeg, UnPred f)
{
    while (beg != end)
    {
        if(f (*beg))
        {
            *destbeg++ = *beg;
        }
        ++beg;
    }

    return destbeg;
}

int main(int argc, char* argv[])
{
    int a []= {12, 45, 12 ,65, 2, 6, 34, 8, 3};
    vector<int> svel{1,2,3,4,5,6,7,8,9};
    cout << distance(svel.begin(), svel.end());
    auto iter_first = svel.begin();
    auto iter_sec = svel.end();
    cout << distance(iter_first, iter_sec);
    return 0;
}
