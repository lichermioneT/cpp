#include<iostream>
using namespace std;

// 同一个作用域
// 函数名称相同
// 参数类型 个数 顺序
// 函数的返回值类型不能作为重载的条件
void func()
{
    cout<< "func的调用" <<endl;
}

void func(int a)
{
    cout<< "func(int a)的调用!" <<endl;
}

void func(char ch)
{
    cout<< "func(char ch)的调用!" <<endl;

}

void func(char ch, int a)
{
    cout<< "func的int char 的调用" <<endl;
}

void func(int a, char ch)
{
    cout<< "func的int char 的调用" <<endl;
}
int main()
{
// 函数名相同 提高函数复用性

// 同一个作用域
// 名称相同
// 函数参数类型不同 个数不同 顺序不同 

// 函数返回值不可以作为函数重载的条件

    func();
    func(1);
    func('w');
    func(1, 'w');







    return 0;
}