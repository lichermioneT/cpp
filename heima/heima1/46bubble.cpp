#include<iostream>
using namespace std;
int main()
{

    int arr[14] = {1,2,3,4,5,6,7,8,9,10,14,0,47,96};
    int tem = 0;
    for(int i = 0; i < 13; i++)  //排序排13次
    {
        for(int j = 0;j < 14 - 1 -i; j++) // 每次排序次数减一
        {
            if(arr[j] > arr[j+1])
            {
                tem = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = tem;
            }
        }
    }
    for(int i = 0; i < 14; i++)
    {
        cout<<arr[i]<<endl;
    }








    return 0;
}