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



    return 0;
}

