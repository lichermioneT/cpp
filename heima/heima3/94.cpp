#include<iostream>
using namespace std;

// const int& ref = x;
// 不能 x = 100; 修改x的值了

void showvalue(const int& val)
{   
    // val = 10 不能修改val的值了
    cout<< "val = " << val <<endl;
}

int main()
{

// 常量引用
// 用来修饰形式参数 防止修改
    // int a = 10;
    // int& ref = a; // 应用一块合法的区域 int& ref = 10;
    // const int& ref = 10;

    int a = 100;
    showvalue(a);  // 形式参数和实际的修改





    return 0;
}