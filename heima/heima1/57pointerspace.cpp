#include<iostream>
using namespace std;
int main()
{

    // 指针变量就是用来存放地址的
    // 64八个字节
    // 32四个字节
    int* p = NULL;
    cout<< sizeof(p) <<endl;
    cout<< sizeof(int*) <<endl;


    return 0;
}