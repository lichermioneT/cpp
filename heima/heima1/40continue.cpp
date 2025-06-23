#include<iostream>
using namespace std;
int main()
{

// continue结束循环里面的一次  直接进行下一次的循环
    for(int i = 0; i <= 100; i++)
    {   
        if(i % 2 == 0)   // 判断是偶数
        {
            continue;   //  直接跳出去  本次循环后面的代码不在进行
        }
            cout<< i <<endl;
    }




 
    return 0;
}