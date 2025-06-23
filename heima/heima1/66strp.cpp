#include<iostream> 
#include<string>
using namespace std;

struct stu
{
    string name;
    int age;
    int score;
};
int main()
{

// 创建结构体变量
    struct stu s = {"张珊", 11, 55};

// 穿件结构体指针
    struct stu* p = &s;

// 访问元素
    cout<< p->name <<endl;
    cout<< p->age <<endl;
    cout<< p->score <<endl;











    return 0;
}