#include<iostream>
using namespace std;

const double PI  = 3.14;

// 设计一个圆圈类计算周长

class Circle
{  
//权限  下面是公共权限
public:

    // 属性 变量
    int m_r;  // 半径

    // 行为 函数
    double calculateZC()
    {
        return 2 * PI * m_r;      // 直接调用类里面的成员变量
    }
    
};


int main()
{

// 设计类创建对象
    // 创建一个对象
    Circle c1;   //  实例化一个对象  .操作在类下面两种操作方法
    c1.m_r = 10;
    // double len = c1.calculateZC();
    // cout<< len <<endl;
    cout<< "圆的周长为:" << c1.calculateZC() <<endl;



    return 0;
}