#include<iostream>
using namespace std;
int main()
{

// 数组放在一块连续的空间里面
// 数组里面的数据都是相同类型的
// 数组定义方式三种

// 数组的长度必须知道
    int arr1[10];
    // arr1[0] = 10; // 赋值
    cout<< arr1[0] <<endl; // 访问元素是从零开始的
    
    int i = 0;
    int arr2[10] = {1,2,3,4,5};
    while (i < 10)  // 没有初始化的数据就是zero
    {
        cout<< arr2[i] <<endl;
        i++;
    }
    

    i = 0;
    int arr3[] = {1, 2, 3, 4, 5};
    while (i < 5)
    {
        cout<< arr3[i] <<endl;
        i++;
    }
    return 0;
}