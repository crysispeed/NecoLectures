/*
------------------------------------
37.Ders
Video başlığı:stl (Standard Template Library) 7, standard function objects (functors), sorting algorithms, partition algorithms, iterator invalidation
------------------------------------

------------------------------------
Function object:
class Functor
{
public:
   void operator()(int); // It overloaded function call operator,that is why it is functor
};

///////////////////////////////////////////////////

#include <vector>
#include <initializer_list>
#include <iostream>

template <typename T>
struct Plus
{
   T operator()(const T& tx, const T& ty) const
   {
      return tx + ty;
   }
};

template <typename T>
struct Less
{
   T operator()(const T& tx, const T& ty) const
   {
      return tx < ty;
   }
};

using namespace std;

int main(int argc, char* argv[])
{
   int a = 10, b = 20;
   //a + b

   Plus<int>{}(a,b);
}

For all these kind of functions, there is a class called "functional".

#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char* argv[])
{
   cout << multiplies<int>{}(10,20) << "\n";
   cout << negate<int>{}(10) << "\n";
}

///////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
   vector<string> x {"Ali", "Murat", "Kemal", "Yasar"};
   vector<string> y {"Ertas", "Aksoy", "Çağlar", "Erkaya"};
   vector<string> z(4);
   
   // transform(x.begin(), x.end(), y.begin(), z.begin(), [](const string &s1, const string& s2){return s1+s2;});
   transform(x.begin(), x.end(), y.begin(), z.begin(), plus<string>{});
}

=======================================

Sorting algorithms

- Can be callable for random access containers.

two types of overloads:

1) sort(svec.begin(), svec.end()) // calls less<> functor by default
2) sort(svec.begin(), svec.end(), func) // func is a binary preticate parameter function
ex:
   sort(svec.begin(), svec.end(), greater{]); // In modern C++, you do not need to specify type for greater<>.

Sortings can be:
1) Stable
1) Unstable
there is an sort algorithm: stable_sort

Ziya  49
Ahmet 23
Burak 19
Ahmet 16
Belma 40
Emine 55

Ahmet 16
Ahmet 23
Burak 19
Belma 40
Emine 55
Ziya  49

partial_sort // Sort a part of the container

=======================================

iterator invalidation

iter = container_position; //eg. *iter -> 3540 
iter.do_something();

a) Bu iterator dangling hale geliyorsa // Gösterdiği nesnenin hayatı bitmiş
   *iter //ub

b) iter'in gösterdiği değerin değişmesi



*/
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include "date.h"
using namespace std;

int main(int argc, char* argv[])
{
      
}
