#pragma once
class date
{
public:
	date(int year = 1, int month = 1, int day = 1);
	date(const date& other);
	date& operator=(const date& other);
	~date();

private:
	int getMonthDay(int month, int day);
private:
	int _year;
	int _month;
	int _day;
	static const int monthDays[];
};

