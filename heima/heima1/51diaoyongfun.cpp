#include<iostream>
using namespace std;

// 形式参数
int ADD(int x, int y)
{
    return x + y;
}



int main()
{

    int a = 10;
    int b = 20;


    // 实际参数 a b 形式参数传递给实际参数
    int c = ADD(a, b);   // 函数的调用  函数名(传入参数)    值传递
    cout<< c <<endl;



    return 0;
}