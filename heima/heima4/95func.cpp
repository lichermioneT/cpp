#include<iostream>
using namespace std;

int func1(int a, int b, int c)
{
    return a + b + c;
}

int func2(int a, int b = 20, int c = 30)
{
    return a + b + c;
}


int main()
{

    cout<< func1(10, 20, 30) <<endl;
    cout<< func2(200) <<endl;
    cout<< func2(200, 1) <<endl;
    cout<< func2(200, 1, 2) <<endl; 

    // 可以默认参数值
    // 某个位置有了默认参数值 从左向右都必须是默认参数
    // 函数声明有默认参数，实现就不能有默认参数
    // 声明和实现只能有一个有默认参数
    int func3(int x,int y);
    cout<< func3(10, 10) <<endl;



    return 0;
}

int func3(int x = 10, int y = 10)
{
    return x + y;
}
