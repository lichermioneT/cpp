#include <iostream>

using namespace std; // c++标准命名空间std;

// 命名空间
namespace N
{
    int a = 10;
    int b = 20;
}


// 缺省参数
void Func(int x = 55)
{
    cout<< " x = " << x <<endl;
}

// 全缺省
void Func2(int x = 55, int y = 44, int z = 11)
{
    cout<< " x = " << x <<endl;
    cout<< " y = " << y <<endl;
    cout<< " z = " << z <<endl;
}

// 半缺省,只能是写在最后面的数据
void Func3(int x, int y = 33, int z = 77)
{
    cout<< " x = " << x <<endl;
        cout<< " y = " << y <<endl;
     cout<< " z = " << z <<endl;

}

// 函数重载
// 函数参数类型，参数个数，参数顺序。
int add(int x, int y)
{
    return  x + y;
}

float add(float x, float y)
{
    return  x + y;
}


long add(long x, long y)
{
    return  x + y;
}



void print(int x)
{
    cout<< "x = " << x <<endl;
}

void print(float f)
{
    cout<< " f = " <<endl;
}





int main()
{

// 命名空间的三种使用方法
/*
    cout<< N::a <<endl;
    {
        using N::a;
        cout<< a <<endl;
    }

    {
        using namespace N;
        cout<< a <<endl;
    }
*/

// c++输入输出

/*
    cout<< "hello c+++"<<endl;
    
    int i = 10;
    double d = 44.4;
    float f= 9.5f;

    char ch = 'x';

    cout<< " i = " << i <<endl;
    cout<< " d = " << d <<endl;
    cout<< " f = " << f <<endl;
    cout<< " ch = " << ch <<endl;
*/


// c++缺省参数
   // Func(55);
   // Func2();
   // Func3(2);


// 函数重载
    
    cout<< add(22,44) <<endl;

    print(55);
    print(2.2f);


// 函数名字修饰规则，函数 + 函数的参数就可以区别出来调用的是哪个函数










































































































    return 0;
}

