#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

struct teacher
{
    int id;
    string name;
    int age;
    struct  student stu;  // 定义在前面
};


int main()
{

// 嵌套循环里面 一层一层的访问 通过.
    struct teacher t1;
    t1.id = 10;
    t1.name = "licx";
    t1.age = 55;
    t1.stu.name = "xiaohai";
    t1.stu.age = 20;
    t1.stu.name = 100;






    return 0;
}