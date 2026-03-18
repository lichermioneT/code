#include "date.h"
#include <iostream>
#include <cstdlib>   

using namespace std;

const int date::monthDays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int date::getMonthDay(int year, int month)
{
    if (month < 1 || month > 12)
    {
        return -1;
    }
    int day = monthDays[month];
    // 修正闰年判断条件
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        day += 1;
    }
    return day;
}

date::date(int year, int month, int day)
    : _year(year)
    , _month(month)
    , _day(day)
{
    if (_month >= 1 && _month <= 12
        && _day >= 1
        && _day <= getMonthDay(_year, _month))
    {
        cout << "Initialization succeeded." << endl;
    }
    else
    {
        cout << "Initialization failed!" << endl;
        exit(-1);
    }
}

date::date(const date& other)
    :_year(other._year)
    ,_month(other._month)
    ,_day(other._day)
{
}

date& date::operator=(const date& other)
{
    if (this != &other)
    {
        _year = other._year;
        _month = other._month;
        _day = other._day;      // 修正：原来是 other._year
    }
    return *this;
}

date::~date()
{
    cout << "~date()" << endl;
}


date& date::operator+=(int day)
{
    if (day < 0)
    {
        return *this -= (-day);
    }

    _day += day;
    while (_day > getMonthDay(_year, _month))
    {
        _day -= getMonthDay(_year, _month);
        _month += 1;
        if (_month == 13)
        {
            _year += 1;
            _month = 1;
        }
    }
    return *this;
}

date date::operator+(int day) const
{
    date tmp(*this);
    return tmp += day;
}

date& date::operator-=(int day)
{
    if (day < 0)
    {
        return *this += (-day);
    }

    _day -= day;
    while (_day <= 0)
    {
        _month -= 1;
        if (_month == 0)
        {
            _year -= 1;
            _month = 12;
        }
        _day += getMonthDay(_year, _month);
    }
    return *this;
}

date date::operator-(int day) const
{
    date tmp(*this);
    return tmp -= day;
}

int date::operator-(const date& other) const
{
    if (*this == other)
    {
        return 0;
    }

    int count = 0;
    if (*this > other)
    {   
        date tmp(other);
        while (*this != tmp)
        {
            ++tmp;
            ++count;
        }
        return count;
    }
    else if (*this < other)
    {
        date tmp(*this);
        while (other != tmp)
        {
            ++tmp;
            ++count;
        }
        return -count;
    }
}


date& date::operator++()
{
    return *this += 1;
}

date date::operator++(int)
{
    date tmp(*this);
    *this += 1;
    return tmp;
}

date& date::operator--()
{
    return *this -= 1;
}

date date::operator--(int)
{
    date tmp(*this);
    *this -= 1;
    return tmp;
}

bool date::operator==(const date& other)const
{
    return _year == other._year
        && _month == other._month
        && _day == other._day;
}

bool date::operator>(const date& other)const
{
    return _year > other._year
        || (_year == other._year && _month > other._month)
        || (_year == other._year && _month == other._month && _day > other._day);
}

bool date::operator>=(const date& other)const
{
    return (*this > other || *this == other);
}

bool date::operator<(const date& other)const
{
    return !(*this >= other);
}

bool date::operator<=(const date& other)const
{
    return !(*this > other);
}

bool date::operator!=(const date& other)const
{
    return !(*this == other);
}


void date::print() const
{
    cout << _year << " " << _month << " " << _day << endl;
}
