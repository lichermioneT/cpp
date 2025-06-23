#include<iostream>
using namespace std;

void swap(int x , int y)
{   
    cout << x <<endl;
    cout << y <<endl;

    int tem = x;   
    x = y;
    y = tem;
    cout << x <<endl;
    cout << y <<endl;
}
int main()
{

    int a = 55;
    int b = 44;
    cout<< a <<endl;
    cout<< b <<endl;
    swap(a, b);        // 值传递给 x, y 不会影响实际参数的
    cout<< a <<endl;
    cout<< b <<endl;










    return 0;
}