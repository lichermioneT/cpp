#include<iostream>
using namespace std;

// 不要返回局部变量的引用
// int& test01()
// {
//     int  a = 10;
//     return a;
// }

int& test02()
{
    static int a = 10;
    return a;
}
int main()
{
    int& ref = test02();
    cout<< "ref = " << ref <<endl;
    cout<< "ref = " << ref <<endl;

    // 函数调用作为左值
    test02() = 100;
    cout<< "ref = " << ref <<endl;
    cout<< "ref = " << ref <<endl;











    return 0;
}