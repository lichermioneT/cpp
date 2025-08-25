#include <iostream>
using namespace std;


class A
{

};

class B : public A
{

};

class person
{
public:
    virtual void BuyTicket()
    {
        cout<< "成人：全价" <<endl;
    }

    virtual A* Func1()
    {   
        cout<< " A* " <<endl;
        return  nullptr;
    }
};

class student : public person
{
public:
    virtual void BuyTicket()
    {
        cout<< "学生：半价" <<endl;
    }

    virtual B* Func1()
    {   
        cout<< " B* " <<endl;
        return nullptr;
    }

};

void Func1(person& p)
{
    p.BuyTicket();
}

void Func1(person* p)
{
    p->BuyTicket();
}

void test1()
{
    person p;
    student s;

    Func1(p);
    Func1(s);

    Func1(&p);
    Func1(&s);
}

void Func2(person& p)
{
    p.Func1();
}

void Func2(person* p)
{
    p->Func1();
}

void test2()
{
    person p;
    student s;
    Func2(p);
    Func2(s);

    Func2(&p);
    Func2(&s);

}


class C
{
public:
    virtual ~C()
    {
        cout<< "~C" <<endl;
    }
};

class D: public C
{
public:
    virtual ~D()
    {
        cout<<"~D" <<endl;
    }
};

void test3()
{
    C* p1 = new C;
    C* p2 = new D;

    delete p1; // 调C的析构函数

    delete p2; // 调C/D的析构函数
}


class Car
{
public:
    virtual void Drive() final { cout<< "final" <<endl;}
};

class Benz : public Car
{
public:
    int x = 100;
    // virtual void Drive() {cout<< "舒服" <<endl;} // 无法通过编译的
};

void test4()
{
    Car tesla;
    tesla.Drive();
}


class E
{
public:
    virtual void Drive() 
    {
        cout<< "Drive()"  <<endl;
    }
};

class F : public E
{
public:
    virtual void Drive() override
    {
        cout<< "Drive()"  <<endl;
    }
};

void test5()
{
    F f;
    f.Drive();
}

class Tesla
{
public:
    virtual void Drive() = 0;
};

class Modely : public Tesla
{
public:
    virtual void Drive()
    {
        cout<< "我是modely" <<endl;
    }
};

class Modelx : public Tesla
{
public:
    virtual void Drive()
    {
        cout<< "我是modelx" <<endl;
    }
};

class Model3 : public Tesla
{
public:
    virtual void Drive()
    {
        cout<< "我是model3" <<endl;
    }
};

class Models : public Tesla
{
public:
    virtual void Drive()
    {
        cout<< "我是models" <<endl;
    }
};


void test6()
{
    Model3 m3;
    Modely my;
    Models ms;
    Modelx mx;

    m3.Drive();
    my.Drive();
    ms.Drive();
    mx.Drive();
}


class G
{
public:
    virtual void Func1()
    {
        cout<< "Func1()" <<endl;
    }

    virtual void Func2(int x)
    {
        cout<<  "Func2(int x)" <<endl;
    }
private:
    int _a;
};


void test7()
{
    // 函数指针
typedef void(*FUNC1)(G*);
typedef void(*FUNC2)(G*, int);

    // cout<< sizeof(G) <<endl;
    
        G g;
    // 拿 vtable 地址
    void** vtable = *(void***)&g;

    // 强转取函数
    FUNC1 f1 = (FUNC1)vtable[0];
    FUNC2 f2 = (FUNC2)vtable[1];

    f1(&g);   // 输出 Func1()
    f2(&g, 10); // 输出 Func2(int)
}


class H
{
public:
    virtual void Func1() { cout << "H::Func1()" << endl; }
    virtual void Func2() { cout << "H::Func2()" << endl; }
    virtual void Func3() { cout << "H::Func3()" << endl; }
private:
    int _a = 1;
};

class L : public H
{
public:
    virtual void Func1() { cout << "L::Func1()" << endl; } // 重写
private:
    int _d = 2;
};

// 测试函数：打印对象虚函数表并调用
template<typename T>
void PrintVTable(T& obj)
{
    // 获取虚表指针
    void** vtable = *(void***)&obj;

    cout << "对象地址: " << &obj << endl;
    cout << "虚表地址: " << vtable << endl;

// 类里面的函数隐藏this指针
    typedef void(*FuncPtr)(T*);

    cout << "调用虚函数:" << endl;
    for (int i = 0; i < 3; i++)
    {
        // 强转为函数指针并调用
        FuncPtr f = (FuncPtr)vtable[i];
        f(&obj);
    }
    cout << "-------------------------" << endl;
}


void test8()
{
    H h;
    L l;

    cout << "测试 H 对象:" << endl;
    PrintVTable(h);

    cout << "测试 L 对象:" << endl;
    PrintVTable(l);
    
}

class Base1 {
public:
    virtual void func1() {cout << "Base1::func1" << endl;}
    virtual void func2() {cout << "Base1::func2" << endl;}
private:
    int b1;
};

class Base2 {
public:
    virtual void func1() {cout << "Base2::func1" << endl;}
    virtual void func2() {cout << "Base2::func2" << endl;}
private:
    int b2;
};

class Derive : public Base1, public Base2 {
public:
    virtual void func1() {cout << "Derive::func1" << endl;}
    virtual void func3() {cout << "Derive::func3" << endl;}
private:
    int d1;
};


template<typename T>
void PrintVTable2(T& obj, int countBase1 = 2, int countBase2 = 2)
{
    // 获取 Base1 vptr
    void** vtableBase1 = *(void***)&obj;

    cout << "对象地址: " << &obj << endl;
    cout << "虚表 Base1 部分地址: " << vtableBase1 << endl;

    // Base1 虚函数指针类型
    typedef void(*FuncPtrBase1)(T*);
    cout << "调用 Base1 虚表函数:" << endl;
    for (int i = 0; i < countBase1; i++)
    {
        FuncPtrBase1 f = (FuncPtrBase1)vtableBase1[i];
        f(&obj);
    }

    // 获取 Base2 vptr（Base2 子对象偏移）
    Base2* base2Ptr = (Base2*)((char*)&obj + sizeof(Base1));
    void** vtableBase2 = *(void***)base2Ptr;
    cout << "虚表 Base2 部分地址: " << vtableBase2 << endl;

    // Base2 虚函数指针类型
    typedef void(*FuncPtrBase2)(Base2*);
    cout << "调用 Base2 虚表函数:" << endl;
    for (int i = 0; i < countBase2; i++)
    {
        FuncPtrBase2 f = (FuncPtrBase2)vtableBase2[i];
        f(base2Ptr); // 传入 Base2 子对象地址
    }

    cout << "-------------------------" << endl;
}


void test8()
{
    Derive d;
    PrintVTable2(d);

    cout<< sizeof(d) <<endl; 
}
int main()
{










    return 0;
}