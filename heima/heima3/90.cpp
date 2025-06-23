#include<iostream>
using namespace std;
int main()
{

// 引用就要初始化
    int a = 100;
    int& b = a;

// 引用一旦初始化就不可以更该了
    int c = 20;
    // int& b = c; 不能再初始化了   
    b = c;
    cout<< "a =" << a <<endl;
    cout<< "b =" << b <<endl;
    cout<< "c =" << c <<endl;











    return 0;
}