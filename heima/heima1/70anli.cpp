#include<iostream>
#include<string>
using namespace std;
struct student 
{
    string name;
    int score;
};
struct techer 
{
    string name;
    struct student s[5];
};

void allspace(struct techer t[],int x)
{
    for(int i = 0; i < x; i++)
    {
        
    }
}

int main()
{
    struct techer t[3];
    int len = sizeof(t) / sizeof(t[0]);











    return 0;
}