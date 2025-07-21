#include <iostream>
#include <cstring>
#include <cassert>
namespace lic
{
class string
{
public:
    string()
        : _str(new char[1])
    {
        _str[0] = '\0';
    }

    string(const char* str)
    {   
        // 开辟一块新空间
        // strlen会计算到\0,不计算\0
        _str = new char[strlen(str) + 1];

        // 数据拷贝过去
        strcpy(_str, str); // str(目标地址，源地址) 这里会拷贝\0的
    }
        
    string(const string& that)
    {
        // 深拷贝
        if (that._str) 
        {
            _str = new char[strlen(that._str) + 1];
            strcpy(_str, that._str);
        }   
        else 
        {
            _str = new char[1];
            _str[0] = '\0';
         }
    }


    string& operator=(const string& that)
    {
        // 1. 自赋值检查
        if (this == &that)
            return *this;

        // 2. 释放原内存
        delete[] _str;

        // 3. 分配新内存并拷贝
        if (that._str) 
        {
            _str = new char[strlen(that._str) + 1];
            strcpy(_str, that._str);
         } 
        else 
        {
            _str = new char[1];
            _str[0] = '\0';
        }

        return *this;
    }

    char& operator[](size_t i)
    {
        return _str[i];
    }
    
    size_t size()
    {
        return strlen(_str);
    }

    string& operator+=(const char* str)
    {
         if (str == nullptr)
            return *this;

        size_t oldLen = strlen(_str);
        size_t addLen = strlen(str);
    
         // 分配新空间：原来的长度 + 新加的长度 + 1（结尾 \0）
         char* newStr = new char[oldLen + addLen + 1];

         // 拷贝原来的字符串
         strcpy(newStr, _str);

         // 追加新字符串
         strcat(newStr, str);

        // 释放旧内存
        delete[] _str;

        // 更新 _str
        _str = newStr;

        return *this;
    }

    void print() const
    {
        std::cout << _str << std::endl;
    }

private:
    char* _str;
};
}

void test()
{
    using namespace lic;
    string s1;
    string s2("lichermionex"); // 这里的lichermionex是字符串常量，不能进行修改的
                               // 字符串字面量

    for(int i = 0; i < s2.size(); i++)
    {
        std::cout<< s2[i] <<std::endl;
    }
    
    std::cout<<std::endl;

    for(int i = 0; i < s2.size(); i++)
    {
        s2[i] += 1;
        std::cout<< s2[i] <<std::endl;
    }

    string s3(s2);
    
    std::cout<< " s3 " <<std::endl;
    for(int i = 0; i < s3.size(); i++)
    {   
        std::cout<< s3[i] <<std::endl;
    }

}

namespace lic2
{

// string对象中存储指针，指针指向的数组存放字符，字符保留\0
class string
{
public:
    string()
        :_str(new char[1])
    {
        _str[0] = '\0';
    }
    
    string(const char* str)
        :_str(new char[strlen(str) + 1]) // 尽量使用new开辟空间了
    {
        strcpy(_str, str);
    }

    //推荐全缺省的构造函数
    //string(const char* str = "")
    //  :_str(new char[strlen(str) + 1])
    //  {
    //      strcpy(_str, str);
    //  }

    ~string()
    {
        delete[] _str;
        _str = nullptr;
    }

    size_t size()
    {
        return strlen(_str);
    }

    char& operator[](size_t i)
    {
        return _str[i];
    }

    string(const string& that)
        :_str(new char[strlen(that._str) + 1])
    {
        strcpy(_str,that._str);
    }

    
string& operator=(const string& that)
{
    // if (this == &that)  // 自赋值检查
        // return *this;

    // delete[] _str;  // 释放旧内存

    // _str = new char[strlen(that._str) + 1];
    // strcpy(_str, that._str);
    // return *this;

    if(this == &that)
        return *this;

    delete[] _str;
    
    _str = new char(strlen(that._str) + 1);
    strcpy(_str, that._str);
    return *this;
}


private:
   char* _str;
};




}


int main()
{

    test();


}

