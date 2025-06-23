#include<iostream>

using namespace std;

class date
{
public:
    int getmonthday(int year, int month)
    {
        static int days_in_month[12] = 
        {
        31, // 1月
        28, // 2月
        31, // 3月
        30, // 4月
        31, // 5月
        30, // 6月
        31, // 7月
        31, // 8月
        30, // 9月
        31, // 10月
        30, // 11月
        31  // 12月
        };

        if(year >= 0 && month > 0 && month <= 12)
        {
            if( month ==2 &&((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
            {
                return 29;
            }

            else
            {
                return days_in_month[month - 1];
            }
        }
        else
        {
            cout<< "日期初始化有误" <<endl;
        }
    }


    date(int year = 2000, int month = 2, int day = 10)
        :_year(year)
        ,_month(month)
        ,_day(day)
    {

    }

    void print() const
    {
        cout<< this->_year << " " << this->_month << " " << this->_day <<endl;
    }

    // 用d这和对象初始化*this对象
    date(const date& d) 
    {
        if(this  !=  &d)
        {
            this->_day = d._day;
            this->_month = d._month;
            this->_year = d._year;
        }
    }

    // 日期加天数
    date& operator+(int days)
    {
        this->_day += days;
        while(this->_day > getmonthday(this->_year, this->_month))
        {
            this->_day -= getmonthday(this->_year, this->_month);
            this->_month += 1;
            if(this->_month == 12)
            {
                this->_year += 1;
                this->_month = 1;
            }
        }

        return *this;
    }






private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    date d(2,2,2);
    d.print();

// 下面都是拷贝构造
    date d2(d);
    d2.print();
    date d3 = d;
    d3.print();

// 
   





    
}
