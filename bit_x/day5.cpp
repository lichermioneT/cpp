#include<iostream>
using namespace std;

/*
class Stack
{
public:
    Stack(int n = 10)
    {
        _a = (int*)malloc(sizeof(int) * n);
        _size = 0;
        _capacity = n;
    }

    ~Stack()
    {
        free(_a);
        _a = nullptr;
        _size = _capacity = 0;
    }
private:
    int* _a;
    int _size;
    int _capacity;
};

class date
{
public:
    date(int year = 2000, int month = 2, int day = 10)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    date(const date& that)
    {
        _year = that._year;
        _month = that._month;
        _day = that._day;
    }

    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }

    // i = j = k;
    // d3 = d1返回值是d3,能够支持连续赋值
    // 运算符重载就是为了让自定义类型像内置类型运算
    date& operator=(const date& that)
    {
        if(this != &that) // 针对自己给自己赋值的检查判断
        {
            _year = that._year;
            _month = that._month;
            _day = that._day;
        }
        return *this;
    }

private:
    int _year;
    int _month;
    int _day;

};

*/


class date
{

public:
    int getMonthDaY(int year, int month)
    {
        static const int monthdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 改为 const，记住闰年判断的条件，创建一个静态数组
        if(month == 2 && ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0))
        {
            return 29;
        }
        else
        {
            return monthdays[month];
        }
    }

    date(int year = 2000, int month = 2, int day = 10)
    {
        if(year >=0 && month >=1 && month <=12 && day >= 1 && day <= getMonthDaY(year, month))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout<< " 初始化时间有误 " << endl;
        }
    }

    date(const date& that)
    {
        _year = that._year;
        _month =  that._month;
        _day = that._day;
    }

// 运算符重载
    // 这里函数声明就是为了 const date* this
    // 不会改变this指向对象的成员变量
    // 实现两个，后面的实现就去复用
    bool operator==(const date& that) const
    {
        return _year == that._year&&
               _month == that._month&&
               _day == that._day;
    }

    bool operator>(const date& that) const
    {
        return _year > that._year ||
               _year  == that._year && _month > that._month ||
               _year == that._year && _month == that._month && _day > that._day;
    }

    bool operator<(const date& that) const
    {
        return that > *this;
    }

    bool operator>=(const date& that) const
    {
        return !(*this < that);
    }

    bool operator<=(const date& that) const
    {
        return !(*this > that);
    }

    bool operator!=(const date& that) const
    {
        return !(*this == that);
    }

// i + 10;这个不会改变i的值，所以里面要进行拷贝备份。
    date operator+(int n)
    {   
        // date d(*this);
        // // date d = *this;
        // d._day += n;
        // while(d._day > getMonthDaY(d._year,d._month))
        // {
        //     d._day -= getMonthDaY(d._year, d._month);
        //     d._month += 1;
        //     if(d._month > 12)
        //     {
        //         d._year += 1;
        //         d._month = 1;
        //     }
        // }
        // return d;

        // 拷贝构造实现
        // 复用实现
        date d = *this;
        d += n;
        return d;
    }

// i += 10;
    // 出了作用域还在，引用进行返回。
    date& operator+=(int n)
    {   
      
        _day += n;
        while(_day > getMonthDaY(_year,_month))
        {
            _day -= getMonthDaY(_year, _month);
            _month += 1;
            if(_month > 12)
            {
                _year += 1;
                _month = 1;
            }
        }
        return *this;
    }

// i -10;
    date operator-(int n)
    {   
        // date d(*this);
        // // date d = *this;
        // d._day -= n;
        // while(d._day <= 0)
        // {   
        //     d._month -= 1;
        //     if(d._month == 0)
        //     {
        //         d._year -= 1;
        //         d._month = 12;
        //     }
        //     d._day += getMonthDaY(d._year, d._month);

        // }
        // return d;

        // 复用实现
        date d(*this);
        d -= n;
        return d;
    }

//  i -= 10
    date& operator-=(int n)
    {   
        _day -= n;
        while(_day <= 0)
        {   
            _month -= 1;
            if(_month == 0)
            {
                _year -= 1;
                _month = 12;
            }
            _day += getMonthDaY(_year, _month);

        }
        return *this;
    }

// ++i
    date& operator++()
    {
        // _day+=1;
        // if(_day > getMonthDaY(_year, _month))
        // {
        //     _day -= getMonthDaY(_year, _month);
        //     _month += 1;

        //     if(_month == 13)
        //     {
        //         _year += 1;
        //         _month = 1;
        //     }
        // }
        // return *this;

        *this += 1;
        return *this;
    }


// --i
    date& operator--()
    {
        *this -= 1;
        return *this;
    }

// i++
    date operator++(int)
    {
        date d(*this);
        *this += 1;
        return d;
    }

// i--
    date operator--(int)
    {
        date d(*this);
        *this -= 1;
        return d;
    }


    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }



private:
    int _year;
    int _month;
    int _day;
};

int main()
{

// 拷贝构造两种调用方法
    // date d1(20,2,3);
    // date d2 = d1;

    // date d3(2,2,2); 
    // d1 = d3;
    // d1.print();

// 拷贝构造和赋值构造
// 编译器生产默认的拷贝和赋值构造函数,是浅拷贝（值拷贝），将对象按照字节一个一个拷贝过去。
// 有些类不需要我们自定义拷贝构造和赋值构造

// 浅拷贝问题
    // Stack st1(10);
    // Stack st2(st1);

//
    date d1(2000,2,10);
    d1 -= 10;
    d1.print();

    date d2(2000,4,5);
    date d3 = d2 - 5;
    d3.print();

    ++d3;
    d3.print();









    return 0;
}