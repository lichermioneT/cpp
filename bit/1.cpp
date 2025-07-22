#include<iostream>
using namespace std;

template<class T>
T add(T& x, T& y)
{
    return x + y;
}


template<class T>
void Swap(T& x1, T& x2)
{
    T temp = x1;
    x1 = x2;
    x2 = temp;
}

int main()
{

// 类型的自定义推导
    int a = 1;
    int b = 2;
    cout<< add(a, b) <<endl;
    Swap(a,b);

    char ch1 = 'z';
    char ch2 = 'a';
    cout<< add(ch1, ch2) <<endl;
    Swap(ch1, ch2);

    float f1 = 55.2f;
    float f2 = 55.2f;

// 显示的自定义类型
    float f3 = add<float>(f1,f2);
    cout<< f3 <<endl;

}