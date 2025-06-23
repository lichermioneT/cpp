#include<iostream>
using namespace std;

int& count()
{
    static int n = 0;
    n++;
    return n;
}

int main()
{
    int& r = count();






    return 0;
}