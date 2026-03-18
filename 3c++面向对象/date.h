#pragma once
class date
{
public:
	date(int year = 1, int month = 1, int day = 1);
	date(const date& other);
	date& operator=(const date& other);
	~date();
public:
	date* operator*()
	{
		//return this;
		return nullptr;
	}

	const date* operator*() const 
	{
		//return this;
		return nullptr;
	}
public:
	date& operator+=(int day);
	date operator+(int day) const;
	date& operator-=(int day);
	date operator-(int day) const;
public:
	int operator-(const date& other)const;
public:
	date& operator++();
	date operator++(int);
	date& operator--();
	date operator--(int);
public:
	bool operator==(const date& other)const;
	bool operator>(const date& other)const;
	bool operator>=(const date& other)const;
	bool operator<(const date& other)const;
	bool operator<=(const date& other)const;
	bool operator!=(const date& other)const;

public:
	void print() const;
private:
	static int getMonthDay(int month, int day);
private:
	int _year;
	int _month;
	int _day;
	static const int monthDays[];
};

