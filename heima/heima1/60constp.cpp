#include<iostream>
using namespace std;
int main()
{

    int a = 100;
    int b = 100;

// 常量指针
    const int* p1 = &a;  // 指针的指向可以修改
    p1 = &b;

// 指针常量
    int * const p2 = &a; // 指针指向的值可以修改
    *p2 = 20;

// 常量指针常量
    const int* const p3 = &a; // 指针的指向和值都不可以修改的





    return 0;
}