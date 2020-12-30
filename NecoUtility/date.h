#pragma once

#include <exception>
#include <iosfwd>

class bad_date : public std::exception {
public:

};

class Date {
public:
	Date() = default;
	Date(int d, int m, int y)
	{
		set(d, m, y);
	}

	Date(const char* p);

	//accessors
	constexpr int month()const { return m_; };
	constexpr int year()const { return y_; };
	constexpr int month_day()const { return d_; };

	constexpr int week_day()const
	{
		// array with leading number of days values 
		const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

		// if month is less than 3 reduce year by 1 
		int y = y_;
		if (m_ < 3)
			--y;

		return ((y + y / 4 - y / 100 + y / 400 + t[m_ - 1] + d_) % 7);
	}

	constexpr int year_day()const
	{
		int sum = d_;
		for (int i = 1; i < m_; ++i)
			sum += daytabs[static_cast<int>(isleap(y_))][i];
		return sum;
	}


	friend constexpr bool operator<(const Date& d1, const Date& d2)
	{
		return d1.y_ != d2.y_ ? d1.y_ < d2.y_ :
			d1.m_ != d2.m_ ? d1.m_ < d2.m_ :
			d1.d_ < d2.d_;
	}

	friend constexpr bool operator==(const Date& d1, const Date& d2)
	{
		return d1.y_ == d2.y_ && d1.m_ == d2.m_ && d1.d_ == d2.d_;
	}

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	constexpr friend int operator-(const Date& d1, const Date& d2)
	{
		return d1.totaldays() - d2.totaldays();
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
	//public static functions
	static Date random();

private:
	int d_{ 1 }, m_{ 1 }, y_{ 1900 };
	static constexpr int yearbase = 1900;
	static constexpr bool isleap(int y) { return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); }
	static constexpr bool isvalid(int d, int m, int y)
	{
		return y >= yearbase && m > 0 && m <= 12 && d > 0 && d <= daytabs[static_cast<int>(isleap(y))][m];
	}

	inline static constexpr int daytabs[][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};

	constexpr int totaldays()const
	{
		return (y_ - 1900) * 365 + (y_ - 1901) / 4 + year_day();
	}

	Date& set(int d, int m, int y)
	{
		if (!isvalid(d, m, y))
			throw bad_date{};
		d_ = d, m_ = m, y_ = y;
		return *this;
	}

};

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
constexpr bool operator>(const Date& d1, const Date& d2)
{
	return d2 < d1;
}
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
constexpr bool operator>=(const Date& d1, const Date& d2)
{
	return !(d1 < d2);
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

constexpr bool operator<=(const Date& d1, const Date& d2)
{
	return !(d2 < d1);
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

constexpr bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

