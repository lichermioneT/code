#include "date.h"
#include <iostream>
using namespace std;

const int date::monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int date::getMonthDay(int year, int month)
{
	int day = monthDays[month];
	if ((month == 2) && ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0)))
	{
		day += 1;
	}
	return day;
}


date::date(int year, int month, int day)
	:_year(year)
	, _month(month)
	, _day(day)
{
	cout << " date::date(int year, int month, int day  " << endl;
	if (_day <= getMonthDay(_year, _month))
	{
		cout << "初始化成�? " << endl;
	}
	else
	{
		cout << "初始化失�?" << endl;
		exit(-1);
	}
}

date::date(const date& other)
{
	_year = other._year;
	_month = other._month;
	_day = other._year;
}

date& date::operator=(const date& other)
{
	if (this != &other)
	{
		_year = other._year;
		_month = other._month;
		_day = other._year;
	}
	return *this;
}


date:: ~date()
{
	cout << "~date()" << endl;
}


