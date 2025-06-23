#pragma once
#include <iostream>
using namespace std;

class date {
private:
    int _year;
    int _month;
    int _day;

public:
    int GetMonthDay(int year, int month) const;

    date(int year = 2000, int month = 2, int day = 10);
    date(const date& d);

    bool operator==(const date& d) const;
    bool operator>(const date& d) const;
    bool operator<(const date& d) const;
    bool operator>=(const date& d) const;
    bool operator<=(const date& d) const;
    bool operator!=(const date& d) const;

    date& operator=(const date& d);
    date& operator+=(const int day);
    date operator+(const int day) const;
    date& operator++();
    date operator++(int);
    date& operator-=(const int day);
    date operator-(const int day) const;
    date& operator--();
    date operator--(int);
    int operator-(const date& d) const;

    date* operator&();
    const date* operator&() const;

    void print() const;
};