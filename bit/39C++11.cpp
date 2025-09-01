#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <initializer_list>


using namespace std;

class point
{
public:
	point(int x, int y)
	:_x(x)
	,_y(y)
	{}
private:
	int _x;
	int _y;
};

class A
{
public:
	A() = default; // 指定显示生成默认构造函数，必须存在一个默认的构造函数
	A(const int& a)
		:_a(a)
	{}

private:
	int _a;
};

// 防止拷贝复制
class B
{
public:
	B(const int& a)
		:_a(a)
	{}
	// 删除复制和拷贝构造函数
	B(const B& b) = delete;
	B& operator=(const B& b) = delete;
private:
	int _a;
};

template<class T>
void f(const T& a)
{
	cout << " void f(const T& a) " << endl;
}

template<class T>
void f(const T&& a)
{
	cout << " void f(const T&& a) " << endl;
}



class String
{
public:
	String(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	~String()
	{
		delete[] _str;
	}

	String(const String& s)
	{
		cout << " String(const String& s)---深拷贝 " << endl;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	String(String&& s)
		:_str(nullptr)
	{	
		cout << " String(String&& s)--- 移动拷贝" << endl;
		swap(_str, s._str);
	}
private:
	char* _str;
};


String f3(const char* str)
{
	String temp(str);
	return temp;
}

int main()
{
// 初始化列表
	//int x1 = { 22 };
	//cout << x1 << endl;
	//
	//int x2{ 10 };
	//cout << x2 << endl;

// 初始化可以使用{} 或者={}，两者等价
	vector<int> vec1{ 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 1, 2, 3, 4, 5 };

	list<int> lst1{ 1, 2, 3, 4, 5 };
	list<int> lst2 = { 1, 2, 3, 4, 5 };

	map<string, int> map1{ {"one", 1}, {"two", 2}, {"three", 3} };
	map<string, int> map2 = { {"one", 1}, {"two", 2}, {"three", 3} };


	point pt1{ 1, 2 };
	point pt2 = { 1, 2 };
	point pt3(1, 2);

	// 初始化列表 
	auto i1 = { 1, 2, 3, 4, 5 };
	initializer_list<int> i2 = { 1, 2, 3, 4, 5 };
// 容器支持花括号初始化本质上，是因为容器类都提供了一个构造函数，


// 类型推导
// RTTI= run time type identification 运行时类型识别
	
	//int a = 10;
	//double b = 20;
	//auto c = a + b;
	//cout << typeid(c).name() << endl;

	//string s;
	//cout << typeid(s).name() << endl;

	//decltype(c) d;
	//decltype(s) e;
	//cout << typeid(d).name() << endl;
	//cout << typeid(e).name() << endl;



// auto和范围for
// auto不能做函数形式参数和返回值的，它完全不知道数据的类型。

	std::map<std::string, std::string> dict{ {"inset", "插入"}, {"sort", "排序"}};
	std::map<std::string, std::string>::iterator it1 = dict.begin(); // 手动声明类型
	auto it2 = dict.begin(); // 编译器自动推导的

	// 容器中数据比较大时，或者这个对象要做深拷贝
	// 最好使用&和const，提高效率
	//for (const auto& e : dict)
	//{
	//	cout << e.first << " : " << e.second << endl;
	//}

	//for (const pair<const std::string, std::string>& e : dict)
	//{
	//	cout << e.first << " : " << e.second << endl;
	//}


// 出了STL的容器可以使用范围for，数组也可以使用范围for。原生指针可以认为是天然的迭代器。
	//int a[] = { 1,2,3,4,5,6,7,8,9,77 };
	//for (auto& e : a)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;


// final/override
// final关键字不允许被继承了
// override关键字检查虚函数被重写了没。

// final修饰类，类变成最终类 ，不能被重写
// final修饰虚函数，虚函数不能被重写
// override检查虚函数重写



// 新容器
// array/forword_list/unordered
// c++98
// string/vector/list/dequeue/map/set/bitset--stack/queue/priority_queue
// c++11
// array(定长数据，定长，数据存储在栈区)/forword_list(单链表：实际中少)/unordered(哈希）unordered set, unordered map;

	//A a(2);
	//A aa(a);

// 右值引用

// 不管是右值，左值引用都是给对象取别名的。
	// c++98提出了，引用就是已经存在的对象取别名
	// c++11左值引用 

	// 左值引用
	//int a = 0;
	//int& b = a;
	//const int& e = 22;

	// 右值引用
	//int x = 1;
	//int y = 2;

	//int&& c = 10;
	//int&& d = x + y;
	//int&& f = move(x);

// 什么是左值？可以修改的就是左值，基本上就是一些变量。
// 什么是右值？常量，表达式，函数返回值等临时对象。

	//int a = 1;
	//int b = a;
	//int& c = a;
	//int&& d = 1;

	int x = 10;
	// 下面能区分右值和左值
	//f(x);
	//f(10);

// c++11
// 纯右值：基本类型的常量或者临时对象
// 将亡值：自定义类型的临时对象


	String s1("hello wordl");
	String s2(s1);

	String s3(f3("fdasf"));











	return 0;
}