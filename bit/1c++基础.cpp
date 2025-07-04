#include <iostream>
using namespace std; // c++库所有东西都在std命名空间里面

// cs 客户端  
// bs 网页端  
// 刷题 多读书
// 剑指offer, 系统， 网络
// 刷题
// 刷题：200道不多。200道加
//

namespace N
{
    int num1 = 55;
    int num2 = 66;
    int add(int x, int y)
    {
        return x + y;
    }
}


void Func(int x = 1, int y = 2, int z = 3)
{
    cout<< "x = " << x <<endl;
    cout<< "y = " << y <<endl;
    cout<< "z = " << z <<endl;
}

void Func2(int x, int y = 2, int z = 3)
{
    cout<< "x = " << x <<endl;
    cout<< "y = " << y <<endl;
    cout<< "z = " << z <<endl;
}


int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

int add(int x, int y, double d)
{
    return x + y + (int)d;
}




int main()
{

//  int num1 = 55;
//  cout<< "num1 = " << num1 <<endl;

/*
    cout<< N::num1 <<endl;

    {
        using N::num1;
        cout<< num1 <<endl;
    }
    
    {
        using namespace N;
        cout<< N::num1 <<endl;
    }
*/

/*
    cout<< "hello world\n";
    cout<< "hello world" <<endl;
    
    int a = 10;
    char ch = 'w';
    cout<< "ch = " << ch <<endl;
    cout<< "a = " << a <<endl;
*/


/*
    int num = 0;
    char ch = '0';
    cin>>num>>ch;
    cout<< "num = " << num <<endl;
    cout<< "ch = " << ch <<endl;
*/


// 缺省参数
// 半缺省只能是从右往左
// 参数连续串
// 缺省参数也叫默认参数
// 默认参数可以不传，不是默认参数的必须传参数

/*
    Func();
    Func(2);
*/

// 函数重载
// 函数名修饰规则
    cout<< add(2, 4) <<endl;
    cout<< add(2, 4, 4) <<endl;
    cout<< add(2, 4, 4.2) <<endl;





















    


    return 0;
}

