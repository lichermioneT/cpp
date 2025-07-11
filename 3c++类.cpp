#include <iostream>
using  namespace std;

// 下面都是声明一个类

// 如何定义一个类
class stack
{

// 成员属性:变量
// 成员方法:函数
// 封装性：成员方法和成员属性定义在一起 
// 封装性：想给你看的给你看，不想给你看的封装起来,访问限定符

public:

    void Push(int x)
    {

    }

    void Pop()
    {

    }
    
    void Init();

private:
    int* _a;
    int _szie;
    int _capacity;
};

// 类里面声明，类外面实现
void  stack::Init()
{

}

struct listnode_c
{
    int val;
    struct listnode_c* _next;
    struct listnode_c* _pre;

};


struct listnode_cpp
{

    int val;
    listnode_cpp* _next;
    listnode_cpp* _pre;

    /*
    下面的方法也可以的
    struct  listnode_cpp* _next;
    struct  listnode_cpp* _pre;
    */
};

class Date
{
public:
    void Init(int year, int month, int day)
    {
       this->_year = year;
       this->_month = month;
       this->_day = day;
    }

    void print()
    {
        /* cout<< _year << " " << _month << " " << _day <<endl; */
        cout<< this->_year << " " << this->_month << " " << this->_day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    // 声明和实例化
    stack s1;
    stack s2;

// c++的class默认是私有的
// c++的struct默认是公有的，为了兼容c语言

// 实际定义一个类和结构体，就相当于创建一个类型，就类似c++自带的类型 int char double
// 基本类型，自定义类型
// 实例化就是，给这个类型赋值

    s1.Pop();

// 内存对其
// 对象只是存储成员变量，不去存储成员函数
// 函数在代码区，
// 一个类实例化N个对象，每个类可以存储不同的属性，但是调用的方法都是一样的
// 公共代码段,你们都去这个段找就行了
// 内存对其


// 空类：没有成员方法的类，大小是一
// 解释：开一个字节，不是为了存放数据，是为了占位表示对象存在。

// 隐含的this指针
    Date d1;
    /* d1.print(&d1); */
































    return 0;
}

