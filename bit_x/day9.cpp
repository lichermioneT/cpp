
#include<iostream>
using namespace std;

class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};


class a{
private:
    int _a;
public:
    a(int a = 0)
        :_a(a)
    {
        cout<< " a() "<<endl;
    }

    ~a()
    {
        cout<< " ~a() "<<endl;
    }


};

class Person {
public:
    std::string name;
    int age;

    void sayHello() {
        std::cout << "Hello, I'm " << name << ", " << age << " years old.\n";
    }
};


int main()
{

    // Person* people[3];
    // people[0] = new Person{"Tom", 20};
    // people[1] = new Person{"Jerry", 22};
    // people[2] = new Person{"Spike", 25};

    // for (int i = 0; i < 3; ++i) {
    //     people[i]->sayHello();
    //     delete people[i];  // 别忘记释放
    // }

// c++中建议使用new和delete 自定义类型可以初始化调用构造函数，清理资源调用析构函数

    // auto num1 = 55;
    // auto s  = "lichermionex";


    // cout<< num1 <<endl;
    // cout<< s <<endl;


    // auto p2 = new int(10); // 分配并初始化为 10 
    // cout<< *p2 <<endl;

    MyClass* obj = new MyClass; // 调用构造函数
    delete obj; // 调用析构函数
    MyClass* obja = new MyClass[10];
    delete[] obja;



// operator new
// operator delete

//  operator new和malloc的区别，用法一样但是处理错误的方式不一样。
    // void* operator new(size_t size); 语法

    // a* a1 = (a*)malloc(sizeof(a)); // malloc申请失败指针返回的是null == 0
    // a* a2 = (a*)operator new(sizeof(a)); // operator new申请失败会抛出异常，面向对会抛出异常处理程序。
    // cout<< a1 <<endl;
    // cout<< a2 <<endl;

// malloc     /free
// operator new  == malloc + 失败加抛出异常
// new == operator new + 构造函数
// new 比malloc多1 调用构造函数 2失败抛出异常

// delete比free不一样的地方1调用析构函数
// operator free和free没有区别，因为释放失败进程终止。


// 定位new
    // auto a3 = new a;
    // delete a3;

    // // 定位new 显示调用类里面的构造函数和析构函数
    // auto a4 = (a*)operator new(sizeof(a)); // 开辟空间
    // new(a4)a(10); // 调用构造函数

    // a4->~a();
    // operator delete(a4);

    // return 0;
}



/*

#include<iostream>
using namespace std;

class date
{
private:
    int _a;
public:
    date(int a)
    :_a(a)
    {
        cout<< " date()" <<endl;
    }

    ~date()
    {
        cout<< "~ date()" <<endl;
    }
};



int main()
{

// malloc和new的区别
// operator new == malloc + 抛出依次
// new == operator new + 调用构造函数。

// malloc是一个函数，new是一个操作符
// malloc传参数是字节数 返回值 void*  new后面跟申请对象的类型，返回指针



// c++独有的问题，内存泄漏。
    // 申请的空间忘了释放，别人想用用不上。

    auto p = new int(66);
    cout<< *p <<endl;
    delete p;

    auto p2 = new string("lic");
    cout<< *p2 <<endl;
    delete p2;


    auto p3 = new date(10);
    // p3->~date();
    delete p3;

    int num1 = 0;
    int num2 = 66;

    swap(num1, num2)


    return 0;
}

*/

/*

#include <iostream>

// 定义模板函数
template<class T>
void swap(T& T1, T& T2) {
    T temp = T1;
    T1 = T2;
    T2 = temp;
}

template<class T>
class date
{
    
};


int main() {
    int num1 = 0, num2 = 66;
    std::cout << "Before swap: " << num1 << ", " << num2 << std::endl;
    swap(num1, num2);
    std::cout << "After swap: " << num1 << ", " << num2 << std::endl;

    char ch1 = 's';
    char ch2 = 't';
    std::cout << "Before swap: " << ch1 << ", " << ch2 << std::endl;
    swap(ch1, ch2);
    std::cout << "After swap: " << ch1 << ", " << ch2 << std::endl;

    // 通过模版生成两个函数 发生在预处理阶段，编译阶段就是检查语法了。编译前生成了。
    // 模版原理该生成的函数一个没有少。我们写了模版或者类编译前通过模版生成。
    // 函数模版只有在实例化的时候才会检查语法。
    return 0;
}

*/

/*
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T* elements;
    int topIndex;

public:
    Stack() {
        elements = new T[MAX_SIZE];
        topIndex = -1;
    }

    ~Stack() {
        delete[] elements;
    }

    void push(const T& item) {
        if (topIndex >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }
        elements[++topIndex] = item;
    }

    T pop() {
        if (topIndex < 0) {
            throw std::underflow_error("Stack underflow");
        }
        return elements[topIndex--];
    }

    T top() const {
        if (topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return elements[topIndex];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    std::cout << "C++ Stack Top: " << stack.top() << std::endl;
    std::cout << "C++ Stack Pop: " << stack.pop() << std::endl;
    std::cout << "C++ Stack Size: " << stack.size() << std::endl;
    return 0;
}

*/