#include<iostream>
using namespace std;

// 构造函数的分类以及调用分类
class person
{
public:
    person()
    {
        cout<< "person构造函数的调用" <<endl;
    }

    person(int a)
    {
        cout<< "person构造有参数函数的调用" <<endl;
        age = a;
    }

    // 拷贝
    person(const person &p)
    {
        age = p.age;
        cout<< "拷贝构造函数调用" <<endl;
    }

    ~person()
    {
        cout<< "person析构函数的调用" <<endl;
    }
    int age;

};

void test01()
{
    // 括号法
    // person p1;
    // person p2(10);
    // person p3(p2);
    // cout<< p2.age <<endl;
    // cout<< p3.age <<endl;

    // 显示法
    // person p1;
    // person p2 = person(10);    // person(10);   匿名对象 执行结束就被收回了
    // person p3 = person(p2);    

    // 隐士转换法





}


int main()
{
    test01();









    return 0;
}