#include<iostream>
#include<string>
using namespace std;

class Student
{

// 属性称作成员  成员属性 成员变量
// 行为称作成员  成员方法 成员函数
public:
    int id;
    string name;

    void print_info(void)
    {
        cout<< "学生的id:" << id <<endl;
        cout<< "学生的name:" << name <<endl;
    }

    // 行为给赋值
    void setid(int x)
    {
        id = x;
    }

    void setname(string ch)
    {
        name = ch;
    }

};







int main()
{

    Student s1;
    // .操作符 在类面的使用
    s1.id = 24;
    s1.name = "lichermionex";
    s1.print_info();

    Student s2;
    s2.id = 25;
    s2.name = "licx";
    s2.print_info();

    Student s3;
    s3.setid(5);                
    s3.setname("lic");
    s3.print_info();





    return 0;
}