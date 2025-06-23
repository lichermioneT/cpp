#include<iostream>
#include<string>
using namespace std;

// 公共权限 public      成员在类里面可以访问  类外可以访问
// 保护权限 protectded  成员在类里面可以访问  类外不可以访问   可以继承
// 私有权限 private     成员在类里面可以访问  类外不可以访问     不能继承

class Person
{
public:
    string name;

protected:
    string car;

private:
    int passwd;

public:
    void func()
    {
        name  = "张三";
        car = "tesla";
        passwd = 1024;
    }
};

int main()
{

    Person p1;
    p1.name = "lichermionex";
    //p1.car     不可以访问的
    //p1.passwd  不可以访问的
    return 0;
}