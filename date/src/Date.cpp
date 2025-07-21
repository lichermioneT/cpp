#include "Date.h"

int date::GetMonthDay(int year, int month) const 
{
    static const int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
        return 29;
    return months[month - 1];
}

// 构造函数
date::date(int year, int month, int day) 
{
    if (year >= 0 && month >= 1 && month <= 12 && day > 0 && day <= GetMonthDay(year, month))
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    } 
    else 
    {
        cout << "日期初始化有误" << endl;
    }
}

// 拷贝构造
date::date(const date& d) 
{
    this->_year = d._year;
    this->_month = d._month;
    this->_day = d._day;
}

// 复制构造
date& date::operator=(const date& d)
{
    if (this != &d) 
    {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;
    }
    return *this;
}

// 运算符重载
bool date::operator==(const date& d) const
{
    return this->_year == d._year && this->_month == d._month && this->_day == d._day;
}

bool date::operator>(const date& d) const 
{
    return this->_year > d._year || 
          (this->_year == d._year && this->_month > d._month) ||
          (this->_year == d._year && this->_month == d._month && this->_day > d._day);
}

bool date::operator<(const date& d) const 
{
    return d > *this;
}

bool date::operator>=(const date& d) const
 {
    return !(*this < d);
}

bool date::operator<=(const date& d) const
{
    return !(*this > d);
}

bool date::operator!=(const date& d) const
{
    return !(*this == d);
}


date& date::operator+=(const int day)
{
    if(day < 0)
    {
        return (*this-=-day);
    }
    this->_day += day;
    while (this->_day > GetMonthDay(_year, _month))
    {
        this->_day -= GetMonthDay(_year, _month);
        this->_month++;
        if (this->_month > 12) 
        {
            this->_year++;
            this->_month = 1;
        }
    }
    return *this;
}

date date::operator+(const int day) const 
{
    date d(*this);
    if(day < 0)
    {
        d -= -day;
        return d;
    }
    d += day;
    return d;
}


date& date::operator-=(const int day) 
{
    if(day < 0)
    {
        return *this += -day;
        return *this;
    }
    
    this->_day -= day;
    while (this->_day <= 0) 
    {
        this->_month--;
        if (this->_month <= 0) 
        {
            this->_year--;
            this->_month = 12;
        }
        this->_day += GetMonthDay(_year, _month);
    }
    return *this;
}

date date::operator-(const int day) const 
{
    date d(*this);
    if(day < 0)
    {
        d += -day;
    }
    d -= day;
    return d;
}


// 前置++
date& date::operator++() 
{
    *this += 1;
    return *this;
}
// 后置++
date date::operator++(int) 
{
    date temp(*this);
    *this += 1;
    return temp;
}


date& date::operator--() 
{
    *this -= 1;
    return *this;
}

date date::operator--(int) 
{
    date temp(*this);
    *this -= 1;
    return temp;
}

int date::operator-(const date& d) const 
{
    date max = *this;
    date min = d;
    if (*this < d) {
        max = d;
        min = *this;
    }
    int n = 0;
    while (min != max) {
        ++min;
        ++n;
    }
    return n;
}




date* date::operator&() 
{
    return this;
}

const date* date::operator&() const 
{
    return this;
}

void date::print() const 
{
    cout << _year << " - " << _month << " - " << _day << endl;
}