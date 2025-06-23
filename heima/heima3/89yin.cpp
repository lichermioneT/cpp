#include<iostream>
using namespace std;
int main()
{

// 引用， 给变量取别名
    int a = 100;
    cout<< "a = " << a <<endl;

    // 创建引用
    int& b = a;
    b = 20;
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;






}