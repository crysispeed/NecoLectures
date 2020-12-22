
/*
------------------------------------
32.Ders
Video başlığı: stl (Standard Template Library) 2, iterator, algorithms 1, iterator categories
-----------------
-----------------
Iterator

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

using cont = std::list<int>;

int main(){
    using namespace std;

    cont cx{1,5,7,9,12,3,4,5,6};
    for(auto iter = cx.begin();iter != cx.end(); ++iter)
    {
        cout << *iter << " ";
    }
}

iterator kategorisi iterator interface'ini belirliyor. (O iterator ile ne yapabiliriz, ++, -- gibi)
input iterator
copy constuctible

++it it--
*it it->    (R value)
it1==it2    it1 !? it2


- output iterator
copy constuctible
++it it++
*it it-> (L value)

- forward iterator
copy constuctible, default constructible
++it it++
*it it->  (l value, r value)
it1 == it2  it1 != it2

- bidirectional iterator
copy constuctible, default constructible
++it it++   --it it--
*it it->  (l value, r value)
it1 == it2  it1 != it2

- random_access_iterator
copy constuctible, default constructible
++it it++   --it it--
*it it->  (l value, r value)
it1 == it2  it1 != it2
it + n  n + it  it - n...
==================
Algorithm

#include <algorithm> // %95'i burada
#include <numeric>  //%5'i burada
 */

int main(int argc, char* argv[])
{
    
    return 0;
}
