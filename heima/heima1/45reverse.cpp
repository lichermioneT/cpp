#include<iostream>
using namespace std;
int main()
{
    // int arr[6] = {1,2,3,4,5,6};
    // int sz = sizeof(arr) / sizeof(arr[0]);
    // int tem = 0;
    // for(int i = 0; i < sz / 2; i++)
    // {
    //     // 交换两个数字
    //     tem = arr[i];
    //     arr[i] = arr[sz - 1 -i];
    //     arr[sz -1 -i] = tem;

    // }

  

    int arr[6] = {1,2,3,4,5,6};
    int letf = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    if(letf < right)
    {
        int tem = arr[letf];
        arr[letf] = arr[right];
        arr[right] = tem;
        letf++;
        right--;
    }

    
    for(int j = 0; j < 6; j++)
    {
        cout<< arr[j] <<endl;
    }






    return 0;
}