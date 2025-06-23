#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

// 迭代器访问数据
void test1()
{

// 
    string s("lichermionex");
// 迭代器遍历数据
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout<< *it;
        it++;
    }
    cout<<endl;

    string::reverse_iterator rit = s.rbegin();
    while (rit != s.rend())
    {
        cout<< *rit;
        rit++;
    }
    cout<<endl;

    string::const_iterator cit  = s.cbegin();
    while (cit != s.cend())
    {
        cout<< *cit;
        cit++;
    }
    cout<<endl;
    

    string::const_reverse_iterator crit = s.crbegin();
    while (crit != s.crend())
    {
        cout<< *crit;
        crit++;
    }
    cout<<endl;
    
// size迭代数据
    string s1("hello world");
    for(size_t i = 0; i < s1.size(); i++)
    {
        s1[i] +=  1;
    }

    for(size_t i = 0; i < s1.size(); ++i)
    {
        cout<< s1[i];
    }
    cout<<endl;


    vector<int> vec = {1,2,3,4,5,6};
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout<< vec[i]<< " ";
    }
    cout<<endl;



// 范围for
    vector<int> vec2 = {1, 2, 3, 4, 5};
    for (int num : vec2) 
    {
        cout << num << " ";
    }
    cout<<endl;

    for(char e : s1)
    {
        cout<< e <<endl;
    }



}

int stringtonum(const string& str)
{
    int val = 0;
    string::const_iterator cit = str.cbegin();
    while (cit != str.cend())
    {
        val *= 10;
        val += (*cit - '0');
        ++cit;
    }
    return val;

}


void test2()
{

    string s1("hello wordl");
    cout<< s1.size() <<endl; // 推荐使用size
    cout<< s1.length() <<endl;


    cout<< s1.capacity() <<endl; // 数据增容1.5倍增加

    s1 += "123546789";
    cout<< s1.capacity() <<endl;

    s1.clear();
    cout<< s1 <<endl;
    cout<< s1.capacity() <<endl;

// insert
// erase










}









int main()
{

// 任何一个类就是四个默认成员函数
    // string s1;
    // string s2("hello");
    // string s3(s2);
    // string s4 = s3;
    // const char* c1 = "licherimione";
    // string s5(c1,5);
    // cout<< s5 <<endl;
    // string s6(s2,1,3);

// static const size_t npos = -1;
// ending postion

// 迭代器，正向迭代器，反向迭代器，常量迭代器。迭代器可以auto关键字替代
// 迭代器很像指针

    // test1();


    // 它的类型是vector<int>
    // vector<int> v;

// 
    // string s1("123466");
    // cout<< stringtonum(s1) <<endl;

// 
    test2();









return 0;
}