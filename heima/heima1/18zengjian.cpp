#include<iostream>
using namespace std;
int main()
{
    int a = 3;
    ++a;
    cout<< "a = " << a <<endl;

    int b = 5;
    b++;
    cout<< "b = " << b <<endl;

    int c = a + (b++);  // 4 + 6   先进性表达式的运算 在进行加加
    cout<< "c = " << c <<endl;
    cout<< "b = " << b <<endl;
    

    a = 9;
    b = 9;

    cout<< (++a) * (++b) <<endl;








   system("pause");
   return 0;
}