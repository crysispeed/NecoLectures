/*
------------------------------------
Lesson 48
Title: stl (Standard Template Library) 17, i/o stream 3, iostringstream, Read/Write operations and exception handling, ifstream
-----------------
Things to learn after lessons end (Which is this lesson :()
C++11
    regex
    random
    chrono
C++17
    string_view
    user-defined literals
    optional
    variant
    any
    concurrency (async programming)
        thread
        mutex
-----------------


Creating a log file
////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string get_logfile_name()
{
    ostringstream oss;
    time_t timer;
    time(&timer);

    auto p = localtime(&timer);
    oss.fill('0');
    oss << p->tm_year + 1900 << "_" << setw(2) << p->tm_mon + 1 << "_" << setw(2) << p->tm_mday << "_" << setw(2) << p->tm_hour << "_" << setw(2) << p->tm_min << "_"
    << setw(2) << p->tm_sec << ".log";
    return oss.str();
}

int main(int argc, char* argv[])
{
    //2021_02_11_17_04_45.log
    //2021_02_11_17_06_12.log
    ofstream ofs {get_logfile_name()};
    
    return 0;
}

////////////////////////////////////////////////
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class date
{
public:
    date (int d, int m, int y) : md{d}, mm{m}, my{y}
    {

    }

    friend ostream& operator<<(ostream& os, const date& dx)
    {
        ostringstream oss;
        oss << dx.md << "-" << dx.mm << "-" << dx.my;
        return oss;
        // This will not do what we want, width will be only applicable for md
        // return os << dx.md << "-" << dx.mm << "-" << dx.my;
    }

private:
    int md, mm, my;
};


int main(int argc, char* argv[])
{
    date mydate(11,2,2021);
    cout << left;
    
    
    cout << setw(40) << mydate << "berk arda biren\n";
    
    return 0;
}

////////////////////////////////////////////////
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    string name {"kemalcaglar"};
    ostringstream oss;
    
    for (int i = 100; i < 110; ++i)
    {
        oss << setfill('0');
        oss << name << "_" << setw(4) << i << ".jpg";
        cout << oss.str() << "\n";
        
        // If oss is in for loop, no problem, because oss will be created everytime loop returns to beginning.
        // This is done because otherwise, strings will be created sequentially.
        oss.str("");
    }
    return 0;
}

////////////////////////////////////////////////
If we want to use every word individually that is inputted from console:

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    string sline;

    cout << "bir yazi girin: ";
    getline(cin, sline);
    cout << "[" << sline << "]\n";
    istringstream iss(sline);
    string word;

    while (iss >> word)
    {
        cout << word << "\n";
    }
    
    return 0;
}

////////////////////////////////////////////////
#include <sstream>
#include <iomanip>
#include <iostream>
#include "nutility.h"
#include <algorithm>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{
    vector<string> svec;
    fc(svec, 100, rname);

    ofstream ofs {"out.txt"};
    if(!ofs)
    {
        cerr << "couldn't create file.";
        exit(EXIT_FAILURE);
    }
    
    copy(svec.begin(), svec.end(),  ostream_iterator<string>{ofs, "\n"});
    
    return 0;
}
====================================
Read/Write operations and exception handling

#include <iostream>
#include "nutility.h"

using namespace std;


int main(int argc, char* argv[])
{
    int x = 45;
    cout << "bir tamsayi girin : ";
    // This will not throw exception when exception happens
    // try
    // {
    //     cin >> x;
    // }
    // catch (exception& ex)
    // {
    //     cout << "Hata yakalandi : " << ex.what() << "\n";
    // }

    // On default, cin is designed for not throwing exceptions. We can set exception throwing using this function.
    cin.exceptions(ios::failbit);
    try
    {
        cin >> x;
    }
    catch (exception& ex)
    {
        cout << "Hata yakalandi : " << ex.what() << "\n";
    }
    
    cout << "x = " << x << "\n";

    
    return 0;
}
////////////////////////////////////////////////
====================================
File streams

#include <fstream>
#include <iostream>
#include "nutility.h"

using namespace std;

//ios_base::in
//ios_base::out
//ios_base::trunc
//ios_base::app
//ios_base::ate
//ios_base::binary

int main(int argc, char* argv[])
{
    // ifstream ifs{"ali.txt", ios::in};
    ifstream ifs{"ali.txt"};
    
    // ofstream ofs{"neco.txt", ios::out | ios::trunc};
    ofstream ofs{"neco.txt"};
    
    // fstream fs{"kemal.txt", ios::in, ios::out};
    fstream fs{"kemal.txt"};

    
    return 0;
}
////////////////////////////////////////////////

*/
#include <complex>
#include <fstream>
#include <iostream>
#include "nutility.h"

using namespace std;

//ios_base::in
//ios_base::out
//ios_base::trunc
//ios_base::app
//ios_base::ate
//ios_base::binary

int main(int argc, char* argv[])
{
    /*// ifstream ifs{"ali.txt", ios::in};
    ifstream ifs{"ali.txt"};
    
    // ofstream ofs{"neco.txt", ios::out | ios::trunc};
    ofstream ofs{"neco.txt"};
    
    // fstream fs{"kemal.txt", ios::in, ios::out};
    fstream fs{"kemal.txt"};*/
    
    return 0;
}
////////////////////////////////////////////////