#include<iostream>
using namespace std;
int main()
{

// 数据类型的意义给变量分配合适的内存空间
// 整形数据类型四种

    short num1 = 10; // -32768~23757
    int num2= 10;
    long num3 = 55;
    long long num4 = 44;

    cout<< sizeof(num1) <<endl;
    cout<< sizeof(num2) <<endl;
    cout<< sizeof(num3) <<endl;
    cout<< sizeof(num4) <<endl;
                    
    cout << "short 类型占用的字节数: " << sizeof(short) << " 字节" << endl;
    cout << "int 类型占用的字节数: " << sizeof(int) << " 字节" << endl;
    cout << "long 类型占用的字节数: " << sizeof(long) << " 字节" << endl;
    cout << "long long 类型占用的字节数: " << sizeof(long long) << " 字节" << endl;

    // 数据分配内存合理 四种整形 一般用int类型

    return 0;

}