#include<iostream>
using namespace std;
int main()
{
    // int arr[5] = {10,20,400,22,30};
    // int max_weight = arr[0];
    // int i = 1;
    // while (i < 5)
    // {
    //     if(max_weight > arr[i])
    //     {
    //         ;
    //     }
    //     else
    //     {
    //         max_weight = arr[i];
    //     }
    //     i++;
    // }
    
    int arr[5] = {10,20,400,22,30};
    int max = 0;  // 我认为他就是最大值  就和里面的元素一一比较
    for(int i = 0; i < 5; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    cout<< max <<endl;











    return 0;
}