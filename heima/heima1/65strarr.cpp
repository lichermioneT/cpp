#include<iostream>
#include<string>
using namespace std;

struct student{
    int age;
    int score;
    string name;
};


int main()
{

    struct student stuarry[3] =
    {
        {12,100,"licl"},
        {14,101,"lic2"},
        {14,22,"lidd"}
    };

// 访问元素
    stuarry[0].age = 24;
    stuarry[1].score = 100;
    stuarry[2].name = "lele";
    for(int i = 0; i < 3; i++)
    {
        cout<< stuarry[i].age <<endl;
        cout<< stuarry[i].score <<endl;
        cout<< stuarry[i].name <<endl;
        cout<< "****************" <<endl;
    }







    return 0;
}