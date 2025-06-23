#include<iostream>
using namespace std;

// 引用作为重载的条件
void func(int& a)
{
    cout<< "func int &的调用" <<endl;
}

void func(const int& a)
{
    cout<< "func const int &的调用" <<endl;
}


// 避免默认参数
void func2(int a,int b = 10)
{
    cout<< "func 2 int int " <<endl;
}

void func2(int a)
{
    cout<< "func 2 int" <<endl;
}

int main()
{

    int a = 10;
    // func(a);
    // func(10);
    func2(20, 10);













    return 0;
}