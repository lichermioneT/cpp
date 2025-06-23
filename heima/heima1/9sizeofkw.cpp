#include<iostream>
using namespace std;
int main()
{

    short num1 = 5;
    cout<< "short占用的空间为:"<< sizeof(num1) <<endl;

    int num2 = 55;
    cout<< "int占用的空间为:"<< sizeof(int) <<endl;

    long num3 = 55;
    cout<< "long占用的空间为:"<< sizeof(long) <<endl;

    long long num4 = 66;
    cout<< "long long占用的空间为:"<< sizeof(long long) <<endl;

// sizeof(short) <= sizeof(int) <= sizeof(long) <=sizeof(long long)






    return 0;
}