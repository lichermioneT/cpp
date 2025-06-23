#include<iostream>
using namespace std;

class date
{
private:
    int _year;
    int _month;
    int _day;
public:
    int Getmonthday(int year, int month) 
    {
        // 月份必须是1到12并且不能修改的
        static const int months[] = {31,28,31,30,31,30,31,31,30,31,30,31}; // 改为 const
        if (month < 1 || month > 12)
        {
            // 处理错误：返回-1、抛出异常或使用断言
            return -1; // 示例：返回-1表示无效输入
        }
        if (month == 2&&(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ) 
        {
            return 29;
        }
        else 
        {
            return months[month - 1];
        }
    }

    // date(int year = 0, int month = 1, int day = 1)
    // {
    //     if(year >= 0 && month>0 &&month <13 && day <= Getmonthday(year, month)) // 函数体内赋值
    //     {
    //         _year = year;
    //         _month = month;
    //         _day  = day;
    //     }
    //     else
    //     {
    //         cout<< "日期有误" <<endl;
    //     }
    // }


    date(int year = 2000, int month =  2, int day = 10) // 初始化列表解决几类成员变量 函数体内无法赋值，没有默认构造函数，引用，const
        :_year(year)
        ,_month(month)
        ,_day(day)
    {

    }

    date(const date& d)
    {
        this->_year = d._year;
        this->_month = d._month;
        this->_day = d._day;

    }

    void print() const  // void print(const date* this) 修饰指向的对象（*this），对象就不能修改了
    {
        cout<< _year << " - " << _month << " - " << _day << endl;
    }
    
    void f1()
    {
        cout<< " f2" <<endl;
    }

    void f2() const
    {
        cout<< " f1" <<endl;
    }


    date*  operator&()
    {
        return this;
        // cout<< "nuppprt" <<endl
    }
    
    const date*  operator&() const
    {
        return this;
        // cout<< "nuppprt" <<endl
    }
};


// 传引用就不用拷贝构造
// 这里面的d是const,d是不能够修改的，
void f(const date& d)
{
    d.print(); // d.print(&d) 这里是const修饰了的指向的对象,d是const修饰的数据。
}

class A
{
public:
    A (int a)
    :_a(a)
    {

    }

private:
    int _a;

};

class B
{
public:
    // 可以理解成从初始化列表是对象的成员变量的定义的地方
    // 定义的顺序和声明的顺序一致
    B(int a, int ref)
        :_aobj(1)
        ,_ref(ref)
        ,_n(10)
    {
        _x  = 20000;
    }

    


private:
    // 成员变量声明
    // 下面定义的时候必须初始化
    A _aobj; // 没有默认构造函数，不用传参数就可以调用的那个构造函数
    int& _ref; // 引用
    const int _n; // const对象

    int _x;


};


class Date
{

public:
    Date(int year)
        :_year(_year)
    {
        cout<< "Date" <<endl;
    }

    Date(const date& that)
    {
        cout<< "kaobe" <<endl;
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
    {
        cout<< "Date" <<endl;
    }

    date1(const date& that)
    {
        cout<< "kaobe" <<endl;
    }
private:
    int _year;
    int _month;
    int _day;


};

class b
{
public:
    b()
    {
        count += 1;
    }

    b(const b& that)
    {
        count += 1; 
    }

    void print()
    {
        cout<< count<< endl;
    }

    static int get() // 没有this指针，函数中不能访问非静态的成员
    {
        return count;
    }

private:
    static int count; // 这个成员变量是所有的类共同拥有的一个n
    // cout在数据段，静态区里面

};

int b::count = 0; // 在类外部初始化

b f(const b& that)
{
    return  that;
}

int main()
{


    // date d(2,2,2);
    // f(d);

    // d.print(); // 权限可以缩写，这里可以调用。

// const date*  this // 指向的对象 ，不能修改
// date const*  this // 指向的对象 ，不能修改
// date* const this  // 指针本身 ，不修改


// 只要调用成员函数，都涉及const修饰
// const成员函数
// 什么时候给成员函数添加const，只要是成员函数不修改成员变量，最好添加上const
// const权限的传递

    // cout<< &d <<endl;

// 初始化列表
    // B b(1,2); // 对象定义

// 声明顺序才是初始化顺序

// 类初始化
    // date d1(2000,2,33); // 构造函数
    // date d2 = d1; // 拷贝构造

// 隐士类型的转换
    // 隐士类型转换会产生临时变量，临时变量具有常属性
    // Date d3 = 5; // 隐士类型转换、构造出temp(2)+再用temp拷贝构造d3(temp)+优化
    // const date& d4 = 6;  // 不会优化的，直接即是临时变量

    
    /*
    int i = 1;
    double d = i; // 隐士转换一个临时变量temp,temp在复制给d
    */
// explicit 添加到构造函数前面，就不会发生隐士类型转换的
// c++11多参数
    // date1 d5 = {1,2,3}; // 这里也是隐士类型的转换





// 静态成员变量
// static的成员变量
    // 设计一个类，可以 计算这个类可以计算产生了多少个对象

// 类只能是拷贝构造和赋值构造产生出来的

    b bb;
    f(bb);
    bb.print();

    b bbb;
    bbb.print();

// 静态成员函数的调用方式
    cout<< b::get() <<endl; 



























    return 0;
}