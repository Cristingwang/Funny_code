#include "Date.h"
    Date::Date(int year,int month,int day)
    {
        _year=year;
        _month=month;
        _day=day;
    }
    Date::Date(const Date&d)
    {
        _year=d._year;
        _month=d._month;
        _day=d._day;
    }
    void Date::Print()
    {
        cout<<_year<<"/"<<_month<<"/"<<_day<<"/"<<endl;
    }
int GetMonthXDay(int year,int month)
{
    int montharr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month!=2)
    return montharr[month];
    else if((year%4==0&&year%100!=0)||year%400==0)
    return 29;
    else return 28;
}
int GetYearXDay(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        return 366;
    }
    else
    return 365;

}
	bool Date::operator==(const Date& d)
    {
        return _year==d._year
        &&_month==d._month
        &&_day==d._day;
    }
	bool Date::operator!=(const Date& d)
    {
        if((*this)==d)
        return false;
        else
        return true;
    }
	bool Date::operator<(const Date& d)
    {
        if(_year!=d._year)
        return _year<d._year;
        else if(_month!=d._month)
        return _month<d._month;
        else
        return _day<d._day;
    }
	bool Date::operator<=(const Date& d)
    {
        return *this<d||*this==d;
    }
	bool Date::operator>(const Date& d)
    {
        if(_year!=d._year)
        return _year>d._year;
        else if(_month!=d._month)
        return _month>d._month;
        else
        return _day>d._day;
    }
	bool Date::operator>=(const Date& d)
    {
        return *this>d||*this==d;
    }
	Date& Date::operator+=(int day)
    {
        _day+=day;
        while(_day>GetMonthXDay(_year,_month))
        {
            _day-=GetMonthXDay(_year,_month);
            _month++;
            if(_month==13)
            {
                _year++;
                _month=1;
            }
        }
        return *this;
    }
	Date Date::operator+(int day)
    {
        Date tmp=(*this);
        tmp+=day;
        return tmp;
    }
	Date& Date::operator-=(int day)
    {
        _day-=day;
        while(_day<0)
        {
            _day+=GetMonthXDay(_year,_month);
            _month-=1;
            if(_month==0)
            {
                _year-=1;
                _month=12;
            }
        }
        return *this;
    }
	Date Date::operator-(int day)
    {

        Date tmp=*this;
        tmp-=day;
        return tmp;
    }
	int Date::operator-(const Date& d)
    {
        if(*this>=d)
        {  
             int day=0,day1=0,day2=0;
                day1=_day;
                for(int i=_month-1;i>0;i--)
                {
                    day1+=GetMonthXDay(_year,i);
                }
                day1--;
                day2=d._day;
                for(int i=d._month-1;i>0;i--)
                {
                    day2+=GetMonthXDay(d._year,i);
                }
                day2--;
            for(int j=d._year;j<_year;j++)
            {
                day+=GetYearXDay(j);
            }
            day=day-day2+day1;
            return day;
        }
        else{
            return -1;
        }
    }
	Date& Date::operator++()
    {
        (*this)+=1;
        return (*this);
    }
	Date Date::operator++(int)
    {
        Date tmp=*this;
        (*this)+=1;
        return tmp;
    }