#include<iostream>
using namespace std;

// 对象的初始化和清理
// 构造函数：Constructor 用于初始化对象，通常在声明对象时自动调用。
// 析构函数：Destructor  用于释放资源，在对象销毁时自动调用。
class person
{

public:
    person()
    {   
        cout<< "person构造函数的调用" <<endl;
    }

    ~person()
    {
        cout<< "person的析构函数调用" << endl;
    }

};

void test01()
{
    person p1;    // 栈区的数据
}

int main()
{

    // test01();  // 自动调用 而且自会调用一次的

    person p2;



    system("pause");


    return 0;
}