#include<iostream>
#include<string>
using namespace std;

void test1()
{
    string s1("hello");
    s1 += ' ';
    s1 += " world";
    cout<< s1 <<endl;
    s1.push_back('T');
    s1.append("xxxxxxxx");
    cout<< s1 <<endl;
}

void test2()
{
    string s1("hello world");

// 下标访问数据
    for(size_t i = 0; i < s1.size(); i++)
    {
        cout<< s1[i] <<endl;
    }
    cout<< "size" <<endl;

// 迭代器访问数据
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        cout<< *it <<endl;
        it++;
    }
    cout<< "iterator"<<endl;


// 访问for遍历数据
    it = s1.begin();
    for(auto e : s1) // 范围for
    {
        cout<< e <<endl;
    }
    cout<< "for" <<endl;
}


void test3()
{
    string s = "hello world";

    // 获取字符串的首地址
    const char* str = s.c_str();
    while (*str)
    {
        cout<< *str <<endl;
        ++str;
    }

    cout<< s <<endl;           // string重载opetator<<
    cout<< s.c_str() <<endl;  // 输出const char*

    s += '\0';
    s += "world";

    cout<< s <<endl; // string重载opetator<<
    cout<< s.c_str() <<endl; // 输出const char*

    char str1[] = "中国";
    cout<< str1 <<endl;

    
}

void test4()
{

    string s1("string.cpp");
    string s2("string.c");
    string s3("string.txt");
    size_t pos1 = s1.find('.');
    cout<< pos1 <<endl;
    if(pos1 != string::npos)
    {
        cout<< s1.substr(pos1) <<endl;
    }
}

void test5()
{

// find开始+字符串长度
    string url("https://subingwen.cn/data-structure/sort/#5-%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F");
    string ur2("https://grok.com/chat/c9e591f9-8ace-4214-9dd7-cfecdcb82e82");
    size_t i1 = url.find(':');

    // 可以使用引用作为，就可以减少传递参数
    if(i1 != string::npos)
    {
        cout<< url.substr(0,i1)<<endl;
    }

    size_t i2 = url.find('/',i1 + 3);
    if(i2 != string::npos)
    {
        cout<< url.substr(i1+3,i2 -i1 -3)<<endl;
    }

    cout<< url.substr(i2+1) <<endl;
}


void test6()
{
    string s1("hello");
    string s2 = s1 + "worlf";
    string s3 = s1 += "worlf";

    string s4("awfs");
    string s5("sdff");
    cout<< (s4 < s5) <<endl;
}

void test7()
{

    string url("https://cplusplus.com/reference/iolibrary/ ");
    size_t i1 = url.find(':');
    if(i1 != string::npos)
    {
        cout<< url.substr(0,i1);
        cout<<endl;
    }

    size_t i2 = url.find('/',i1+3);
    if(i2 != string::npos)
    {
        cout<< url.substr(i1+3, i2 - i1 -3);
        cout<<endl;
    }

    cout<< url.substr(i2+1)<<endl;
}


void test8()
{
    string s1("hello");
    string ret = s1 + "world";
    string ret2 = s1 += "world";
}



void test9()
{
    string s1("abdcd");
    string s2("sadfdsf");
    cout<< (s1 < s2) <<endl;
    cout<< (s1 > s2) <<endl;
    cout<< (s1 > "he") <<endl;
}


void find_str()
{
    string s;
    getline(cin,s);
    size_t i1 = s.rfind(' ');
    cout<< s.substr(i1+1) <<endl;
}

void huiwen()
{
    string s("sadfssdf");
    for(auto& e : s)
    {
        
    }
}





class solution
{
public:

    bool isCharOrNumber(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool iso(string s)
    {
        for(auto& ch :s)
        {
            if((ch >= 'A' && ch <= 'Z'))
            {
                ch += 32;
            }
        }


        int begin = 0;
        int end = s.size() - 1;

        while(begin < end)
        {
            while (begin < end && !isCharOrNumber(s[begin]))
            {
                ++begin;
            }

            while(begin < end && !isCharOrNumber(s[end]))
            {
                --end;
            }

            if(s[begin] != s[end])
            {
                return false;
            }
            else
            {
                ++begin;
                --end;
            }

            
        }
        return true;
    }
};


class solution2
{
public:
    string stringadd(string s1,string s2)
    {
        // 每次都是三个数字相加，注意进位
        int end1= s1.size()-1;
        int end2 = s2.size()-1;
        int next = 0;
        string retstr;
        while (end1 >= 0 || end1 >= 0)
        {
            int val1 = 0;
            int val2 = 0;
            if(end1 >= 0)
                val1 = s1[end1] - '0';
            
            if(end2 >= 0)
                val2 = s2[end2] - '0';

            int ret  = val1 + val2 + next;
            if(ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            // retstr += (ret - '0');
            retstr.insert(retstr.begin(), '0' + ret);
            --end1;
            --end2;
        }

        if(next == 1)
        {
            retstr.insert(retstr.begin(), '1');
        }
        
        return retstr;
    }




};







int main()
{


// string是数组，存放字符串
    // test1();
    // test2();

// c_str字符串
    // test3();

// find
    // test4();
    // test5();

    // test6();

// getline()
    // string s("hell");
    // getline(cin,s); // geiline空格不结束，换行才结束
    // cout<< s <<endl;

    
    // test7();
    // test9();

    find_str();





    return 0;
}