#include<iostream>
using namespace std;
int main()
{

    int score = 0;

    cout<< "请输入您的高考成绩" <<endl;
    cin >> score;
    cout<< "您的高考成绩为:" << score <<endl;

    if(score > 600)
    {
        cout<< "工恭喜您考上一一本大学\n" <<endl;
    }
    else
    {
        cout<< "还需要继续努力" <<endl;
    }







    return 0;
}