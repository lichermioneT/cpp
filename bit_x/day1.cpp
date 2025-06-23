#include<iostream>

// 在日常练习中 不在乎跟库命名冲突
// c++标准库里面的东西
using namespace std;  // c++库中所有东西 都是放到std命名空间里中

namespace N
{
    int a = 10;
    int b = 20;

    int add(int left, int right)
    {
        return left + right;
    }


    int sub(int left, int right)
    {
        return left - right;
    }

}

// 展开命名空间的b;
    // using N::b;

// 全部展开
    // using  namespace N;


// 只是展开常用的命名空间
// 工程项目里面比较推荐！！！！
// using std::cout;
// using std::endl;
// using std::cin;


// 缺省参数 里面有默认参数 全缺省/半缺省
// 不传入参数 就默认参数
// 缺省参数只能写在最后面
void Func1(int a = 0 )
{
    cout<< a <<endl;
}

void Func2(int x, int y, int z = 100)
{
    cout<< x <<endl;
    cout<< y <<endl;
    cout<< z <<endl;

}

// 全缺省
void Func3(int x = 10, int y = 20,  int z = 30)
{   
    cout<< x <<endl;
    cout<< y <<endl;
    cout<< z <<endl;
}

// 半缺省 缺少部分参数
// 只能放在后面  并且缺省的参数是连续的  
void Func4(int z, int x, char ch = 'e')
{
    cout<< z <<endl;
    cout<< x <<endl;
    cout<< ch <<endl;
}

// 函数重载
// 注意数字L,D,F。否则会产生隐士类型转换。
int add(int x, int y)
{
    return x + y;
}

int add(double x, int y)
{
    return (int)x + y;
}

int add(int x , int y, int z)
{
    return x + y + z;
}

int add(int y, double x)
{
    return (int)x + y;
}



int main()
{
// BS 网页    server       前端 HTML + CSS + JS
// CS client  server       MFC/

// 七大排序 
// 刷题 leetcode 刷题刷题移动两百道题 
// 
// 多读书 《剑指offer》 《系统和网络结构的书》
// 坚持重复大量练习是给每个普通人成功的机会
// QT界面



// 命名空间
    // 关键字是:namespace;
    // 三种使用方式命名空间

    // cout<< N::a <<endl;
    // cout<< N::add(55, 66) <<endl;

    
// c++的输入和输出 iostream 输入输出流
// cout
    // cout<< "hello world" <<endl;   // 自动识别这里面是字符串
    // std::cout<< "hello world";
    // std::cout<< "hello world\n";
    // std::cout<< "hello world" <<endl;

    // int i = 1;
    // double d = 1.11;
    // std::cout << "d" << " = " << i <<endl;   // 自动识别类型 这里面是double类型的

// cout是如何识别类型，通过函数重载实现


// cin
    // int i = 0;
    // double d = 1.11;
    // cin>> i >> d;       // 输入能够直接识别类型呢
    // cout<< "i = " << i <<endl;  
    // cout<< "d = " << d <<endl;  

// 函数缺省 == 默认参数
// 不是缺省参数的必须传入函数参数 
    // Func1();
    // Func2(1, 2);
    // Func2(1, 2, 3);
    // Func3();
    // Func3(1,2,3);
    // Func4(10, 33);


// 函数重载
// 一个函数里面多个功能
// 缺省参数不能作为函数重载的判断条件
// C++ 编译器在编译函数时，会把函数名 + 参数类型信息一起编码成一个唯一的名字，这样多个同名但参数不同的函数就不会冲突
// extern "C" 修饰的函数能够让c/c++同时调用这个函数
    // 函数名相同 参数不同：参数类型不同  参数个数不同  参数类型顺序不同 

    // 函数的返回值没有要求
    // 返回值不能够作为重载的条件
    // 调用根据函数类型去识别函数
    // 基于函数名和参数类型


// 引用
    // 引用必须初始化 初始化过后不能更改 
    // 常量指针
    // int a  = 1;
    // int& ra = a; // ra是a的引用  引用就是别名 给a再取一个名称
    // int& b = a;
    // int& c = a;
    // int& d = ra;

    // ra= 10;
    // cout<< a <<endl;
    // b = 100;
    // cout<< a <<endl;
    // c = 1000;
    // cout<< a <<endl;

    // cout<< &a <<endl;
    // cout<< &ra <<endl;
    // cout<< &b <<endl;
    // cout<< &c <<endl;
 
    // int a = 1;
    // int& c = a;
    // int d = 2;
    // c = d;   // 这里把d的值赋给c(a)
    // cout<< c <<endl;
    // cout<< a <<endl;
    // cout<< &c <<endl;
    // cout<< &a <<endl;

// <类型>& <引用名> = <变量名>;可写可读
// const <类型>& <引用名> = <变量名>; 只读

// 引用的权限
    // const int  a = 0;
    // int& b = a; // b的类型是a的类型int 可以读可以写 所以不行
    // const int& b = a; // 正确的

    // int c = 1;  // c是可以读可以写
    // int& d = c;
    // const int& e = c;  // e只是读的可以的

    int i = 0;
    double db = i; // 隐士类型转换

    // 只读的情况
    // 隐士类型转换具有常属性
    const float& rf = i; // 引用类型注意 
    const double& rd = i; // 临时变量具有常性

    // 变量之间赋值是没有权限发大和缩小的情况 


    // 指针常量
    int* const p = &i;
    *p = 55;
    cout<< i <<endl;
    cout<< *p <<endl;
    return 0;
}