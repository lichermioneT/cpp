#include<iostream>
using namespace std;
int main()
{

    // 10 9 经典
    // 8  7 非常好
    // 6 5 一般
    // 烂片
    // switch里面只能是整形变量
    // 结构清晰 执行效率更高
    // 缺点不是区间

    int score  = 0;
    cout<< "请输入您的评分" <<endl;
    cin >> score;
    switch(score)
    {
        case 10:cout<< "经典电影" <<endl;break;  // break里面跳出循环语句
        case 9:cout<< "经典电影" <<endl;break;
        case 8:cout<< "好电影" <<endl;break;
        case 7:cout<< "好典电影" <<endl;break;
        case 6:cout<< "一般电影" <<endl;break;
        case 5:cout<< "一般电影" <<endl;break;
        default:cout<< "烂片" <<endl;break;    // default也要添加 break 后面的添加代码

    }
    return 0;
}