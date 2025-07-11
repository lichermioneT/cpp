#include <iostream>
using namespace std;

void SWAP(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


int T = 66;

int  count(int& T)
{
    return ++T;
}





int main()
{

/* 引用的复习，引用的权限 */
    int a = 10;
    const int& ra = a;
    
    const int b = 55;
    const int& rb = b;

    const int c = 66; // 这里面的引用只能是只读的 不能够进行权限的放大

    const int x = 99;
    const int y = x;

// 引用的语法
// 类型& 名称 = 变量名
//
//
//
//
//
// 
// 引用做函数参数
    int num1 = 99;
    int num2 = 66;

    SWAP(num1, num2);
    /* cout<< num1 <<endl; */
    /* cout<< num2 <<endl; */
    
    int t = count(T);
    /* cout<< t <<endl; */









    return 0;
}

