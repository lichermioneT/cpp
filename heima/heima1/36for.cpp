#include<iostream>
using namespace std;
int main()
{

    for(int i = 1; i <= 100; i++)
    {
        if(i % 7 == 0)  // 倍数 
        {
            cout<< "敲桌子" << i <<endl;
        }
        else if(i % 10 == 7)
        {
             cout<< "敲桌子" << i <<endl;
        }
        else if( i / 10 ==5)
        {
             cout<< "敲桌子" << i <<endl;
        }
    }

// 一个数的倍数  55 % 5 = 0 则55是5的倍数
 












    return 0;
}