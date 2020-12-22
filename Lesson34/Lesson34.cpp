/*
------------------------------------
33.Ders
Video başlığı: stl (Standard Template Library) 4, iterator manipulation functions cont., ostream_iterators, lambda expressions
------------------------------------
IIFE
------------------------------------
iteratörler üzerinde işlem yapan global fonksiyon şablonları

advance (Lesson 33)
distance (Lesson 33)
next (C++ 11)
prev (C++ 11)
iter_swap

iter next(iter), iter next(iter, 3) iter'den sonra üçüncü iter
iter prev(iter), iter prev(iter, 3) iter'den önceki üçüncü iter:

int main(int argc, char* argv[])
{
    int a []= {12, 45, 12 ,65, 2, 6, 34, 8, 3};
    vector<int> ivec{1,2,3,4,5,6,7,8,9};
    auto iter = next(ivec.begin());
    auto iter2 = next(ivec.begin(), 4);

    cout << *iter << "\n";
    cout << *iter2 << "\n";
    
    return 0;
}

iter_swap: //iter'lerin içindeki verileri swap eder, iterlerin kendisini değil
template<Iter1, Iter2>
iter_swap (Iter1 x, Iter2 y)
{
    auto temp = *x;
    *x = *y;
    *y = *temp;
}

iterator types:
vector<int>::iterator (ivec.begin(), begin(ivec)) // end'ler için de geçerli
vector<int>::const_iterator (ivec.cbegin(), cbegin(ivec)) // end'ler için de geçerli
vector<int>::reverse_iterator (ivec.rbegin(), rbegin(ivec)) // end'ler için de geçerli
vector<int>::const_reverse_iterator (ivec.crbegin(), crbegin(ivec)) // end'ler için de geçerli
============================================================================================================
Lambda Expressions

Derleyiciye yazdırdığımız bir class'tan yaratılan bir geçici nesne yaratması ve ()'ı overload etmesi

int main(int argc, char* argv[])
{
    // Compiler'ın yaptığı
    class cmp_gen
    {
    public:
        void operator()(int x)
        {
            
        }
    };
    
    cmp_gen{}(1);
    
    //Lambda Expression
    [](int x)
    {
    }(1); // Fonksiyonun geri dönüş değeri, fonksiyonun içinde return edilen değer ile belirlenir. Yoksa void olur.
    return 0;
}
[capture close](parameter(s))->int {code}();
                ->double(return type)
                mutable
                noexcept
                constexpr
closure type: sınıfın türü
closure object: sınıftan yaratılan nesne

Örnek 1:
int main(int argc, char* argv[])
{
    auto f = [](int x){return x*x;}(20);
    cout << "f = " << f << "\n";
    return 0;
}

Örnek 2:
int main(int argc, char* argv[])
{
    auto f = [](int x){return x*x;};
    cout << "f = " << f(12) << "\n";
    cout << "f = " << f(20) << "\n";
    cout << "f = " << f(13) << "\n";
    return 0;
}

Örnek 3:

int main(int argc, char* argv[])
{
    int a = 30; // Normalde expression'ın code body'sinde bir variable kullanmamız için variable global olmalı
                //ama köşeli parantezin içine bu değeri vererek aşağıdaki şekilde kodu compiler'a yazdırabiliriz:

    class cmp_gen
    {
    private:
    int ma = a;
    public:
        cmp_gen(int a):ma{a}{}
        int operator()(int x)
        {
            return x*x;
        }
    };
    
    auto f = [a](int x){return x*x;};
    
    cout << "f = " << f(12) << "\n";
    cout << "f = " << f(20) << "\n";
    cout << "f = " << f(13) << "\n";
    return 0;
}

[=](){}Visible olan local scope'taki tüm isimleri kopyalanmış olarak kullanabilirsin demek (capture all by copy)
[&](){}Visible olan local scope'taki tüm isimleri referans olarak kullanabilirsin demek (capture all by reference)
[=, &x](){}(capture all by copy but x by reference)
[&, x](){}(capture all by reference but x by copy)

*/

#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    int a = 30; // Normalde global olmalı ama köşeli parantezin içine bu değeri vererek aşağıdaki şekilde kodu compiler'a yazdırabiliriz:

    class cmp_gen
    {
    private:
    int ma = a;
    public:
        cmp_gen(int a):ma{a}{}
        int operator()(int x)
        {
            return x*x;
        }
    };
    
    auto f = [a](int x){return x*x;};
    
    cout << "f = " << f(12) << "\n";
    cout << "f = " << f(20) << "\n";
    cout << "f = " << f(13) << "\n";
    return 0;
}
