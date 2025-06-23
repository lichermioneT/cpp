#include<iostream>
using namespace std;
int main()
{
// 多条件语句

// 600 一本
// 500 二本
// 400 三本
// <=400 没考上大学
    int score = 0;
    cout<< "请输入您的高考成绩" <<endl;
    cin >> score;
    cout<< "您的成绩为：" << score <<endl;
    if(score > 600)
    {
        cout<< "您考上一本大学" <<endl;
    }
    else if(score > 500)
    {
        cout<< "您考上二本大学" <<endl;
    }
    else if(score > 400)
    {
        cout<< "您考上三本大学" <<endl;
    }
    else
    {
        cout<< "没有考上大学,大专" <<endl;
    }






    return 0;
}