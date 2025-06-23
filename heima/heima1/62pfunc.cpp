#include<iostream>
using namespace std;

void swap1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    
}


void swap2(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main()
{
    int a = 10;
    int b = 20;
    cout<< a <<endl;
    cout<< b <<endl;

// 值传递
    swap1(a, b);
    cout<< a <<endl;
    cout<< b <<endl;


// 址传递
    swap2(&a, &b);
    cout<< a <<endl;
    cout<< b <<endl;








    return 0;
}