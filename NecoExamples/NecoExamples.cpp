#include <iostream>
#include <memory>
#include <list>
#include <numeric>
template<typename T, typename A = std::allocator<T>>
class Vector
{
public:
    class iterator
    {
    public:
        T& operator*();
        T *operator->();
        void operator++();
        void operator--();
    };
};

template <typename Iter, typename F>
int Count_if(Iter beg, Iter end, F pred)
{
    int cnt{};

    while(beg != end)
    {
        if(pred(*beg))
        {
            ++cnt;
        }
        ++beg;
    }
}

using cont = std::list<int>;

int main(){

    using namespace std;
    cont cx{1,5,7,9,12,3,4,5,6};
    auto a = count(cx.begin(), cx.end(), 3);
    cout << a << "\n";

    int b = 10;
    
    for(auto iter = cx.begin();iter != cx.end(); ++iter)
    {
        cout << *iter << " ";
    }
}
