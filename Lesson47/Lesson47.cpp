/*
------------------------------------
Lesson 47
Title: stl (Standard Template Library) 17, i/o stream 2, format state, condition state of stream
-----------------
-----------------
Formatting

format state
fmtflags is an integer value that holds flags for formats.
ex: on-off flags
0 - 1 (if turned off)
true - false (if turned on)

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //cout.flags() | ios::boolalpha;
    cout.setf(ios::boolalpha);
    
    cout << (10 > 5) << "\n";

    // cout.flags(cout.flags & ~ios::boolalpha);
    cout.unsetf(ios::boolalpha);
    
    cout << (10 > 5) << "\n";

    return 0;
}
////////////////////////////////////////////////

#include <iostream>

using namespace std;

//ios.showpos

int main(int argc, char* argv[])
{
    int x = 10;
    
    cout << x << "\n";
    cout.setf(ios::showpos);
    cout << x << "\n";
    return 0;
}

////////////////////////////////////////////////

#include <iostream>

using namespace std;

//ios.showbase
//ios.uppercase

int main(int argc, char* argv[])
{
    int x = 47802;
    cout << hex;
    cout << x << "\n";
    
    cout.setf(ios::showbase);
    cout.setf(ios::uppercase);
    cout << x << "\n";
    return 0;
}

////////////////////////////////////////////////

#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << bitset<32>(ios::showpos) << "\n";
    cout << bitset<32>(ios::boolalpha) << "\n";
    cout << bitset<32>(ios::showpoint) << "\n";
    return 0;
}

////////////////////////////////////////////////

// If you want to know if te flag is set or not:
#include <bitset>
#include <iostream>

using namespace std;

void func(ostream& os)
{
    if(os.flags() & ios::boolalpha)
    {
        cout << "Will write as true false";
    }
    else
    {
        cout << "Will write as 0 1";
    }
}

int main(int argc, char* argv[])
{
    cout.setf(ios::boolalpha);
    func(cout);
    return 0;
}
////////////////////////////////////////////////

Which number system will be used:
hex
oct
dec
0000000000000abc0000000

ios::base_field
00000000000001110000000

#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int x = 47802;
    cout << x << "\n";
    //cout.setf(ios::hex) // you will only set hex flag, the other number system flags will not be reset.
    cout.setf(ios::hex, ios::basefield);
    cout << x << "\n";
    cout.setf(ios::oct, ios::basefield);
    cout << x << "\n";
    cout.setf(ios::dec, ios::basefield);
    cout << x << "\n";
    
    return 0;
}

////////////////////////////////////////////////
// If there are more than one number system flag is set, it will print dex as default:

#include <bitset>
#include <iostream>

using namespace std;

void show_base_flags(ios_base& ib)
{
    if(ib.flags() & ios_base::dec)
    {
        cout << "dec is set\n";
    }

    if(ib.flags() & ios_base::hex)
    {
        cout << "hex is set\n";
    }

    if(ib.flags() & ios_base::oct)
    {
        cout << "oct is set\n";
    }
}

int main(int argc, char* argv[])
{
    show_base_flags(cout);
    cout.setf(ios::hex);
    show_base_flags(cout);

    cout << 47802 << "\n"; // 
    
    return 0;
}
////////////////////////////////////////////////

#include <bitset>
#include <iostream>

using namespace std;

//float_field / 3 types:
// 1 and 2 Depends on the bigness of the number
// 1) ios::fixed         12.7654
// 2) ios::scientific    1.2e5
// 3) ios::hex

void print_float_flags(ios_base& ib)
{
    if(ib.flags() & ios::scientific)
    {
        cout << "Scientific is set.\n";
    }
    else
    {
        cout << "Scientific is not set.\n";
    }
    
    if(ib.flags() & ios::fixed)
    {
        cout << "Fixed is set.\n";
    }
    else
    {
        cout << "Fixed is not set.\n";
    }
}

int main()
{
    print_float_flags(cout);
    cout.setf(ios::fixed, ios::floatfield);
    
    cout << 73.12;
    cout << 3523652363262362.2352352351251251;
    
    cout.setf(ios::scientific, ios::floatfield);
    cout << 73.12;
    cout << 3523652363262362.2352352351251251;

    // If both flag is set, it will use as hexadecimal
    cout.setf(ios::scientific | ios::fixed);
    cout << 73.12;
    cout << 3523652363262362.2352352351251251;
    return 0;
}

====================================

witdh (width of the write field)
    ios::left
    ios::right
    ios::internal
    ios::ajustfield

#include <iostream>
#include "nutility.h"

using namespace std;


int main()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.fill('.');
    
    for(int i = 0; i < 10; ++i)
    {
        cout.width(12);// This width is only applicable for first << usage. That is why we are setting in loop.
        cout << Irand(0, 99999)() << rname() << "\n";
    }
    return 0;
}

====================================
Manipulator
    ostream manipulator
    istream manipulator

cout << endl

class ostream{
public:
    ostream& operator<<(int);
    ostream& operator<<(double);
    ostream& operator<<(void *);

    ostream& operator<<(ostream&(*fp)(ostream&)) // Manipulator
    {
        
    }
    
};

////////////////////////////////////////////////

#include <iostream>
#include "nutility.h"

using namespace std;

ostream& myendl(ostream& os)
{
    os.put('\n');
    os.flush();
    return os;
}

int main()
{
    cout << 123 << myendl << 198 << myendl;
    return 0;
}

////////////////////////////////////////////////
// Manipulator with parameter
#include <iostream>
#include "nutility.h"

using namespace std;

class ps
{
public:
    ps(int val) : mval{val}
    {
        
    }

    friend ostream& operator<<(ostream& os, const ps& x)
    {
        int n = x.mval;
        while (n--)
        {
            os.put(' ');
        }
        return os;
    }
private:
    int mval;
};

int main()
{
    int x = 34, y = 8676, z = 3534523;
    cout << x << ps(5) << y << ps(12) << z << ps(23) << "aysegul\n";
    return 0;
}
====================================
condition state of stream

iostate
ios::goodbit
ios::badbit
ios::failbit
ios::eofbit
////////////////////////////////////////////////
#include <bitset>
#include <iostream>
#include "nutility.h"

using namespace std;


int main()
{
    cout << (bitset<16>(ios::goodbit)) << "\n";
    cout << (bitset<16>(ios::eofbit)) << "\n";
    cout << (bitset<16>(ios::failbit)) << "\n";
    cout << (bitset<16>(ios::badbit)) << "\n";
    return 0;
}

////////////////////////////////////////////////
#include <iostream>
#include "nutility.h"

using namespace std;

void print_condition_state(ios& x)
{
    if(x.rdstate() == 0)
    {
        cout << "stream is fine\n";
        return;
    }

    if(x.rdstate() & ios::eofbit)
    {
        cout << "eofbit is set\n";
    }

    if(x.rdstate() & ios::failbit)
    {
        cout << "failbit is set\n";
    }

    if(x.rdstate() & ios::badbit)
    {
        cout << "badbit is set\n";
    }
}

int main()
{
    print_condition_state(cin);
    int x{};

    cout << "Enter an integer: ";
    cin >> x;
    print_condition_state(cin);
    
    return 0;
}

////////////////////////////////////////////////
#include <iostream>
#include "nutility.h"

using namespace std;

int main()
{
    int x{};

    cout << "Enter an integer: ";
    cin >> x;

    cout << boolalpha;

    cout << "cin.operator bool()    = " << (cin ? "true" : "false") << "\n";
    cout << "cin.fail()             = " << (cin.fail() ? "true" : "false") << "\n";
    cout << "!cin.operator!()       = " << (!cin ? "true" : "false") << "\n";
    cout << "cin.eof()              = " << (cin.eof() ? "true" : "false") << "\n";
    cout << "cin.bad()              = " << (cin.bad() ? "true" : "false") << "\n";

    cin.clear(); // Resets error flags
    
    return 0;
////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main()
{
    int x{};

    // while(cin.operator>>(x).operator bool())
    while(cin >> x) // Calls operator bool func internally. When you enter wrong input, loop will end.
    {
        cout << "decimal: " << dec << x << "hex: " << hex << x << "octal: " << oct << x << "\n";
    }
    
    return 0;
}

====================================
I/O operations in memory (scanf, sprintf in C)

#include <sstream>
// ostringstream ==> ostream   bellek üstünde yazma işlemleri için
// istringstream ==> istream   bellek üstünde okuma işlemleri için
// stringstream  ==> iostream  bellek üstünde hem okuma hem yazma işlemleri için

////////////////////////////////////////////////
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int x = 12;
    double dval = 4.7643;
    string name = "kemal";
    ostringstream oss;

    
    oss << x << "_" << dval << "_" << name <<".txt";
    auto s = oss.str();

    cout << s.size() << "\n";
    cout << "[" << s << "]\n";
    return 0;
}
*/

////////////////////////////////////////////////
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int x = 12;
    double dval = 4.7643;
    string name = "kemal";
    ostringstream oss;

    
    oss << x << "_" << dval << "_" << name <<".txt";
    auto s = oss.str();

    cout << s.size() << "\n";
    cout << "[" << s << "]\n";
    return 0;
}
