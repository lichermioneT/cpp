#include <iostream>
using namespace std;

class Date
{
public:
    int GetMonthsDays(int year, int month)
    {
      static int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
            if(month == 2 &&((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            {
                return 29;
            }
            else
           {
              return daysInMonth[month];
            }
    }

    Date(int year = 2000, int month = 2, int day = 10)
    {
        // 检查日期的合法性
        if(year >= 0 && month >= 1 && month <=12 && day >=1 && day <= GetMonthsDays(year, month))
        {

            this->_year = year;
            this->_month = month;
            this->_day = day;
        }
        else
        {
            cout<< " 日期初始化有误 " <<endl;
        }
    }
    
    ~Date()
    {
        //
    }

    Date(const Date & that)
    {
        this->_year = that._year;
        this->_month = that._month;
        this->_day = that._day;
    }
    
    void print()
    {
        cout<< this->_year << "-" << this->_month << "-" << this->_day <<endl;
    }


// 复制构造  k = j 连续复制，这里的返回值是k
    Date& operator=(const Date& that)
    {   
        if(this != &that)
        {
            this->_year = that._year;
            this->_month = that._month;
            this->_day = that._day;
        }
        return *this;
    }

// 运算符重载
    bool operator==(const Date& that) const
    {
        return this->_year == that._year &&
               this->_month == that._month &&
               this->_day == that._day;
    }
    
    bool operator>(const Date& that) const
    {
        return this->_year > that._year ||
               (this->_year == that._year && this->_month > that._month) ||
               (this->_year == that._year && this->_month == that._month && this->_day > that._day);
    }
    
    bool operator!=(const Date& that) const 
    {
        return !(*this==that);
    }
    
    bool operator<(const Date& that) const
    {
        return (that > *this);
    }
    
    bool operator>=(const Date& that) const
    {
        return (*this > that || *this == that);
    }
    
    bool operator<=(const Date& that) const
    {
        return (*this < that || *this == that);
    }
    

// d1 + 10 不能修改原来的值
    Date operator+(int n)
    {
        Date ret = *this;
        ret._day += n;
        while(ret._day > GetMonthsDays(ret._year, ret._month))
        {
            ret._day -= GetMonthsDays(ret._year, ret._month);
            ret._month++;
            if(ret._month == 13)
            {
                ret._year++;
                ret._month = 1;
            }
        }
        return ret;
    }

// d1 += 10;
    Date& operator+=(int n)
    {
        this->_day += n;
        while(this->_day > GetMonthsDays(this->_year, this->_month))
        {
            this->_day -= GetMonthsDays(this->_year, this->_month);
            this->_month++;
            if(this->_month == 13)
            {
                this->_month == 1;
                this->_year++;
            }
        }
        return *this;
    }

// d1 - 10
    Date operator-(int n)
    {
        Date ret = *this;
        // ret -= n;
        while(ret._day <= 0)
        {
            ret._month--;
            if(ret._month == 0)
            {
                ret._year--;
                ret._month = 12;
            }
            ret._day += GetMonthsDays(ret._year, ret._month);
        }
        return ret;
    }

// d1 -= 10
    Date& operator-=(int n)
    {
        this->_day -= n;
        while(this->_day <= 0)
        {
            this->_month--;
            if(this->_month == 0)
            {
                this->_year--;
                this->_month = 12;
            }
            this->_day += GetMonthsDays(this->_year, this->_month);
        }
        return *this;
    }

// ++d
    Date& operator++()
    {
        *this += 1;
        return *this;
    }

// d++
    Date operator++(int)
    {
        Date ret(*this);
        ret += 1;
        return ret;
    }

// --d
    Date& operator--()
    {
        *this -= 1;
        return *this;
    }
// d--
    Date operator--(int)
    {
        Date ret(*this);
        ret -= 1;
        return ret;
    }

// 日期减日期
    int operator-(const Date& that)
    {   
        int flag = 1;
        Date max = *this;
        Date min = that;
        if(*this < that)
        {
            max = that;
            min = *this;
            flag = -1;
        }
        
        int n = 0;
        while(min != max)
        {
            ++min;
            ++n;
        }
        return n * flag;
    }

private:
    int _year;
    int _month;
    int _day;
};


int main()
{

    Date d1(200,2,10);
    Date d2(d1);
    Date d3 = d1 + 55;
    d3.print();
    Date d4 = d3 - 55;
    d4.print();
    return 0;
}

