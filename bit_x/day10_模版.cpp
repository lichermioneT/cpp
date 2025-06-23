#include<iostream>
#include <string>  // 必须包含这个头文件
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template<class T>
class stack{
private:
    T* _a;
    size_t _size;
    size_t capacity;
};
// stack<int> s1;      // 声明一个存储 int 的栈对象
// stack<double> s2;   // 声明一个存储 double 的栈对象
// stack<string> s3;   // 声明一个存储 string 的栈对象（需 #include <string>）

template<class T>
class vector{
public:
    vector()
        :_a(nullptr)
        ,_size(0)
        ,_capacity(0)
    {
    }
    ~vector()
    {
        delete[] _a;
        _a = nullptr;
        _size = _capacity = 0;
    }

    size_t size()
    {
        return _size;
    }

    // 引用做函数返回值，可以修改数据
    T& operator[](size_t i)const
    {
        assert(i < size);
        return _a[i];
    }

    // 类里面声明，类外面定义
    void push_back(const T& x);
    void pop_back();
private:
    T* _a;
    size_t _size;
    size_t _capacity;
};

template<class T>
void vector<T>::push_back(const T& x)
{
    if(_size == _capacity)
    {
        size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
        T* tmp = new T[newcapacity];
        if(_a)
        {
            memcpy(tmp,_a,sizeof(T)*_size);
            delete[] _a;
        }
        _a = tmp;
        _capacity = newcapacity;
    }
    _a[_size] = x;
    ++_size;
}

template<class T>
void vector<T>::pop_back()
{




}





int main()
{
// 基础语法，函数重载+类和对象，四个成员函数，运算符重载+泛型编程，模板
// 忘记初始化和销毁---构造和析构函数
// 没有封装，谁都可以修改数据----类+访问限定符
// 同时定义int和double两个栈---模板
    // int x = 0;
    // int y = 10;
    // Swap(x,y);
    // cout<< x << " " << y <<endl;
    // Swap<int>(x,y);
    // cout<< x << " " << y <<endl;









    return 0;
}