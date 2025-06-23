#include<iostream>
using namespace std;

void func(int& ref)
{
    ref = 100;  // *ref = 100;
}
int main()
{

// 引用的本质
    int a = 10;

    // int* const ref = &a; 指针常量 一旦初始化就不能修改了
    // ref 只能指向 a的地址 
    int& ref = a;
    
    // 相当于 *ref = 20
    ref = 20;

    cout<< "a = " << a <<endl;
    cout<< "ref = " << ref <<endl;

    func(a);
    cout<< "a = " << a <<endl;


    return 0;
}