#include<iostream>
using namespace std;
int main()
{

// 单精度
    float f = 3.141665555f;  // float注意添加f  一般默认是double 后面写个f好声明
    cout<< "f = " << f <<endl;

// 双精度
    double d = 55.31222;
     cout<< "d = " << d <<endl;


// c++ 默认显示六位有效数字


// 计算内存所占的空间
    cout<< "float占用的空间为" << sizeof(float) <<endl;
    cout<< "double占用的空间为" << sizeof(double) <<endl;
    // float占四个字节
    // double占8个字节


// 科学计算法 也可以表示小数
    float f2 = 3e2;
    cout<< "f2 = " << f2 <<endl;

    float f3 = 3e-2;
    cout<< "f3= " << f3 <<endl;






    return 0;
}