#include<iostream>
#include<string>
using namespace std;

struct student{
    // 成员列表
    string name;
    int age;
    int id;
    int score;
}s3;



int main()
{
// 通过点访问成员变量
    struct student s1;
    s1.name = "lichermionex";
    s1.age = 55;
    s1.id = 33;
    s1.score = 100;
    cout<< s1.name <<endl;
    cout<< s1.age <<endl;
    cout<< s1.id <<endl;
    cout<< s1.score <<endl;

// 直接赋值
    struct student s2 = {"lic", 22, 55, 100};
    cout<< s2.name <<endl;
    cout<< s2.age <<endl;
    cout<< s2.id <<endl;
    cout<< s2.score <<endl;

// 
    s3.name = "lichermionex";
    s3.age = 55;
    s3.id = 33;
    s3.score = 100;
    return 0;
}