/*
------------------------------------
35.Ders
Video başlığı:stl (Standard Template Library) 5, lambda expressions 2, linear search algorithms, erase operations, replace operations, container classes 1
------------------------------------
IIFE
------------------------------------

C++14
Generalized lambda expressions
Ex 1:
int main(int argc, char* argv[])
{
    auto f = [](auto x, auto y) { return x * y; };
    return 0;
}

//Representation
class comp_gen
{
public:
    template <typename T, typename U>
    auto func(T x, T y)
    {
        return x * y;
    }
};

Ex 2:
int main(int argc, char* argv[])
{
    auto f = [](auto &x, auto &y) { return x * y; };
    return 0;
}

//Representation
class comp_gen
{
public:
    template <typename T, typename U>
    auto func(T &x, T &y)
    {
        return x * y;
    }
};
stateless lambda??

C++ 20 öncesinde lambda closure type olan sınıfların default ctor ve atama op. fonksiyonları delete edilmiş idi.
Stateless lambdalar için artık yukarıdaki kurallar geçerli değil.

int main(int argc, char* argv[])
{
    auto fx = [](int x) { return x * x; };

    decltype(fx) fy;
    fx = fy; //C++20'de gecerli
    return 0;
}

============================================================================================================
Linear Search algorithms
find
find_if
find_if_not
transform
for_each
=======================================
STL'deki silme algoritmaları
Hiçbir algoritma bir aralıktan öğe silemez

erase
pop_back
pop_front
unique
============================================================================================================
vector class (General purpose dynamic array)
string class

container interface:

con.size()
con.empty();
con.clear()

con.front()
con.back()
*/

#include <algorithm>


//stateless lambda
int main(int argc, char* argv[])
{
    return 0;
}
