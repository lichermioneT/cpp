#include<iostream>
using namespace std;
int main()
{
// 三只小猪称体重
    int a, b, c;
    cout<< "请您输入三只小猪的体重 用空格隔开" <<endl;
    cin >> a >> b >> c;
    if(a > b)
    {
        if(a > c)
        {
            cout<< "里面最大的就是a:" << a <<endl;
        }
    }
    else
    {
        if(b > c)
        {
            cout<< "里面最大的就是b:" << b <<endl;

        }
        else
        {
            cout<< "里面最大的就是c:" << c <<endl;

        }
    }


/*
    int a, b, c;
    cout << "请您输入三只小猪的体重：" << endl;
    cin >> a >> b >> c;

    // 找出最大值
    int maxWeight = a;  // 默认a为最大值
    if (b > maxWeight) {
        maxWeight = b;
    }
    if (c > maxWeight) {
        maxWeight = c;
    }

    cout << "里面最大的就是: " << maxWeight << endl;
*/









}