/*
------------------------------------
39.Ders
Video başlığı: stl (Standard Template Library) 9, set, multiset, map, multimap 1
-----------------
-----------------

set:

set<int> myset;
// set<int, less<int>, allocator<int>> myset;
=======================================
eşitlik karşılaştırması

x==y equality

equivalence:
less
!(x < y) && !(y < x) // every comparison will be made like this in set, so we need <operator in Key

!op(x, y) && !op(y, x)

set<string> myset;
// Irand rand {0 ,1000 };

for(int i = 0; i < 500 ; ++i)
{
    myset.insert(rname());
}

cout << "myset.size() = " << myset.size() << "\n";

// for(auto val: myset)
// {
//     cout << val << "\n";
// }

// set<int, less<int>, allocator<int>> myset;
return 0;

=======================================

strict weak ordering

a < b ===> true  =====>   b < a ===> true

a < b ===> true, b < c ===> true  =====>   a < c ===> true

!(a < b) && !(b < a), !(b < c) && !(c < b) =====> a = b = c

=======================================
int main(int argc, char* argv[])
{
    set<int> myset;

    myset.insert(myset.begin(), 13); // Hint insert, start comparing from the first parameter. Mostly used if we know where to put the value
    return 0;
}
=======================================
sequence data structure

lower bound
upper bound
equal range

4 7 9 12 12 56 56 56 98 113 67

lower bound -> belirli bir değerin sırayı bozmadan eklenebileceği ilk konum
upper bound -> belirli bir değerin sırayı bozmadan eklenebileceği son konum

75 için lower bound >= 75 olan ilk ögenin konumu (yukarıdaki listede 98'e denk geliyor)
75 için upper bound > 75 olan son ögenin konumu (yukarıdaki listede 98'e denk geliyor)
98 için upper bound > 98 olan son ögenin konumu (yukarıdaki listede 113'e denk geliyor)

[lower bound - upper bound] ==> equal range

#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include "nutility.h"

using namespace std;

int main(int argc, char* argv[])
{
    set<int> myset;

    fc(myset, 30, Irand{0,10});
    pc(myset);
    int ival;

    cout << "bir tam sayi girin: ";
    cin >> ival;

    auto iter_lower = myset.lower_bound(ival);
    auto iter_upper = myset.upper_bound(ival);

    cout << "distance for lower_bound : " << distance(myset.begin(), iter_lower) << "\n"; 
    cout << "distance for upper_bound : " << distance(myset.begin(), iter_upper) << "\n"; 
    cout << "distance for equal range : " << distance(iter_lower, iter_upper) << "\n"; 

    return 0;
}
==============================================================================
map and multimap (Map can only contain 1 key, multimap can have multiple keys)

template<typename Key, typename Val, typename Comp = less<Key>, typename A = allocator<pair<Key, Val>>>
class map;
======================================
#include <iostream>
#include <map>
#include <string>
#include "nutility.h"
#include <iomanip>
using namespace std;

using name = string;
using age = int;

int main(int argc, char* argv[])
{
    map<name, age> mymap;

    Irand rand{10,80};
    
    for(int i = 0; i < 20; ++i)
    {
        // mymap.insert(pair<name, age>{rname(), rand()});
        // mymap.insert(make_pair(rname(), rand()));
        // mymap.insert({rname(), rand()});
        mymap.emplace(rname(), rand());
    }
    cout << left;
    for (auto p : mymap)
    {
        cout << setw(20) << p.first << "  " << p.second << "\n";
    }
    
    return 0;
}
 */

#include <set>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "nutility.h"
#include <iomanip>
using namespace std;

using name = string;
using age = int;

int main(int argc, char* argv[])
{
    map<name, age> mymap;

    Irand rand{10,80};
    
    for(int i = 0; i < 20; ++i)
    {
        // mymap.insert(pair<name, age>{rname(), rand()});
        // mymap.insert(make_pair(rname(), rand()));
        // mymap.insert({rname(), rand()});
        mymap.emplace(rname(), rand());
    }
    cout << left;
    for (auto p : mymap)
    {
        cout << setw(20) << p.first << "  " << p.second << "\n";
    }
    
    return 0;
}
