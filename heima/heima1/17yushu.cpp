#include<iostream>
using namespace std;
int main()
{

    int num1 = 10;
    int num2 = 3;
    cout<< "num1 % num2 = " << (num1 % num2) <<endl;

    num1 = 10;
    num2 = 20;
    cout<< "num1 % num2 = " << (num1 % num2) <<endl;

    num1 = 4455;
    num2 = 554;
    cout<< "num1 % num2 =" << (num1 % num2) <<endl;  // 一个数取余数 只会小于被取余数的数字
    // 不能对0取余数


    return 0;
}