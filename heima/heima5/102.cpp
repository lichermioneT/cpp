#include<iostream>
using namespace std;

class c1
{
    int a;  // 私有权限
};

struct c2
{
    int b;

};

int main()
{

// class和struct的区别
// struct默认权限是public
// class默认权限是private

    c1 c2;
    struct c2 c;
    c.b = 100;








    return 0;
}