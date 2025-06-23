#include<iostream>
using namespace std;

// 类里面不存在访问限制
class date
{

public:

// explicit关键字修饰构造函数，防止隐士类型转换。
    // explicit date(int year, int month, int day)  // 初始化列表的顺序是声明的顺序决定的。实际中声明和定义顺序写成一样的
    date(int year = 0, int month = 1, int day = 1)  // 初始化列表的顺序是声明的顺序决定的。实际中声明和定义顺序写成一样的
        // 成员变量定义的地方
        :_year(year)
        ,_month(year)
        ,_day(day)
    {

    }

    void print()
    {
        cout<< this->_year << " - " << this->_month << " - " << this->_day << endl;
        this->print(5);
        print(22); // 非静态函数调用静态函数
    }

    static void print(int x)
    {
        cout<< x <<endl;
    }


private:
    // 成员变量的声明
    int _day;
    int _month;
    int _year;
    static int n; 
};

// 指定类域了就可以访问了
int date:: n = 0;


class num
{
public:
    num()
    {
        sum += number;
        ++number;

    }
    num(const num& that)
    {
        ++number;
        sum += number;
    }

    static int get()
    {
        return sum;
    }

 private:
    static int number;
    static int sum;
};

// 静态成员变量只能在类外面突破类域访问
int num::number = 1;
int num::sum = 0;

int main()
{
// const成员变量，引用成员变量，没有默认构造函数的自定义成员变量
// 成员变量初始化的顺序是声明的顺序，建议声明和定义顺序写一样
// explicit修饰构造函数，让对象能够隐士类型转换

    // date d(22,5,3); // 对象的定义
    // 隐士类型转换 生成临时变量，临时拷贝构造，优化给变量
    // date d0 = 1;
    // date d1 = {1};
    // date d2 = {1,2};
    // date d3 = {1,2,3};

// 静态成员变量和成员函数突破类域就可以访问了。
// 非静态可以调用静态

// 突破类域，编译器知道那个类域+访问限定符是否可以访问

    num a[10];
    cout<< num::get() <<endl; // 使用静态成员函数，访问数据

    

























    return 0;
}