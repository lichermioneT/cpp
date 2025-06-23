#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

void test()
{
// 构造函数
    string  s1; // 无参数构造函数
    string  s2("hellox world");
    string  s3("helll", 3);
    string  s4(s2);
    string  s5(s2,1,4);
    string  s6(s2,1);
    string  s7(10, 'a');
    cout<< s5 <<endl;
    s1 = s7;

    // npos是类里面的静态成员变量
    // static const size_t npos = -1;
}


void test_string2()
{
// 遍历字符串
    string s1("hello");
    s1 += ' ';
    s1 += "world";
    cout<< s1 <<endl;

// [] 重载实现
// [] + 下标访问。推荐用这个。
// 写数据
    for(size_t i = 0; i < s1.size() ; i++)
    {
        s1[i] += 1; // 字符串后面添加一个1
    }

    // 读数据
    for(size_t i = 0; i < s1.size() ; i++)
    {
        cout<< s1[i] <<endl;
    }

// 迭代器不一定是指针
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        *it -= 1;
        ++it;
    }
    
    // 注意指针的位置，消息越界
    it = s1.begin();
    while (it != s1.end())
    {
        cout<< *it<< " ";
        ++it;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator vit = v.begin();

    while (vit != v.end())
    {
        cout<< *vit <<endl;
        vit++;
    }


// 范围for 访问数据容器,原理迭代器
    for(auto ch : s1)
    {
        cout<< ch << " ";
    }
}



int string2int(const string & str)
{
    int val = 0;
    string::const_iterator it = str.begin();
    while (it != str.begin())
    {
        val *= 10;
        val += (*it - '0');
        
    }
    return val;
}

// 反向迭代器 
void test_string3()
{
    string s1("hello world");
    string::reverse_iterator rit = s1.rbegin();

    while (rit != s1.rend())
    {
        cout<< *rit <<endl;
        ++rit;
    }
    
    string nums("123");
}


void test4()
{

    string s1("hello world");
    // cout<< s1.size() <<endl;
    // cout<< s1.capacity() <<endl;
    // s1.reserve(120);
    // s1.resize(10);
    // for(int i = 0; i < 100; i++)
    // {
    //     s1.push_back('a');
    //     cout<< s1.capacity() <<endl;
    // }

    string s2("hello world");
    s2.resize(5);
    s2.resize(20,'x');
}


void test5()
{


    string s;
    s.push_back('x'); // 插入一个字符
    s.append("hello");
    s += "licherminonex";
    cout<< s <<endl;
    s.insert(s.begin(),'T');
    cout<< s <<endl;
    s.insert(2,"2");
    cout<< s <<endl;



}



int main()
{
// 看文档说明 不需要看源代码，源代码就复杂了。
// 引用作为参数可以修改和效率

    // test_string3();
    // test();
    // vector<int> v = {1,2};
    // cout<<v[1]<<endl;
    // test4();
    // test5();
  






    return 0;
}