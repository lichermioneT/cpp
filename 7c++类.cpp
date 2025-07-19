#include <iostream>
using namespace std;

class date
{
    friend void f(date& d);
public:
    date(int year = 1, int month = 1, int day = 1)
        :_year(year)
        ,_month(month)
        ,_day(day)
    {

    }

    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }

    void operator<<(ostream& out)
    {
        out<< _year << " " << _month << " " << _day <<endl;
    }

private:
    int _year = 1;
    int _month = 1;
    int _day = 1;
};


// 有元函数
// 类里面friend修饰函数
// friend void f(date& d);
void f(date& d)
{
    cout<< d._year <<endl;
}


class date1
{
public:
    
    static void f1()
    {
        cout<< " static " <<endl;
    }

    void  f2()
    {
        cout<< " non_static"<<endl;
        f1();
    }
};

class count
{
public:
    count()
    {
        n++;
        sum += n;
    }
    
    static int getsum()
    {
        return sum;
    }

private:
    static int sum;
    static int n;
};

int count::n = 0;
int count::sum = 0;



class date3
{
public:
    date3()
    {

    }
    
    void print()
    {
        cout<< _year << " " << _month << " " << _day <<endl;
    }

private:
    // c++11,这里是成员属性的缺省值
    // 缺省值，默认值
    // 静态成员属性不能够给的,必须在类外面定义
    int _year = 0;
    int _month = 0;
    int _day = 0;

};


class date4
{
    friend void f4(const date4& d);
    friend ostream& operator<<(ostream& out, const date4& d);
    friend istream& operator>>(istream& cn, dadte4& d);
    // friend class d 有元类
public:
    date4(int year = 0, int month = 0, int day = 0)
        :_year(year)
        ,_month(month)
        ,_day(day)
    {
        
    }
    
    void operator<<(ostream& out)
    {
        out<<_year << " " << _month << " " << _day <<endl;
    }



private:
    int _year;
    int _month;
    int _day;
};


void f4(const date4& d)
{
    cout<< d._year <<endl;
}


// 输入输入必须重载成有元函数：
ostream& operator<<(ostream& out, const date4& d)
{
    out<< d._year<< " " << d._month << " " << d._day<<endl;
    return out;
}

istream& operator>>(istream& cn, dadte4& d)
{
    cn>>d._year>>d._month>>d._day;
    return cn;
}

int main()
{

    // date d;
    // f(d);

    // d.operator<<(cout);
    // d << cout;



// 初始化列表是成员属性定义的地方
    // date d1; // 这是对象的定义

// 必须在初始化列表初始化
// const成员属性
// 引用成员属性
// 没有默认构造函数的自定义成员属性

// 成员变量在初始化列表的的顺序是，声明的顺序决定的
// 声明和定义的顺序一致

// explicit修饰构造函数。进制隐士类型的转换

    // date d2 = 1;
    // date d3 = {2, 4};
    // date d4 = {4, 5, 9};


// static静态修饰成员属性和成员方法
// 存在静态区里面的，不属于任何一个类的，在类外面声明

// 静态成员函数没有this指针 类域访问

// static成员变量不存在对象中，存在静态区 ，属于这个类的所有对象，也属于这个类
// static成员函数没有this指针 ，不使用对象就可以可以调用，类名::func()

// 静态调用非静态：不能
// 非静态调用静态：可以
//


// static修饰的函数和变量，不能访

    // date1::f1();
    // date1 d3;
    // d3.f2();

// 是 C++ 明确禁止的，因为你尝试用 类名去调用一个非静态成员函数，这在语义上是错误的。

    // count a[100];
    // cout<< count::getsum() <<endl;
    
    // date3 d;
    // d.print();


// 什么是有元
// 突破类域访问一个类里面的东西


    // date4 d;
    // f4(d);
    
    // date4 d;
    
    // d<<cout;
    // d.operator<<(cout);
    date4 d;
    cout<<d;


// 内部类 
// 类里面定义一个类


// 封装
// 继承
// 多态



























































































    return 0;
}

