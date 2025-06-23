#include<iostream>
using namespace std;
int main()
{

    // int num = 100;
    // int num1 = 0;
    // int num2 = 0;
    // int num3 = 0;
    // int num4 = 100;
    // int sum = 0;
    // do
    // {   num = num4;
    //     num1 = num % 10;
    //     num = num / 10;
    //     num2 = num % 10;
    //     num3 = num / 10;
    //     sum = num1 * num1 * num1 + num2 * num2 * num2 + num3 * num3 * num3;
    //     if(num4 == sum)
    //     {
    //         cout<< num4 <<endl;

    //     }
    //     num4++;
    // } while(num4 < 1000);
    
// 水仙花数
// 个位 num % 10
// 十位 (num / 10) % 10
// 百为 (num / 100) % 10

    int num = 100;
    do
    {
        int a = 0;
        int b = 0;
        int c = 0;
        a = num % 10;
        b = (num / 10) % 10;
        c = (num / 100) % 10;
        if(a*a*a + b*b*b + c*c*c ==num)
        {
            cout<< num <<endl;
        }
        num++;

        
    }while(num < 1000);






    return 0;
}