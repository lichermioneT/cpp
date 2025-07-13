#include <iostream>
using namespace std;

class date
{
public:
    date(int year = 0, int month = 1; int day = 1)
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




int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

