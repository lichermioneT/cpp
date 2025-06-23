#include<iostream>
using namespace std;

class solution
{
public:

    solution()
    {
        cout<< "solution" <<endl;
    }

    int sum_solution(int n)
    {
        return n;
    }

    ~solution()
    {
        cout<< "~solution" <<endl;
    }

};


class a
{
public:
    a()
    {
        cout<< "a" <<endl;
    }

    ~a()
    {
        cout<< "1a" <<endl;
    }
};

class b
{
public:
    b()
    {
        cout<< "b" <<endl;
    }

    ~b()
    {
        cout<< "1b" <<endl;
    }
};

class c
{
public:
    c()
    {
        cout<< "c" <<endl;
    }

    ~c()
    {
        cout<< "1c" <<endl;
    }
};

class d
{
public:
    d()
    {
        cout<< "d" <<endl;
    }

    ~d()
    {
        cout<< "1d" <<endl;
    }
};


class  weight
{
public:
    weight()
    {

    }
    weight(const weight &w)
    {
        cout<< "weigiht" <<endl;
    }
};


weight f(weight u)
{
    // 下面两个都是调用拷贝构造的
    weight v(u);
    weight w = v;
    return w;
}


// c c1;


// main函数之前就初始化，在哪儿都能用，作用域全局的
// 这两个链接属性不一样，第一个所有文件中可见，第二个只能在这个文件可见。
int globalVar = 1; // 全局变量
static int staticGlobalVar = 1; // 静态全局变量


class t
{
public:
    t()
    {
        _a = 99;
    }

    ~t()
    {
        cout<< "~t" <<endl;
    }
    void print()
    {
        cout<< _a <<endl;
    }


private:
    int _a;
};

int main()
{

    // s1的声明周期在main函数里面
    // s1在mian函数结束调用析构函数
    // solution s1;
    // s1.sum_solution(22);

// 匿名对象
    
    // solution();

    // 以后只有这一行使用，别人不需要。直接创建匿名对象。
    //这个匿名对象生命周期在这一行
    // cout<< solution().sum_solution(5) <<endl; // 这一行结束就直接调用析构函数
    // cout<< " sdfas" <<endl;

// 作用
    // static const int monthdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 改为 const
    // int year, month, day;

    // // 测试多个案例
    // while(cin>>year>>month>>day)
    // {
    //     int n = 0;

    //     for(int i = 1; i < month; i++)
    //     {
    //         n += monthdays[i];
    //     }
    //     n += day;
    //     if(month > 2 &&((year %4 ==0)&&year % 100 != 0) || year % 400 == 0)
    //     {
    //         n += 1;
    //     }
    //     cout<< n <<endl;
    // }

// 构造析构
    // a a1;
    // b b1;
    // static d d1;
// c
// a
// b
// d

// 1b
// 1a

// 1d 局部静态变量
// 1c 全局变量


// 连续的拷贝构造可能被优化。返回和传参时。返回值做参数。
// 返回值马上给
    // weight x;
    // weight y = f(f(x));


// c/c++内存分布

/*
┌───────────────┐
│   栈（Stack）  │ ← 局部变量、函数参数、返回地址等
├───────────────┤
│   堆（Heap）   │ ← 动态分配的内存（new/malloc）
├───────────────┤
│ BSS段（未初始化的全局/静态变量）│
├───────────────┤
│ 数据段（已初始化的全局/静态变量）│
├───────────────┤
│   代码段（Text）│ ← 程序代码（指令）
└───────────────┘
*/
    // 运行到这里才初始化，只能在main函数里面使用
    static int staticVar = 1; // 静态局部变量。

    // 栈区
    int localVar = 1; // 局部变量
    // 栈区
    int num1[10] = {1, 2, 3, 4}; // 数组初始化

    // 栈区
    char char2[] = "abcd"; // 字符数组，五个字节，别忘记\0
    // 栈区
    // char* pChar3 = "abcd"; // 字符指针

    // 动态内存分配

    // 栈区
    int* ptr1 = (int*)malloc(sizeof(int) * 4);

    int* ptr2 = (int*)calloc(4, sizeof(int));

    int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);

    // 释放动态分配的内存
    free(ptr1);
    free(ptr3);


// c语言申请内存
// c++申请内存

    // // 函数
    // int* p1 = (int*)malloc(sizeof(int));
    // int* p3 = (int*)malloc(sizeof(int) * 10);
    // *p1 = 22;
    // cout<< *p1 <<endl;
    // free(p1);
    // free(p3);

    // // 操作符
    // // int* p2 = new int;
    // int* p2 = new int(10);
    // int* p4 = new int[10];

    // cout<< *p2 <<endl;
    // delete p2;
    // delete[] p4;


// c++和c开辟空间的区别
    // 内置类型一样的
    // 自定义类型不一样的

    int* p1 = new int;
    int* p2 = (int*)malloc(sizeof(int));

    t* t1 = (t*)malloc(sizeof(t));
    t* t2 = new  t;
    
    t1->print();  // 申请空间
    t2->print();  // 申请空间+构造函数初始化

    free(t1); // 释放空间
    delete t2; // 释放空间 + 析构函数释放空间























































    return 0;
}