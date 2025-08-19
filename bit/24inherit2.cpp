#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(const char* name = "peter")
        : _name(name)
    {
        cout << "Person()" << endl;
    }

    Person(const Person& p)
        : _name(p._name)
    {
        cout << "Person(const Person& p)" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;
        return *this;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }

protected:
    string _name; // 姓名
};

class Student : public Person
{
public:
    Student(const char* name, int num)
        : Person(name) // 调用基类的构造函数初始化，先初始化基类
        , _num(num)
    {
        cout << "Student()" << endl;
    }

// 拷贝够函数，必须传引用
    Student(const Student& s)
        : Person(s)      // 这里是切片，天然支持的
        , _num(s._num)   // 
    {
        cout << "Student(const Student& s)" << endl;
    }

    Student& operator=(const Student& s)
    {
        cout << "Student& operator= (const Student& s)" << endl;
        if (this != &s)
        {
            Person::operator=(s); // 调用父类的赋值构造，切片行为。 显示调用父类的函数，同名函数会出现隐藏的。
            _num = s._num;
        }
        return *this;
    }

    ~Student()  // 子类的析构函数和父类的析构函数构成隐藏，因为它们的名字会被编译器统一处理成 destructor
    {
        // Person::~Person()  // 正确的用法不需要你显示调用，结束后自动调用。
        cout << "~Student()" << endl;
    }

protected:
    int _num; // 学号
};

void Test()
{
    Student s1("jack", 18);
    Student s2(s1);
    Student s3("rose", 17);
    s1 = s3;
}



class A 
{
public:
    void func() { std::cout << "A::func()\n"; }
public:
    int a;
};

class B : public A {public: int _b;}; // 使用虚继承
class C : public A {public: int _c;}; // 使用虚继承
class D : public B, public C {public: int _d;}; // 菱形继承

//   A
// B   C
//   D
// 

//           A
// virtual B  virtual C
//           D




int main()
{
    // Student s1("jack", 88);
    
// 派生类初始化
// 1.基类：是调用自己的构造，析构函数
// 2.派生类：调用自己的构造，析构函数
// 基类只能基类自己初始化


// 默认构造函数：编译器生成，全缺省，无参数的。
// 默认构造函数必须存在一个。


    // 拷贝构造呢
    // 父类调用父类的构造函数
    // 
    // Student s2(s1);

    // Student s3("rose", 17);
    // s1 = s3;

// 析构也是自己调用自己的
// 析构函数是自动调用的，不需要子类指定调用

// 结束的时候会自动调用父类的析构函数，因为这样子才能够先保证先析构子类，在析构父类。
// 先析构子类，在析构父类

// 显示调用：默认构造，拷贝构造，赋值构造。
// 不显示调用：析构函数

// 友元和继承

// 如何涉及一个不能被继承的类
// 构造私有、析构私有
// 无论你怎么继承，都无法初始化


// 友元关系不能被继承下来
// 静态成员继承下来只有一份
// 谁改变了，其它的都相应的改变了

// 静态成员图片类域就可以访问


// 多继承：是一个原理罪。是一个大坑
// 菱形继承：菱形继承，二义性和歧义。数据冗余了已经，虽然可以指定类域访问。

// virtual 关键字登场

    // D d;
    // d.func(); // 正确调用 A::func()，无二义性
// 是如何解决的呢

// c++的缺陷有哪些呢？
//  多继承-->菱形继承-->虚继承-->底层结构的对象模型复杂。切效率有损失的。

// 对象模型


    




    return 0;
}
