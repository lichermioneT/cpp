#include <iostream>
using  namespace std;

class solution
{
public:
    solution()
    {
        cout<< "solution" <<endl;
    }
    int sum_solution(int n)
    {
        cout<< "匿名对象" <<endl;
        return n;
    }
};

class a
{
public:
    a()
    {
        ++n;
        cout<< n <<endl;
    }
    ~a()
    {
        ++n;
        cout<< n <<endl;
    }

private:
    static int n;
};

int a::n = 0;

int globalvar = 1;
static int staticglobalvar = 1;

class b
{
public:
    b()
    {
        a = 5;
        cout<< " b " <<endl;
    }
    
    ~b()
    {
        cout<< "~b" <<endl;
    }

public:
    int a;
};

int main()
{

// // 匿名对象
//     solution s1;  // s1生命周期mian函数
//     s1.sum_solution(10);

// // 匿名对象
// // 只有我这一行调用这个，别不需要使用。
//     solution().sum_solution(55); // 它的生命周期这一行

    // static const int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    // int year = 0;
    // int month = 0;
    // int day = 0;
    // cin>>year>>month>>day;  

    // int n = 0;
    // for(int i = 1; i < month; i++)
    // {
    //     n += months[i];
    // }
    
    // n += day;
    // if(month > 2 && ((year %  4 == 0 && year % 100 != 0) || year % 400 == 0))
    // {
    //      n += 1;
    //  }
    
    // cout<< n <<endl;
    
    static int staticvar = 1;

// 数据段
// 全局变量和全局静态变量，局部静态变量：数据段


// 栈区
    int localvar = 1;
    int num1[10] =  {11,2};
    char ch[] = "adfs";
     

// linux运行程序
// 编写的代码只是存在文件系统上面的
// 编译器读取这个程序
// 终端运行

// c语言malloc
// c语言calloc
// c语言realloc
// free()
    
    // c，这是一个函数
    // int* p1 = (int*)malloc(sizeof(int));
    // int* p3 = (int*)malloc(sizeof(int) * 10);
    // free(p1);
    // free(p3);

    // c++，这是一个操作符
    // int* p2 = new int;
    // int* p5 = new int(10); // 申请一个int
    // int* p4 = new int[10]; // 10个int
    // delete p2;
    // delete[] p4;
    // delete p5;

// c语言已经有了，c++为什么还要这些呢
// 1.对于内置类型，效果是一样的
// 2.对于申请自定义类型 ，效果不一样了

    int* p1 = new int;
    int* p2 = (int*)malloc(sizeof(int));
    free(p1); // 内置类型一样的
    delete p2; // 内置类型一样的

    b* p3 = (b*)malloc(sizeof(b));
    b* p4 = new b; // 自定义类型，调用它的构造函数

    free(p3);   // 释放空间
    delete p4; // 析构 + 释放空间



































































    return 0;
}

