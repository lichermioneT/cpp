#include<iostream>
#include<string>
using namespace std;

class person
{
public:
    void setname(string ch)
    {
        name = ch;
    }
    string getname()
    {
        return name;
    }
    void setage(int x)
    {
        if(x >0 && x < 150)
        {
            age = x;
        }
        else
        {
            cout<< "年龄必须是0 - 150" <<endl;
        }
    }
    int getage()
    {
        return age;
    }

    void setidol(string ch)
    {
        idol = ch;
    }
// 自己控制权限
private:
    string name;
    int age = 18;
    string idol;

};

int main()
{
// 成员属性设为私有
// 自己控制权限
// 验证写的有效性

    person p1;
    p1.setname("licx");
    cout<< p1.getname() <<endl;
    cout<< p1.getage() <<endl;
    p1.setidol("caixunkun");
    p1.setage(2222);
    p1.setage(22);
    p1.getage();
    cout<< p1.getage() <<endl;
    return 0;
}