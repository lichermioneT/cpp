#include<iostream>
using namespace std;
int main()
{

// swith语里面
// 循环
// 嵌套循环

// 游戏难度选择
    // cout<< "选择难度" <<endl;
    // cout<< "1普通" <<endl;
    // cout<< "2中等" <<endl;
    // cout<< "3简单" <<endl;
    // int select = 0;
    // cin >> select;
    // switch (select)
    // {
    //     case 1:
    //         cout<< "您选择普通难度" <<endl;
    //         break;
    //     case 2:
    //         cout<< "您选择中等难度" <<endl;
    //         break;
    //     case 3:
    //         cout<< "您选择简单难度" <<endl;
    //     default :
    //         cout<< "您的选择有误" <<endl;
    //         break;
    // }
 
    // for(int i = 0; i < 10; i++)
    // {
    //     if(i == 5)  // 判断等于是 == 双等于的
    //     {
    //         break;
    //     }
    //     cout<< i <<endl;
    // }

// 嵌套循环里面
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == i)
            {
                break;  // 只能跳出所占的循环
            }
            cout<< "*";
        }
        cout<<endl;
    }















    return 0;
}