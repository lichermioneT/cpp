// #include<iostream>
// using namespace std;

// // 类里面定义成员变量，成员方法
// // 工程里面类的声明和使用分开
// class Person
// {
//     void print()
//     {
//         cout<< _name <<endl;
//         cout<< _age <<endl;
//     }
//     char _name[10];
//     int _age;
// };


// class Student
// {
// public:
//     void print_info()
//     {
//         cout<< _name <<endl;
//         cout<< _aage <<endl;
//         cout<< _score <<endl;
//     }

// // private: // 一般成员变量都是私有的  都会定义成私有或者保护
//     // char _name[20];
//     char* _name;
//     int _aage;
//     int _score;
// };


// int main()
// {
//     Student s1;
//     // s1._name = "bob";
//     // s1._name = "b0b";
//     // s1._aage = 19;
//     // s1._score = 100;
//     // s1.print_info();
                                                                                                                     
//     return 0;
// }

#include<iostream>  
using namespace std;

// 定义一个类
// 类名 成员变量 成员函数
// 访问限定符

// c语言里面struct只是用来定义结构体
// c++兼容c语言可以用来定义结构体，还可以定义类。
// c++使用class和struct定义类的区别就是：默认的访问限定符号

// 区别就是c++里面的结构体可以定义成员方法 默认的成员变量和成员函数就是公开的


// class Stack
// {
// // 封装将数据和方法放在一起
// // 封装把想给你看的给你看，不想给你看的封装起来 访问限定符

// public:
//     // 成员函数
//     // 成员变量
//     void Push(int x)
//     {

//     }

//     void Pop();

//     bool Empty();

// private:
//     int* _a;
//     int _size;
//     int _capacity;
// };


class date1
{
public:
    date1(int year , int month, int day)  // void Init(date* this,int year, int month, int day)  
    {
        if(year > 0 && month > 1 && month < 13 && day > 0 && day < 31)
        {
            _year = year;
            _month = month;
            _day = day;

            // this->_year = year;
            // this->_month = month;
            // this->_day = day;
        }
    }

    date1()
    {
        _year = 0;
        _month = 1;
        _day = 1;
    }


    void print()
    {
        cout<< _year << "-" << _month << "-" << _day <<endl;
    }
    /*
    void print(date* this)
    {
      cout<< this->_year << "-" <<this->_month << "-" << this->_day <<endl;
    }
    */

   void Init(int year, int month, int day)
   {
        _year = year;
        _month = month;
        _day = day;
   }



   void init();

private:
    int _year;
    int _month;
    int _day;
};

// 类外面定义
void date1::init()
{
}


int main()
{   
// 在类里面声明 类外面定义
// 在类里面定义

// 计算类的大小：对象只存储成员变量，不存储成员函数
// 为什么没有函数大小
// 函数在代码区
// 一个类实例化出n个对象，每个对象的成员变量可以存储不同的值，但是调用的函数确是一个

// 每个对象都放成员函数，这些成员函数都是一样的，就是浪费空间的
// 函数放在一个公共的区域里面，公共代码段里面

// 如何计算一个实例化类对象的大小，计算成员变量之和，并且考虑内存对齐规则

// 没有成员变量的类空间大小是一
// 开一个字节不是为了存数据，而是为了占位 方便声明


// this 指针是 C++ 中一个特殊的指针，只在类的非静态成员函数中可用，它指向当前调用该成员函数的对象本身。
// 隐含的this指针
// date1 d1;
// d1.Init(2025, 1, 22); // d1.Init(&d1,2025,1,22)

// d1.print(); // d1.print(&d1)

// 隐含的this指针
// 谁调用 这个成员函数 this就指向谁
// this是存在进程地址那个区域  栈上(函数的形式参数)
// 


// 构造函数
    // 就是为了让数据能够初始化，不被赋随机值
    // 初始化数据. 
    date1 d1(200,2,22);
    d1.print();

    date1 d2; // 这里调用的是构造函数（无参数的）
    d2.print();
// 没有显示定义构造函数，生成默认一个无参数的默认构造函数














return  0;
}