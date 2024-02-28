#include<iostream>
using namespace  std;

class Date
{
    public:
    Date(int year=2024,int month=2,int day=27);
    Date(const Date&d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);

	// d1 - 100
	Date operator-(int day);

	// d1 - d2;
	int operator-(const Date& d);

	// ++d1
	Date& operator++();

	// d1++
	// int参数 仅仅是为了占位，跟前置重载区分
	Date operator++(int);
    void Print();

    private:
    int _year;
    int _month;
    int _day;
};
int GetMonthXDay(int year,int month);