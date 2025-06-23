#include<iostream>
#include<string>
using namespace std;

struct stu
{
    string  name;
    int age;
    int score;
};
void pint_stu1(struct stu s)
{
    cout<< s.name <<endl;
    cout<< s.age <<endl;
    cout<< s.score <<endl;

}

void pint_stu2(struct stu *p)
{
    cout<< p->name <<endl;
    cout<< p->age <<endl;
    cout<< p->score <<endl;

}

int main()
{

    struct stu s;
    s.name = "lihaiju";
    s.age = 50;
    s.score = 100;

    pint_stu1(s); // 拷贝一份过去就行的
    pint_stu2(&s);








    return 0;
}