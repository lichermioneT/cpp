#include "Date.h"

int date::GetMonthDay(int year, int month) const {
    static const int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
        return 29;
    return months[month - 1];
}

date::date(int year, int month, int day) {
    if (year >= 0 && month > 0 && month <= 12 && day > 0 && day <= GetMonthDay(year, month)) {
        _year = year;
        _month = month;
        _day = day;
    } else {
        cout << "日期初始化有误" << endl;
    }
}

date::date(const date& d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

bool date::operator==(const date& d) const {
    return _year == d._year && _month == d._month && _day == d._day;
}

bool date::operator>(const date& d) const {
    return _year > d._year || 
          (_year == d._year && _month > d._month) ||
          (_year == d._year && _month == d._month && _day > d._day);
}

bool date::operator<(const date& d) const {
    return d > *this;
}

bool date::operator>=(const date& d) const {
    return !(*this < d);
}

bool date::operator<=(const date& d) const {
    return !(*this > d);
}

bool date::operator!=(const date& d) const {
    return !(*this == d);
}

date& date::operator=(const date& d) {
    if (this != &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

date& date::operator+=(const int day) {
    if(day < 0)
    {
        return (*this-=-day);
    }
    _day += day;
    while (_day > GetMonthDay(_year, _month)) {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month > 12) {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

date date::operator+(const int day) const {
    date d(*this);
    if(day < 0)
    {
        d -= -day;
        return d;
    }
    d += day;
    return d;
}

date& date::operator++() {
    *this += 1;
    return *this;
}

date date::operator++(int) {
    date temp(*this);
    *this += 1;
    return temp;
}

date& date::operator-=(const int day) {
    if(day < 0)
    {
        return *this += -day;
        return *this;
    }
    
    _day -= day;
    while (_day <= 0) {
        _month--;
        if (_month <= 0) {
            _year--;
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

date date::operator-(const int day) const {
    date d(*this);
    if(day < 0)
    {
        d += -day;
    }
    d -= day;
    return d;
}

date& date::operator--() {
    *this -= 1;
    return *this;
}

date date::operator--(int) {
    date temp(*this);
    *this -= 1;
    return temp;
}

int date::operator-(const date& d) const {
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

date* date::operator&() {
    return this;
}

const date* date::operator&() const {
    return this;
}

void date::print() const {
    cout << _year << " - " << _month << " - " << _day << endl;
}