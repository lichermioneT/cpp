#include <iostream>

using namespace std;

class Base
{
public:
    int _a = 1;
protected:
    int _b = 2;
private:
    int _c = 3;
};

class Drive1 : public Base
{
    // 可以访问 _a,_b;
    // 同样的_a，类外面可以访问的
    // _a还是public;
    // _b还是protected;
public:
    void test()
    {
        cout<< _a <<endl;
        cout<< _b <<endl;
    }
};

class Drive2 : protected Base
{
    // 可以访问 _a,_b;
    // 类外面不可以访问的_a;
    // _a还是protected;
    // _b还是protected;
public:
    void test()
    {
        cout<< _a <<endl;
        cout<< _b <<endl;
    }
};

class Drive3 : private Base
{
    // 可以访问 _a,_b;
    // _a是private
    // _b是private
public:
    void test()
    {
        cout<< _a <<endl;
        cout<< _b <<endl;
    }
};

void test()
{
    Drive1 d1;
    d1.test();
    cout<< d1._a <<endl;

    Drive2 d2;
    d2.test();

    Drive3 d3;
    d3.test();
}



class Person
{
public:
    Person(const char* name, const char* sex, int age)
        :_name(name)
        ,_sex(sex)
        ,_age(age)
    {
    }

    void print()
    {
        cout<< _name <<endl;
        cout<< _sex <<endl;
        cout<< _age <<endl;
    }

protected:
    string _name;
    string _sex;
    int _age;
};

class Student : public Person
{
public:
    Student(const char* name, const char* sex, int age, int id)
        :Person(name, sex, age)
        ,_id(88)
    {
    }
public:
    int _id;
};



void test2()
{
    Student s("lic", "mam", 25, 211);
    Person p("fmy","female", 24);

// 三种切片行为
    // p = s;
    // p.print();

    // Person& ref = s;
    // ref.print();

    // Person* p1 = &s;
    // p1->print();

}


class  A
{
public:
    void func(double d  = 7.8)
    {
        cout<< d <<endl;
    }

    void func(char ch = 'w')
    {
        cout<< ch <<endl;
    }

    void func(int x = 77)
    {
        cout<< "func" <<endl;
    }

protected:
    string _name = "lic";
    int _num = 11;
};

class B : public A
{

public:
    void print()
    {
        cout<< _num <<endl;
    }


    void func()
    {   A::func(77);
        cout<< "func() " <<endl;
    }


protected:
    int _num = 99;
};

void test4()
{
       B b;
    b.func();
}

namespace lic
{

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
        : Person(name)
        , _num(num)
    {
        cout << "Student()" << endl;
    }

    Student(const Student& s)
        : Person(s)  // 调用基类拷贝构造
        , _num(s._num)
    {
        cout << "Student(const Student& s)" << endl;
    }

    Student& operator=(const Student& s)
    {
        cout << "Student& operator=(const Student& s)" << endl;
        if (this != &s)
        {
            Person::operator=(s); // 先赋值基类部分
            _num = s._num;        // 再赋值派生类部分
        }
        return *this;
    }

    ~Student()
    {
        cout << "~Student()" << endl;
    }

protected:
    int _num; // 学号
};

}

class D
{

public:
    static int x;

    void  count()
    {
        ++x;
    }

    void print()
    {
        cout<< x <<endl;
    }
};

int D::x = 0;

class Drived1 : public D
{
public:
    Drived1()
    {
        ++x;
    }
};

class Drived2 : public D
{
public:
    Drived2()
    {
        ++x;
    }
};

void test6()
{
    Drived1 a[10];
    Drived2 b[10];

    D d;
    d.print();
}



class F
{
public:
    string _name;
};

class F1 : public F
{

};

class F2 : public F
{

};

class F3 : public F1, public F2
{

};

void test7()
{
    // F3 f;
    // // f._name = "lic" // 谁的_name??

    // f.F1::_name = "XXXX";
    // f.F2::_name = "zzzz";
    ;
}

class H
{
public:
    int _a;    
};

class H1 : public H
{
public:
    int _b;
};

class H2 : public H
{
public:
    int _c;
};

class H3 : public H1, public H2
{
public:
    int _d;
};


class H4 : public H2, public H1
{
public:
    int _e;
};

void test9()
{
    H3 h;
    h.H1::_a = 1;
    h.H2::_a = 2;

    h._b = 3;
    h._c = 4;
    h._d = 5;

    cout<< *(int*)&h <<endl; // 1
    cout<< *((int*)&h + 1) <<endl; // 3

    cout<< *((int*)&h + 2) <<endl; // 2
    cout<< *((int*)&h + 3) <<endl; // 4
 
    cout<< *((int*)&h + 4) <<endl; // 4


    H4 h2;
    h2.H1::_a = 1;
    h2.H2::_a = 2;

    h2._b = 3;
    h2._c = 4;
    h2._e = 5;

    cout<< *(int*)&h2 <<endl; // 2
    cout<< *((int*)&h2 + 1) <<endl; // 4
    cout<< *((int*)&h2 + 2) <<endl; // 1
    cout<< *((int*)&h2 + 3) <<endl; // 1
    cout<< *((int*)&h2 + 4) <<endl; // 3
}


class Z
{
public:
    int _a;
};

class Z1 : virtual public Z
{
public:
    int _b;
};

class Z2 : virtual public Z
{
public:
    int _c;
};

class Z3 : public Z1, public Z2
{
public:
    int _d;
};



int main()
{
 
    Z3 z;
    z.Z1::_a = 1;
    z.Z2::_a = 2;

    z._b = 3;
    z._c = 4;
    z._d = 5;
    // z1
    // z2
    // z
    // 

    // cout<< &z <<endl;
    // cout<< *(int*)&z <<endl;
    // cout<< *((int*)&z + 1) <<endl; // 
    // cout<< *((int*)&z + 2) <<endl; // 
    // cout<< *((int*)&z + 3) <<endl; // 
    // cout<< *((int*)&z + 4) <<endl; // 
    

    // 打印对象首地址
    cout << "z对象首地址: " << &z << endl;

    // 打印每个成员变量的地址和值
    cout << "&z.Z::_a = " << &z.Z::_a << " , value = " << z.Z::_a << endl;
    cout << "&z._b     = " << &z._b     << " , value = " << z._b << endl;
    cout << "&z._c     = " << &z._c     << " , value = " << z._c << endl;
    cout << "&z._d     = " << &z._d     << " , value = " << z._d << endl;

    // 直接用强转指针方式查看内存中 int 顺序
    cout << "内存视图:" << endl;
    int* p = (int*)&z;
    for (int i = 0; i < 6; i++)
    {
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    }












    return 0;
}