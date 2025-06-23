#include<iostream>
using namespace std;
int main()
{

    int arr1[2][3]; // 同样二位数组的访问都是零开始的  访问和赋值都是从零开始的
    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[0][2] = 3;

    arr1[1][0] = 3;
    arr1[1][1] = 4;
    arr1[1][2] = 6;

    // for(int i = 0; i < 2; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         cout<< arr1[i][j]<<endl;
    //     }
    // }


    int arr2[2][3] = {{1,2,3},{4,5,6}};  // 推荐这种方式定义
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //     {
    //         cout<< arr1[j][i]<<endl;
    //     }
    // }

    int arr3[2][3] = {1,2,3,4,5,6};

    // for(int i = 0; i < 2; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         cout<< arr1[i][j]<<endl;
    //     }
    // }


    int arr4[][3] = {1,2,3,4,5,6};  // 列数不可以省略的
    // for(int i = 0; i < 2; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         cout<< arr1[i][j]<<endl;
    //     }
    // }













    return 0;
}