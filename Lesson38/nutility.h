#ifndef NUTILITY_H
#define NUTILITY_H


#include <random>
#include <string>
#include <iostream>
#include <set>
#include <forward_list>


class Irand {
public:
	Irand() = default;
	Irand(int min, int max) : m_dist{ min, max } {}
	int operator()();
private:
	std::uniform_int_distribution<int> m_dist;
};

class Drand {
public:
	Drand() = default;
	Drand(double dmin, double dmax) : m_dist{ dmin, dmax } {}
	double operator()();
private:
	std::uniform_real_distribution<double> m_dist;
};


void randomize();
std::string rname();
std::string rfname();
std::string rtown();
std::string rperson();

bool isprime(int val);

std::ostream& sl(std::ostream& os);
//--------------------------------------------------
//--------------------------------------------------
constexpr int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val != 0) {
		val /= 10;
		++digit_count;
	}

	return digit_count;
}
//--------------------------------------------------
//--------------------------------------------------
template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
	return os << "[" << p.first << ", " << p.second << "]";
}
//--------------------------------------------------
//--------------------------------------------------
template<typename C, typename F>
void fc(C& c, size_t n, F frand)
{
	while (c.size() < n)
		c.insert(c.end(), frand());
}
//--------------------------------------------------
//--------------------------------------------------
template<typename T, typename F>
void fc(std::forward_list<T>& c, size_t n, F frand)
{
	while (n--)
		c.insert_after(c.before_begin(), frand());
}


template<typename C>
void pc(const C& c, const char* p = " ", std::ostream& os = std::cout)
{
	for (const auto& elem : c)
		os << elem << p;
	os << sl;
}
//--------------------------------------------------
//--------------------------------------------------

template<typename InIter>
void pr(InIter beg, InIter end, const char* p = " ", std::ostream& os = std::cout)
{
	while (beg != end) {
		os << *beg++ << p;
	}
	os << sl;
}

//--------------------------------------------------
//--------------------------------------------------

template<typename C, typename F>
void fcs(C& c, size_t n, F func)
{
	std::set<typename C::value_type> s;
	while (s.size() != n)
		s.insert(func());
	c.assign(s.begin(), s.end());
}
//--------------------------------------------------
//--------------------------------------------------

void my_terminate();

#endif
