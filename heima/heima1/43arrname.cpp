#include<iostream>
using namespace std;
int main()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<< sizeof(arr1) <<endl;                     // 计算整个数组所占空间的大小
    cout<< sizeof(arr1[0]) <<endl;                  // 计算一个数组所占空间的大小
    cout<<  sizeof(arr1) / sizeof(arr1[0]) <<endl;  //计算数组元素的个数
    cout<< arr1 <<endl;      // 打印数组的首地址
    cout<< &arr1[0] <<endl;  // 打印数组的首地址
    cout<< &arr1[1] <<endl;  // 第二个元素的地址

    

// 数组名就是首地址
// 数组名是常量 不可以进行赋值  指向首地址了


    return 0;
}