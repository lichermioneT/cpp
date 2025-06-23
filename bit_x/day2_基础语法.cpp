#include<iostream>
#include<time.h>
#include<map>
using namespace std;

// 注意引用是引用 指针是指针
// 引用的本质不是常量指针，是c++特有用的语法
// 指针实现两个数字交换

// 形式参数是实际参数的拷贝
void swap0(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 地址传递
void swap1(int* p1, int* p2)
{
    int temp = *p1;
    *p1  = *p2;
    *p2 = temp;
}

// c++引用实现两个数字交交换
void swap2(int& p1, int& p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

// 传值返回
int count1()
{   
    // 修饰生命周期
    static int n = 0;
    n++;
    return n;   // 返回临时变量的类型就是int  接收的时候会开辟空间的,临时变量具有常属性
}

// 传引用返回  不会产生多余的空间
// 返回值是引用 只能是引用接收
int& count2()
{   
    // 修饰生命周期
    static int n = 0;
    n++;
    return n;  // static修饰了n，这里不会返回临时变量的，n在数据段。
}

int add1(int a, int b)
{
    int c = a + b;
    return c;
}

int& add2(int a, int b)
{   
    // static在定义的是指运行一次
    static int c = a + b;
    return c; // 局部变量的声明周期和作用域
}

struct A
{
    int a[1000];
};


struct A a;

A test1()
{
    return a;
}

A& test2()
{
    return a;
}

int add3(int left, int right)
{
    return left + right;
}

// 内联函数
inline void swap(int& x1, int& x2)
{
    int temp = x1;
    x1 = x2;
    x2 = temp;
}

void fun(int  x)
{
    cout<< "整型" <<endl;
}

void fun(int*  x)
{
    cout<< "整型" <<endl;
}

int main()

{
// 引用的语法:<变量类型>& 别名 = 变量名
// const修饰的引用: const<变量类型>& 别名 = 变量名
// const权限就是只读
// const权限适合引用和指针
// const权限适合引用和指针

    // // 不能进行权限的放大
    // const int a = 10;
    // const int& b = a; 

    // int c = 20;
    // int& d = c;
    // const int& e = c; // 权限的缩小

    // // 这里面只是x的值 不能够更改
    // const int x = 10;
    // int y = x; // 只是读取x的值给y  并不会影响y的权限呢

    // int z = 10;
    // const int r = z; // 这里是用变量初始化数据  

    // const int* cp1 = &a; // cp1指向的东西 不能够改变
    // // int* p1 = cp1; // 不能权限放大了

    // int* p2 = &c;
    // const int* cp2 = p2; // 权限缩小 


// 引用的使用场景，做函数参数和返回值。
// 引用作为函数参数，输出型参数
    // int a = 0;
    // int b = 1;
    // cout<< a <<endl;
    // cout<< b <<endl;

    // swap1(&a, &b);
    // cout<< a <<endl;
    // cout<< b <<endl;

    // swap2(a, b); 
    // cout<< a <<endl;
    // cout<< b <<endl;
    // 引用相当于指针隐藏起来了的

// 引用作返回值
// 一个函数要使用引用返回，返回变量出了这个函数的作用域还存在
// 就可以使用引用返回，否则不安全。
// 一个函数要使用引用作为函数返回值，返回的变量出来作用域变量还在。
    // 临时变量具有常性
    // const int& r1 = count1();

    // int& r2 = count2(); // n的 别名是r2
    // cout<< r1 <<endl;
    // cout<< r2 <<endl;

    // const int& ret = add1(2,4);
    // int x = add1(1,  33);
    // cout<< x <<endl;

    // int& ret = add2(3, 4);
    // cout<< "add(3, 4)" << ret <<endl;
    // add2(3,4);

// 引用返回性能测试
// 返回引用减少拷贝
// 返回引用效率更高
    // size_t begin1 = clock();
    // for(size_t i = 0; i < 1000000; i++)
    // {
    //     test1();
    // }
    // size_t end1 = clock();

    // size_t begin2 = clock();
    // for(size_t i = 0; i < 1000000; i++)
    // {
    //     test2();
    // }
    // size_t end2 = clock();

    // cout<< "test1 = "  << end1 - begin1 <<endl; 
    // cout<< "test2 = "  << end2 - begin2 <<endl; 

// 引用和指针的区别九点区别
    // int  a = 10;
    // int& b = a;  // b就是a的别名  不会开辟空间的 实际上底层是开辟空间的
    // int* p = &a  // 创建一个变量存放一个地址


// 内联函数
    // 空间换时间
    // 声明和定义不要分开
    // 频繁调用函数是有消耗的，需要建立 栈帧，是有消耗的
    // c语言解决用宏函数
    // c++使用内联函数
    // int a = 0;
    // int b = 33;
    // swap(a,b); // inline 每一行都是 展开空间换时间的代价


// 关键字auto
// auto关键字使用在数据容器里面
    // int a = 0;
    // auto b = a; // b的类型是根据a的类型
    // int& c = a;
    // int* p = &a;
    // int* & p2 = p;
    // cout<< typeid(a).name()<<endl;
    // cout<< typeid(c).name()<<endl;
    // cout<< typeid(p).name()<<endl;
    // cout<< typeid(p2).name()<<endl;

    // auto& d = a;
    // auto* e = &a;  //指针变量
    // auto f = &a;   //指针变量
    // cout<< typeid(d).name()<<endl;
    // cout<< typeid(e).name()<<endl;
    // cout<< typeid(f).name()<<endl;

// 关键字for
    // int array[] = {1, 2, 3, 4, 5};
    // c语言实现
    // for(int i = 0; i < sizeof(array) / sizeof(int); ++i)
    // {
    //     array[i] *= 2;
    // }

    // for(int i = 0; i < sizeof(array) / sizeof(int); ++i)
    // {
    //     cout<< array[i] <<endl; 
    // }

    // c++范围for:遍历一个
    // 范围for遍历数组
    // 语法糖
    // for(auto e: array) // 这里面是取出来赋值给e
    // {
    //     e *= 2;
    // }

    // for(auto e: array)
    // {
    //     cout<< e <<endl;
    // }

// 引用和范围for循环
// 数组传参就退化为指针 int array[]

    // for(auto& e: array) // 这里面是取出来的值就是实际值的本身
    // {
    //     e *= 2;
    // }

    // for(auto e: array)
    // {
    //     cout<< e <<endl;
    // }

// c++空指针 nullptr
    // c++里面 NULL == 0
    // #define NULL 0
    // c 
    // int* p1 = NULL;
    // C++
    // int* p2 = nullptr;
    // fun(10);
    // fun(NULL); c++里面预处理过后就是fun(0)
    // fun(nullptr); // fun((void*)0)

    // int a = 6;
    // int* p = &a;
    // int*& pr = p;
    // cout<< pr <<endl;

// 类的开头
// c语言结构体只能定义变量，c++结构体既能定义变量也能定义函数
// 类的声明和定义分开
// 访问限定符：public,protected,private
// class默认限定符private,struct默认限定符public
class person
{

public:
    void print()
    {
        cout<< this->_name<<endl;
        cout<< this->_age<<endl;
        cout<< this->_weight<<endl;
    }

// 成员属性一般不让外面看见，可以设计接口，通过接口按规则修改
    char* _name;
    int _age;
    int _weight;
};

// 实例public
    // person p1;
    // p1._name = "tom";
    // p1._age = 55;
    // p1._weight = 80;
    // p1.print();


// 类定义一个栈
class stack
{
public:
    void init()
    {

    }

    void destory()
    {

    }

    void push()
    {

    }

    void pop()
    {
        
    }


private:
    int* _a;
    size_t _top;
    size_t _capacity;
};





    return 0;
}