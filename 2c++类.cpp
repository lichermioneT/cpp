#include <iostream>
#include <typeinfo>
using namespace std;

void SWAP(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


int T = 66;

int  count(int& T)
{
    return ++T;
}



int count1()
{
    int x = 1;
    return x;
}

int& count2()
{

}


int& count3()
{
// x 是一个 静态局部变量，只初始化一次，函数每次调用都会使用同一个 x。
// 它的生命周期是整个程序运行期（不像普通局部变量，每次调用都会创建新的）。
    static int x = 44;
    return x;
}

int& add(int x, int y)
{
    static int c = 0;
    c = x + y;
    return c;
}

inline void sub(int& a, int& b)
{
    cout<< (a - b) <<endl;
}


inline int square(const int& x)
{
    return x * x;
}

class person
{

// 成员属性：变量
// 成员方法：函数

    // 方法
    void print()
    {

    }

    // 属性
    char _name[20];
    int _age;

};

class student
{
public:
    void print()
    {
    
    cout<< _name <<endl;
    cout<< _age <<endl;
    cout << _stdid <<endl;


    }

    int GetAge()
    {
        return _age;
    }
private:
    char _name[20];
    int _age;
    int _stdid;
};

class stack
{
public:
    void Init()
    {
        //
    }
    
    void Destory()
    {
        //
    }
    
    void Push()
    {
        //
    }

    void Pop()
    {
        //
    }

private:
    int* _a;
    size_t _top;
    size_t _capacity;
};

int main()
{

/* 引用的复习，引用的权限 */
    int a = 10;
    const int& ra = a;
    
    const int b = 55;
    const int& rb = b;

    const int c = 66; // 这里面的引用只能是只读的 不能够进行权限的放大

    const int x = 99;
    const int y = x;

// 引用的语法
// 类型& 名称 = 变量名
//
//
//
//
//
// 
// 引用做函数参数
    int num1 = 99;
    int num2 = 66;

    SWAP(num1, num2);
    /* cout<< num1 <<endl; */
    /* cout<< num2 <<endl; */

// 引用做函数的返回值，出来函数的作用域，变量还必须存在。
    int t = count(T);



// 传值返回，返回的是变量的临时拷贝。
// 因为临时变量具有常属性，所以需要const进行接收
//
    const int& rrc = count1();


// 传值都会产生拷贝，传引用不会产生拷贝。
// static修饰的是声明周期
    int temp = count3();
    cout<< (temp + 44) <<endl;


// 引用作为函数的返回值，如果返回的是函数体内的局部变量，不安全
// 函数的栈帧已经结束了，外面还可以访问这块空间

// 总结：一个函数要使用引用作为函数的返回值，返回的变量出了
// 这个函数，作用域还在就可以使用引用返回，否则不安全

// 优点：
// 少创建临时变量：提高效率
// 类里面的拷贝构造
// 引用返回可以进行赋值
// 做参数和返回值

// 引用没有独立空间，和引用实体共用一块空间






// 内联函数
// inline修饰函数
//  “内联函数直接展开”这个说法，说的是编译器在编译期间，将函数调用处替换为函数体代码本身的过程。
//  这个展开不是在你写代码时可见的，而是发生在编译器优化阶段。
// 空间换时间


// 频繁调用是有消耗的的
// c语言使用宏函数
// c++使用内联函数
    int num3 = 4;
    int sum1 = square(num3);
    // int sum = num3 * num3;

// 内联函数声明和定义不能分开，
// const替换宏常量
// 内联函数替代宏函数

// auto关键字
    int num4 = 33;
    auto num5 = num4;
    /* cout<<(typeid(num5).name()) <<endl; */

// auto关键字
// 后面的STL里面使用


    int arr[] = {1,2,3,5,8,6,4,56,2,1,22,333,22,23};
    for(auto e : arr)
    {
        cout<< e << " ";
    }
    cout<<endl;
    
    for(auto& e: arr)
    {
        cout<< e * 2 << " ";
    }
    cout<<endl;


// c++11推荐的新，新指针的用法
    int* p1 = NULL;
    int* p2 = nullptr;
// 因为NULL是零，不是空指针
// 建议使用nullptr是空指针


// 面向过程关注步骤
// 面向对象关注对象之间的关系

// c语言结构只能定制变量
// c++结构体可以定义变量和函数

// 万事万物皆是对象
// 成员属性
// 成员方法


// 声明和定义分离
// 封装性
// 继承性
// 多态性


    student s1;
    s1.print();
    cout<< s1.GetAge() <<endl;

//  class默认是私有的访问限定符
//  struct默认是公有的访问限定符
//  c++支持c语言，struct可以当做结构体用

































    return 0;
}

