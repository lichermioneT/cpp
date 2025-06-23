#include<iostream>
using namespace std;
int main()
{

// 与或非
    // 逻辑非  非零表示真的
    int a = 2;
    cout<< !a <<endl;
    int b = 0;

    // 逻辑或  其中一个逻辑是真的就是真的 同假为假 其余为真
    cout<< (a || b) <<endl; 

    // 逻辑与 两个逻辑都是真的才能是真的  同真为真 其余为假
    cout<< (a && b) <<endl;




    return 0;

}