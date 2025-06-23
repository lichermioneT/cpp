#include<iostream>
using namespace std;
/*
class Time{
public:
    Time()
    {
        cout<< "time" <<endl;
        _hour = 0;
        _minute = 0;
        _secod = 0;
    }

    ~Time()
    {
        cout<< " ~ Time() " <<endl;
    }
private:
    int _hour;
    int _minute;
    int _secod;

};

class date{
public:
    // date()
    // {
    //      _year = 1;
    //     _month = 1;
    //     _day = 1;
    // }

    // 推荐全缺省构造函数
    date(const int& year = 0, const int& month = 1, const int& day = 1)
    {
         cout<< " 全缺省构造函数 " <<endl;
        _year = year;
        _month = month;
        _day = day;
    } 

    // 
    ~date()
    {
        cout<< " ~date() " <<endl;
    }
   
    // date() = default; // 显式要求编译器生成默认构造函数
    // date() = delete; // 禁止使用默认构造，必须通过构造函数构造对象

    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;

};


class stack
{
public:
    stack(int n = 10)
    {
        _a = (int*)malloc(sizeof(int) * n);
    }

    ~stack()
    {
        free(_a);
        _a = nullptr;
        _size = _capacity = 0;
        cout<< " ~stack " <<endl;
    }
private:
    int* _a;
    int _size;
    int _capacity;
};
*/

/*
class Stack
{
public:
    Stack(int n = 10)
    {
        _a = (int*)malloc(sizeof(int) * n);
    }
    ~Stack()
    {
        cout<< "~stack" <<endl;
    }

private:
    int* _a;
    int _szie;
    int _capacity;
};


class date{
public:
    // 完成初始化
    date(int year = 0, int month = 1, int day = 1)
    {   
        _year  = year;
        _month = month;
        _day = day;
    }

    // 拷贝构造
    date(const date& that)
    {
        _year = that._year;
        _month = that._month;
        _day = that._day;
    }

    bool operator==(const date&  that) const 
    {
        // if(this->_year ==  that._year && this->_month == that._month && this->_day == that._day)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
        return (this->_year ==  that._year && this->_month == that._month && this->_day == that._day);
    }

    bool operator>(const date& that) const
    {
        // if(this->_year > that._year)
        // {
        //     return true;
        // }
        // else if(this->_year == that._year && this->_month > that._month)
        // {
        //     return true;
        // }
        // else if(this->_year == that._year && this->_month == that._month && this->_day > that._day)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
        return (this->_year > that._year) ||
               (this->_year == that._year && this->_month > that._month) ||
               (this->_year == that._year && this->_month == that._month && this->_day > that._day);
    }

    bool operator<(const date& that) const
    {
        return that> *this;
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
        return (*this == that);
    }


    // 对象声明周期到了以后，完成清理工作
    ~date()
    {
        // cout<< "~date" <<endl;
    }
    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }


private:
    int _year;
    int _month;
    int _day;
    // Stack _s;
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
        date d(*this);
        // date d = *this;
        d._day += n;
        while(d._day > getMonthDaY(d._year,d._month))
        {
            d._day -= getMonthDaY(d._year, d._month);
            d._month += 1;
            if(d._month > 12)
            {
                d._year += 1;
                d._month = 1;
            }
        }
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

// 默认构造函数
// 全缺省/无参数/编译器生成的（不传参数就可以调用的）

// 构造函数
    // date d1(2000,2,10);
    // d1.print();

    // date d2; // 调用无参数的构造函数
    // d2.print();

// 编译器生成的默认构造函数
    // 它只内置类型的成员变量没有出来
    // 针对自定义类型调用它的默认构造函数
    // 显示定义类构造函数它就不会生成默认的

    // date d1;
    // d1.print();

// 默认构造函数就是不用传参数的
// 默认构造函数只能存在一个
// 全缺省/无参数/编译器生成的
    // date d1; // 调用无参数的构造函数
    // d1.print();

// 析构函数无参数，不能重载
// 析构函数完成清理工作
    // 析构函数，对象声明时，自动调用，完成资源清理
    // 析构是反着来的
    // stack s;


    // date d1;
    // d1.print();

    // date d2(2,2,2);
    // d2.print();

// 编译器生成的默认析构函数。针对内置类型处理，自定义类型处理。
    // date d1;


// 拷贝构造函数,只能是一个参数
// 先传参数，拷贝构造
    // date d1(2000,2,100);

    // 下面两种调用方式都是拷贝构造
    // date d2(d1);  // date d1 
    // d2.print();
    // date d3  = d2;
    // d3.print();

// 运算符重载
    // 让自定义类型可以使用运算符
    // date的对象比较大小相等，自定义类型 

    // date d1(2,2,2);
    // date d2(2,2,2);

    // 运算符重载如何调用
    // cout<< (d1==d2)<<endl;
    // cout<< d1.operator==(d2) <<endl; // 实际上就是函数调用

    // date d3 (3,3,3);
    // date d4 (4,4,4);
    // cout<< d3.operator>(d4) <<endl;
    // cout<< d4.operator>(d3) <<endl;




// 完善的日期类
    date d(200,2,3);
    d.print();

    // 拷贝构造
    date d2(d);
    date d3 = d2;
    
    date d4 = d2 + 10;
    d4.print();

    date d5= d + 1000;
    d5.print();

    

































    return 0;
}