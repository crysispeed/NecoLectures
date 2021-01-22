/*
------------------------------------
Lesson 42
Title: stl (Standard Template Library) 12, reference_wrapper class 2, tuple, function adapters: std::bind, not_fn, mem_fn
-----------------
-----------------
Tuple:
Mostly used for returning variable number of variables and objects.

#include <functional>
#include <iostream>
#include <tuple>
#include "date.h"

using namespace std;

int main(int argc, char* argv[])
{
    tuple<int, double, string, Date> tx;

    ++get<0>(tx);
    get<2>(tx) = "can";
    
    cout << get<0>(tx) << "\n";
    cout << get<1>(tx) << "\n";
    cout << get<2>(tx) << "\n";
    cout << get<3>(tx) << "\n";
    return 0;
}
===================
Example 1:
int main(int argc, char* argv[])
{
    tuple<int, double, string, Date> tx;

    get<int>(tx) = 45; //Give me the int value of the tuple. If there are more than 1 int, syntax error will happen
    get<double>(tx) = 4,5;//Give me the double value of the tuple. If there are more than 1 double, syntax error will happen
    return 0;
}

Example 2:
#include <tuple>
#include "date.h"

using namespace std;

using age = int;
using name = string;
using bdate = Date;

int main(int argc, char* argv[])
{
    tuple<age, name, bdate> tx = {25, "Kemal Çağlar", {12, 5, 1995}};

    get<age>(tx) = 45; 
    return 0;
}

#include <tuple>
#include "date.h"

using namespace std;

using age = int;
using name = string;
using bdate = Date;

int main(int argc, char* argv[])
{
    int x{14};
    string str{"alican"};

    auto tx = make_tuple(1.2f, 3.4 ,ref(str), x);

    get<2>(tx) = "hayrettin";
    
    return 0;
}
===================

Caution:
#include <tuple>
#include "date.h"

using namespace std;

using age = int;
using name = string;
using bdate = Date;

int main(int argc, char* argv[])
{
    tuple tx = {25, "Kemal Çağlar", {12, 5, 1995}};

    cout << get<0>(tx) << "\n";
    cout << get<1>(tx) << "\n"; // This will be char*, not string
    cout << get<2>(tx) << "\n";
    
    return 0;
}

======================================
not_fn:

#include <functional>
#include <iostream>
#include <tuple>
#include "date.h"
#include "nutility.h"

using namespace std;

using age = int;
using name = string;
using bdate = Date;

tuple <int, double, string, Date> func();

int main(int argc, char* argv[])
{
    vector<string> svec;
    fc(svec, 100, rname());
    int len;

    cout << "uzunluk degerini girin: ";
    cin >> len;

    auto f = [len](const string &s) {return s.length() == len; };

    copy_if(svec.begin(), svec.end(), ostream_iterator<string>{cout, " "}, not_fn(f));
    
    return 0;
}


 */

#include <functional>
#include <iostream>
#include <tuple>
#include "date.h"
#include "nutility.h"

using namespace std;

using age = int;
using name = string;
using bdate = Date;

tuple <int, double, string, Date> func();

int main(int argc, char* argv[])
{
    vector<string> svec;
    fc(svec, 100, rname());
    int len;

    cout << "uzunluk degerini girin: ";
    cin >> len;

    auto f = [len](const string &s) {return s.length() == len; };

    copy_if(svec.begin(), svec.end(), ostream_iterator<string>{cout, " "}, not_fn(f));
    
    return 0;
}
