#include <iostream>
using namespace std;

class stack
{
public:
    stack(int n = 10)
    {
        if( n > 0 )
        {
            _a = (int*)malloc(sizeof(int) * n);
            _size = 0;
            _capacity = n;
        }
    }

    ~stack()
    {
        free(_a);
        _a = nullptr;
        _size = _capacity = 0;
    }



private:
    int* _a;
    int _size;
    int _capacity;

};

int main()
{
// 六个默认构造函数

// 拷贝构造:初始化
// 赋值构造:已经存在的

// 构造函数
// 析构函数

// 取地址重载

// 我们不写会自动生成，自定义类型调用这个函数的构造和析构
// 我们不写会自动生成，拷贝和赋值是浅拷贝,一些类不需要写
// 浅拷贝就是值拷贝，会导致指针拷贝过去，一块空间释放两次
//

    return 0;
}

