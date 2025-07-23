#include<iostream>
using namespace std;

class A
{
public:    
    void print()
    {
        cout<< x <<endl;
        cout<< y <<endl;
        cout<< z <<endl;
        cout << y2 << endl;
        cout << z2 << endl;
    }

    static const int y2 = 66;

    // public 的静态变量（类外初始化）
    static int z2;

private:
    const int x = 55;
    static const int y = 66;
    
    // 私有静态变量，必须在类外初始化
    static int z;

};


int A::z = 77;
int A::z2 = 99;

int main()
{
    A a;
    a.print();


// static修饰的属性和方法，直接突破类域酒可以访问了。
// 前提是公共的，访问限定符。
// 常量可以初始化在类里面，变量就不行的

    cout<< A::y2 <<endl;
    cout<< A::z2 <<endl;
}