#include<iostream>
using namespace std;
int main()
{

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p = arr;
    // cout<< *p <<endl; // 首地址
    // cout<< *(p + 1) <<endl;
    // cout<< *(p + 2) <<endl;

    for(int i = 0; i < 10; i++)
    {
        cout<< *p <<endl;
        p++;
    }










    return 0;
}