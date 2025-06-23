#include<iostream>
using namespace std;

void func(int x, int, int = 10)
{
    cout<< "xxxxxxxx" <<endl;
}


int main()
{

// 站位参数  知识写一个数据类型
// 站位参数的默认参数
// 目前站位参数 我们使用不到哦

    func(10,20);
    return 0;
}