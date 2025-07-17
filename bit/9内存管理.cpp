#include <iostream>
using namespace std;

class a
{
public:
    a()
    {
        cout<< " a " <<endl;
    }

    ~a()
    {
        cout<< " ~a " <<endl;
    }

};

struct listnode
{
    int _val;
    struct listnode* _next;
    struct listnode* _prev;
};


typedef struct listnode listnode;

listnode* buylistnode(int val)
{
    struct listnode* node_c = (struct listnode*)malloc(sizeof(struct listnode));
    node_c->_val = 1;
    node_c->_next = NULL;
    node_c->_prev = NULL;
    
    return node_c;
}

void destorylistnode(listnode* node)
{

}

struct listnode_cpp
{
    int _val;
    listnode_cpp* _next;
    listnode_cpp* _prev;

    // 兼容c语言
    // struct listnode_cpp* _next;
    // struct listnode_cpp* _prev;

    listnode_cpp(int val = 1)
        :_val(val)
        ,_next(nullptr)
        ,_prev(nullptr)
    {
        cout<< " listnode_cpp" <<endl;
    }

    ~listnode_cpp()
    {
        cout<< " ~listnode_cpp " <<endl;   
    }
};


class b
{
public:
    b()
    {
        n++;
    }

    b(const b& that)
    {
        n++;
    }
    
    void print_n()
    {
        cout<< n <<endl;
    }

    static void print_nn()
    {
        cout<< n <<endl;
    }

private:
    static int n;
};

int b::n = 0;



class c
{
public:
    c()
    {
       cout<< " c " <<endl; 
    }

    ~c()
    {
        cout<< " ~c " <<endl;
    }

private:
    int _a;
};



class d
{
public:
    d(int a)
        :_a(a)
    {
        cout<< " d " <<endl;
    }

    ~d()
    {
        cout<< " ~d " <<endl;
    }



private:
    int _a;
};

// template<typename T>
template<class T>
void Swap(T& x1, T& x2)
{
    T temp = x1;
    x1 = x2;
    x2 = temp;
}





int main()
{
    // int* p1  = new int;
    // int* p2  = new int(10);
    // delete p1;
    // delete p2;

    // int* p3 = new int[10];
    // delete[] p3;

    


// 内置类型new和malloc一样的
// 针对自定义类型不一样的

    // int* p1 = (int*)malloc(sizeof(int));
    // int* p2 = new int(22);

    // struct listnode* node_c = (struct listnode*)malloc(sizeof(struct listnode));
    // node_c->_val = 1;
    // node_c->_next = NULL;
    // node_c->_prev = NULL;
    

    // listnode_cpp* node1 = new listnode_cpp;      // 调用默认构造函数
    // listnode_cpp* node2 = new listnode_cpp(100); // 调用构造函数
    
    // delete node1;
    // delete node2;

// c++定义一个对象就初始化数据
// new/delete 开空间的时候讲究初始化和清理


// 结论就是
// 推荐使用new和delete
    
    // listnode_cpp a[10];
    // 直接调用构造和析构函数

// 这里是指针要自己释放才可以的
    // listnode_cpp* p = new listnode_cpp[10];
    // delete[] p;




// 静态函数突破类域就行
    // b a[5];
    // a[0].print_n();    // 可以
    // b::print_nn();     // 推荐方式




// -------------------------------
// operator new
// operator delete

    // c* p1 =(c*) malloc(sizeof(c*));
    // c* p2 = new c;
    // c* p3 = (c*)operator new(sizeof(sizeof(c))); // 在堆上分配内存（raw memory allocation），并返回这块内存的指针

// malloc和operator new区别

// malloc失败返回0
// operator new失败抛出异常
// 使用方式都是一样的，处理错误的方式不一样的



// malloc/free
// operator new / operator delete
// new /delete
    

// malloc和operator new基本上一样的

// operator new = malloc + 失败抛异常实现
// new          = operator new + 构造函数

// new比malloc不一样的地方：1构造函数初始化2失败了抛出异常
// new = malloc + 抛出异常 + 构造函数

// delete比free不一样的地方：1.调析构函数清理2.
// operator delete == free,一样的，因为释放空间失败都是，直接终止进程



// 一个类定制operator new
// 一个类定制operator delete



// 定位new
// place new
    
    // d* p1 = new d(10);
    // delete p1;

// 模拟上面的行为
    // d* p2 = (d*)operator new(sizeof(d));

// 对已经存在的空间调用构造函数初始化
// 定位new/ placement new
    // new(p2)d(10);
    
    // p2->~d();
    // operator delete(p2);

// malloc和new的区别？
// new == malloc + 抛出异常 + 构造函数
// malloc失败返回零
//
// new是一个操作符 malloc是一个函数
//
// void* malloc(字节数)
// 类型对应的指针 new 类型


// c++独有的问题：内存泄露。
    
    // char* pc = new char[1024 * 1024 * 1024];


    // 忘记释放了

// valgrind
//
//
// 1G = 1024 MB
// 1MB = 1024 KB
// 1KB = 1024 B
// 所以：
// 1G = 1024 × 1024 × 1024 = 1,073,741,824 B




// 模版-------------------------------------
    // int a = 10;
    // int b = 20;

    // Swap(a, b);
    // cout<< a <<endl;
    // cout<< b <<endl;

    // char ch1 = 'x';
    // char ch2 = 't';

    // Swap(ch1, ch2);
    // cout<< ch1 <<endl;
    // cout<< ch2 <<endl;

    // float f1 = 1.2f;
    // float f2 = 1.3f;
    
    // Swap(f1, f2);

    // cout<< f1 <<endl;
    // cout<< f2 <<endl;
// 这几个函数不是同一个函数
// 推演参数类型
// 生成实例化模版

// 函数模版
// 类模版


    
























    return 0;
}

