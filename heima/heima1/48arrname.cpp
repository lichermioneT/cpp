#include<iostream>
using namespace std;
int main()
{
// 数组名查看占用的空间
    int arr[2][3] = {{1,2,3,},{4,5,6}};
    cout<< sizeof(arr) <<endl;  // 计算整个数组
    cout<< sizeof(arr[0]) <<endl; // 计算一行
    cout<< sizeof(arr[0][0]) <<endl; // 计算一个

    cout<< sizeof(arr) / sizeof(arr[0]) <<endl;  // 计算行数
    cout<< sizeof(arr[0]) / sizeof(arr[0][0]) <<endl; // 计算列数


// 查看首地址
    cout<< arr <<endl;      // 整个数组的首地址
    cout<< &arr[0] <<endl;  // 第一行的首地址
    cout<< &arr[0][0] <<endl; // 第一个元素的首地址  
    //  上面的地址都是一样的
    
    // cout<< &arr[0][1] <<endl;
    cout<< &arr[1] <<endl;   // 第二行元素的首地址
    cout<< &arr[1][0] <<endl; // 第二行第一个地址










    return 0;
}