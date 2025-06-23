#include<iostream>
using namespace std;
int main()
{

// 单引号 只能存放一个字符
// 单引号 一个字符

    char ch = 'x'; // 存放对应的ASCII
    cout<< ch <<endl;

    cout<< "char所占字节:" << sizeof(char) <<endl;

    cout<< (int)ch <<endl;


    


    return 0;
}