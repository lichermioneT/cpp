#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
// #define N 1000


// 非类型模版参数
// 非类型模版参数是常量，不然怎么做数组的初始化参数呢
template<class T, int N = 55>
class array
{
private:
    T _a[N];
};

// 不能做非类型模版参数的数据类型
// float double
// 自定义类型
// 基本上都是整形，int或者char类型的

// array数组


// 模版特化
// 特殊类型特殊处理

/*
template<class T>
bool isEqual(T& left, T& right)
{
    return left == right;
}
*/

template<typename T>
bool IsEqual(T left, T right)
{
    return left == right;
}

// 函数模板特化 for const char*
template<>
bool IsEqual<const char*>(const char* left, const char* right)
{
    return strcmp(left, right) == 0;
}


// 类模版特化
template<class T1, class T2>
class Data
{

public:
    Data()
    {
        cout<< " Data<T1, T2> " <<endl;
    }
private:
    T1 _d1;
    T2 _d2;
};

// 全特化
template<>
class Data<int, char>
{
public:
    Data()
    {
        cout<< " Data<int, char> " <<endl;
    }
private:
    int _d1;
    char _d2; 
};

// 偏特化
template<class T2>
class Data<int, T2>
{
public:
    Data()
    {
        cout<< " Data<int, T2> " <<endl;
    }

private:
    int _d1;
    T2 _d2;
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
    Data()
    {
        cout<< " Data<T1*, T2*> " <<endl;
    }

private:
};

template<class T1, class T2>
class Data<T1&, T2&>
{
public:
    Data()
    {
        cout<< " Data<T1&, T2&> " <<endl;
    }

private:
};



int main()
{

// 非类型模版参数
/*
    array<int> a;
    cout<< sizeof(a) <<endl;

    array<int, 20> a1;
    cout<< sizeof(a1) << endl;

    array<int, 300> a2;
    cout<< sizeof(a2) << endl;
*/

// 模版的特化

/*
    int a = 10;
    int b = 10;
    cout<< isEqual<int>(a, b) <<endl;

    char* p1 = "hello";
    char* p2 = "world";
*/

/*
    Data<int, int> d1;
    Data<int, char> d2; 
    Data<char, char> d3; 
    Data<int*, char*> d4;
    Data<int&, char&> d5;
*/


// 模版分离编译
// 工程中，声明放.h, 定义放在.cpp里面
// 为什么分离编译，方便查看和维护

// 模版不能分离编译
// 为什么呢？

// 预处理，展开头文件，宏替换，条件编译，去掉注释 func.i 
// 编译，检查语法，生成汇编代码  func.s
// 汇编,汇编代码转成二进制的机器码。 func.o
// 链接，a.out 

// 链接
// 模版类型













































    return 0;
}