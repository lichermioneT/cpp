#include<iostream>
using namespace std;
int main()
{

    int x = 100;
    int* p = &x;       // 定义int类型的指针

    *p =500;   // 通过地址找到数据
    cout<< x <<endl;
    cout<< "p的地址为:" << p <<endl;
    cout<< "x的地址为:" << &x <<endl;
    return 0;
}