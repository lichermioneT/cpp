#include<iostream>
using namespace std;

void swap01(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap02(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap03(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{

    int a = 10;
    int b = 20;

    swap01(a, b);    
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;

    swap02(&a, &b);
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;

    swap03(a, b);
    cout<< "a = " << a <<endl;
    cout<< "b = " << b <<endl;


    
    return 0;
}