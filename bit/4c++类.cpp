#include <iostream>
using namespace std;

class TIME
{
    ~TIME()
    {
        cout<< " ~TIME " <<endl;
    }
};

class Date
{
public:
    Date(int year = 2000, int month = 2, int day = 10)
    {   
        this->_year =  year;
        this->_month = month;
        this->_day = day;
    }
    
    // ~Date()
    // {
        // cout<< "~Date: " << this << endl;
    // }
    
    // 拷贝构造
    Date(const Date& that)
    {
        this->_year = that._year;
        this->_month = that._month;
        this->_day = that._day;
    }

    void print()
    {
        cout<< this->_year << " - " << this->_month << " - " << this->_day <<endl;
    }


    // 运算符重载
    bool operator==(const Date& that)
    {
        return this->_year == that._year &&
               this->_month == that._month &&
               this->_day == that._day;
    }

    bool operator>(const Date& that)
    {
        return this->_year > that._year || 
               (this->_year == that._year && this->_month > that._month)||
               (this->_year == that._year && this->_month == that._month && this->_day > that._day);
    }
    
    bool operator!=(const Date& that)
    {
       return !(this->operator==(that));
    }
    


private:
    int _year;
    int _month;
    int _day;
};

class stack
{
public:
    stack(int n = 10)
    {
        _a = (int*)malloc(sizeof(int) * n);
        _capacity = 10;
        _size = 0;
    }
    
    ~stack()
    {

        free(_a);
        _size = _capacity = 0;
        _a = nullptr;
    }

private:
    int* _a;
    int _size;
    int _capacity;
};

int main()
{

// Date d; 实际上调用无参数的
// Date d1;
// Date d2(1,2,4);

// 构造函数基本类型不管
// 自定义类调用他的构造函数
// 全缺省、无参数、编译器生成的 无参数就可以调用的

    // Date d1;
    // Date d2;
    // stack s1;
    // stack s2;

// 析构函数看你实际的类，怎么去清理这些资源
// 一个类怎么设计，是根据你的实际场景去设计的
// 自动生成的，会调用自定义类型的析构函数


// 拷贝构造
// 注意递归拷贝

    // Date d1;

// 拷贝构造的两种方法
    // Date d2(d1);
    // Date d3 = d1;

    // d1.print();
    // d2.print();
    // d3.print();

    Date d1(200,2,3);
    Date d3(200,2,4);

    cout<< (d1 == d3) <<endl;
    cout<< (d1.operator==(d3)) <<endl;
    
    cout<< (d1 > d3) <<endl;
    cout<< (d3 > d1) <<endl;






    return 0;
}

