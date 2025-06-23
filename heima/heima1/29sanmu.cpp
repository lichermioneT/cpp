#include<iostream>
using namespace std;
int main()
{

    int a = 10;
    int b = 20;
    int c = 0;

    // c++里面返回的变量 可以继续赋值
    c = (a > b? a : b);
    cout<< "c = " <<c <<endl;

    (a < b? a:b) = 100;
    cout<< "a = " << a <<endl;






    return 0;
}