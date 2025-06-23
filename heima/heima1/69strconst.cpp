#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

void cout_s(const struct student* p)
{
    cout<< p->name <<endl;
    cout<< p->age <<endl;
    cout<< p->score <<endl;
}

int main()
{

    struct student s = {"kic", 55, 66};
    cout_s(&s);







    return 0;
}