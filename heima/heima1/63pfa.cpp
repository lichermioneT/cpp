#include<iostream>
using namespace std;

void bubblesort(int* p, int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i -1; j++)
        {
            if((*p) < (*(p+1)))
            {
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
}

int main()
{

    // 1数组
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int sz = sizeof(arr) / sizeof(arr[0]);
    // 2创建函数
    bubblesort(arr, sz);
    // 3打印结构

    for(int j = 0; j < sz; j++)
    {
        cout<< arr[j] <<endl;
    }





    return 0;
}