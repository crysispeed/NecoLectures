/*
------------------------------------
40.Ders
Video başlığı: stl (Standard Template Library) 10, map and multimap 2, unordered_set and unordered_map, stack and queue class
-----------------
-----------------

#include <iostream>
#include <map>
#include "../NecoUtility/nutility.h"

using namespace std;
int main(int argc, char* argv[])
{
    map<string, int> mymap;

    randomize();

    fc(mymap, 10, [] {return make_pair(rname(), rand());});
    pc(mymap, "\n");
    string name;

    cout << "bir isim giriniz: ";
    cin >> name;

    mymap[name] = 77777;

    pc(mymap, "\n");
}
----------------------------------
unordered_set and unordered_map

unordered_set<int> l_set;
// unordered_set<int, hash<int>, equal_to<int>> l_set;

----------------------------------
stack

#include <iostream>
#include <stack>
#include <unordered_set>

#include "nutility.h"

using namespace std;
int main(int argc, char* argv[])
{
    stack<int> mystack;
    for (int i = 0; i < 10; ++i)
    {
        mystack.push(i);
    }

    cout << "size    : " << mystack.size() << "\n";
    cout << "is empty: " << boolalpha << mystack.empty() << "\n";
    
    cout << "mystack.top() : " << mystack.top() << "\n";
    mystack.top() = 999;

    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    
}

 */

#include <iostream>
#include <stack>
#include <unordered_set>

#include "nutility.h"

using namespace std;
int main(int argc, char* argv[])
{
    stack<int> mystack;
    for (int i = 0; i < 10; ++i)
    {
        mystack.push(i);
    }

    cout << "size    : " << mystack.size() << "\n";
    cout << "is empty: " << boolalpha << mystack.empty() << "\n";
    
    cout << "mystack.top() : " << mystack.top() << "\n";
    mystack.top() = 999;

    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    
}
