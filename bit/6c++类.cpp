#include <iostream>
using namespace std;

class date
{
public:
    date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void print() const
    {
        cout<< _year << "-" << _month << " " << _day <<endl;
    }

// const修饰成员函数，成员函数就不能修改对象的数据了

// 一般只要不修改成员变量都可以加上

    void f1()
    {
        f2();
    }

    void f2() const
    {
        
    }

/*
    void f3()const
    {
        f4();
    }

    void f4()
    {

    }
*/

// 非const可以调用const修饰的函数

    date* operator&()
    {
        return this;
    }

   const date* operator&() const
    {
        return this;
    }
private:
    int _year;
    int _month;
    int _day;
};


class date1
{
public:
    date1(int year, int month, int day)
        :_year(year)
        ,_month(month)
        ,_day(day)
        ,_ref(_day)
    {
        // 初始化列表
        // 为什么有初始化列表呢？
        // 引用成员，const成员，没有默认构造函数的类(不用传参数的构造函数)
    }
private:
    int _year;
    int _month;
    int _day;
    int& _ref;
};

class a
{
public:
    a(int a)
        :_a(a)
    {

    }

private:
    int _a;
};

class b
{

private:
    int _year;
    int _month;
    int _day;
};


// static成员
// 静态成员变量
// 计算一个类产生了多少个对象
// 对象一定是构造函数，拷贝构造产生的


class F
{
public:
    F()
    {
        ++n;
    }
    
    F(const F& f)
    {
        ++n;
    }

    static int getn() // 没有this指针 不能访问非静态成员的
    {
        return n;
    }

private:
    static int n;
};


// 静态成员属性，不属于任何一个类
// 必须在外面初始化

int F::n = 0;

F f(F f)
{
    return f;    
}

int main()
{

    // b b1(1,2); // 对象定义


    // d d1(2);
    // d d2 = 9; // 创建临时变量，用来赋值d2 临时对象9给d2
    // const d& d2 = 9; //  中间就不会优化了,就是临时对象的
    // d d3 = d1; // 拷贝构造实现

    // int i = 0;
    // const double& d  = i;
    
    // c++11支持
    // E e = {1,2,3};

    F f1;
    F f2;

    f(f1);
    f(f2);
    
   cout<< (F::getn()) <<endl; 
























    return 0;
}

