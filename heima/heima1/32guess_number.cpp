#include<iostream>
#include<ctime>
using namespace std;
int main()
{
// 随机数字的生成
// 玩家猜测
// 判断玩家的猜测 返回上一步
    // 随机数种子 根据时间
    srand((unsigned int)time(NULL));
    int num = rand()%101; // 1 - 100的随机数
    // cout<< num <<endl;
    int guess_num = 0;
    int flag = 1;
    while (flag)
    {
        cin >> guess_num;
        if(guess_num > num)
        {
            cout<< "您猜测的数字过大" <<endl;
        }
        else if(guess_num < num)
        {
            cout<< "您猜测的数字过小" <<endl;
        }
        else
        {
            // flag =0;
            break;  // 退出一层循环的
        }
    }
    









    return 0;
}