/*
------------------------------------
36.Ders
Video başlığı:stl (Standard Template Library) 6, vector class
------------------------------------

------------------------------------
Dikkat:
class MyClass
{
public:
    MyClass(std::initializer_list<int>)
    {
        std::cout <<"init. list ctor\n";
    }

    MyClass(int)
    {
        std::cout << "int parameter\n";
    }
};
using namespace std;

int main(int argc, char* argv[])
{
    MyClass m1{10};
    MyClass m2(10);
    
    return 0;
}
Vector class'ı için:

#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //initializer_list has priority in {} operator
    vector<int> m1{10}; // Initializer list ctor will be called
    vector<int> m2(10); // int ctor will be called
    
    return 0;
}
=======================================
you cannot shrink a vector using reserve().
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> m2(13, 5);
    cout << "capacity: " << m2.capacity() << "\n";
    for (int i = 0; i < 1000; ++i)
    {
        m2.push_back(i);
    }
    cout << "capacity: " << m2.capacity() << "\n";

    m2.reserve(1000); // non binding shrink-request
    
    cout << "capacity: " << m2.capacity() << "\n";
    return 0;
}

For this operation, shrink_to_fit() is used. (C++11)
Before modern C++, swap trick is used.
using namespace std;

int main(int argc, char* argv[])
{
   vector<int> ivec;

    for(int i = 0; i < 1000;++i)
    {
        ivec.push_back(i);
    }

    cout << "capacity: "<<ivec.capacity() <<"\n";
    cout << "size: "<<ivec.size() <<"\n";

    ivec.erase(ivec.begin() + 1, ivec.end());
    
    cout << "capacity: "<<ivec.capacity() <<"\n";
    cout << "size: "<<ivec.size() <<"\n";
    
    ivec.shrink_to_fit();
    
    cout << "capacity: "<<ivec.capacity() <<"\n";
    
    return 0;
}
=======================================
global compare functions
lexicographical_compare

2 5 7 8 9   //These are equal
2 5 7 8 9

2 5 7 8 9
2 5 90   // this is greater, because 90 is bigger than 7

Ex 1:
using namespace std;

int main(int argc, char* argv[])
{
   vector<int> x{10,20,30,50};
   vector<int> y{35};

    cout<<boolalpha << (y > x) << "\n"; // True
    return 0;
}

Ex 2:
using namespace std;

int main(int argc, char* argv[])
{
   vector<int> x{1,2,3,4};
   vector<int> y{1,2,3};

    cout<<boolalpha << (y > x) << "\n"; // false, because x has one more item. This happens because until x's last item, numbers are equal.
    return 0;
}

=======================================
addition and deletion operations

vec.push_back(10); //O(1)

C++ 11
perfect forwarding
most commonly used in emplace operations, greatly reduces cost of operation

*/
#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
   vector<int> x{1,2,3,4};
}
