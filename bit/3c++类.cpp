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
    // 一般推荐是全缺省的
    // 函数名和类名一样，没有返回值
    Date(int year = 2000, int month = 2, int day = 10)
    {
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }

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

class a
{
public:
    void pinrt()
    {
        cout<< " jjj" <<endl;
    }
    
    void printa()
    {
        cout<<this->_a <<endl;
    }


private:
    int _a;

};

class TIME
{
public:
    TIME()
    {
        cout<< " TIME" <<endl;
    }
private:
    int _hour;
    int _mintes;
    int _second;
};


class Date2
{





private:
    int _year;
    int _month;
    int _day;
    TIME _T;
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
// 谁调用这个成员函数，这个this指针就指向谁
    /* Date d1; */
    /* d1.print(&d1); */

// this指针存在哪里的? 栈区，因为它是函数的一个参数。vs下存在ecx寄存器里面的。
// this指针可以为空吗？

    // 指针调用，传参就是这个指针
    /* a* ap = NULL; */
    /* ap->pinrt(); */
    /* ap->printa(); */

// 寄存器
// 缓存
// 内存
// 硬盘  机械硬盘，SSD
// 远程网络存储
// 以后当一个活学活用的程序员！！！！！！！！！！！！！！！！！！！！！！！！！！！！



// 只要涉及一个类，就是六个默认成员函数
// 构造函数，对象构造是调用，这个函数完成初始化。
    Date d(2000,2,18);
    Date d2; // 
// 构造函数可以重载
    
    // c++默认的构造函数是会调用自定义类型的
    // 默认构造函数
    // 1针对内置类型成员变量没有出来
    // 2针对自定义类型调用它的构造函数初始化
    Date2 d3;

// 不带参数或所有参数都有默认值的构造函数，用于在对象创建时自动调用。
// 全缺省、没有参数的、编译器生成的 都不需要传参数

// 析构函数和构造函数类似
// 对象声明周期
// 完成对象里面的资源清理,并不是对象的清理











    return 0;
}

