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


namespace lic3
{   
    using std::endl;
    using std::cout;
    using std::cin;
    using std::ostream;
class string
{
public:
    typedef char* iterator;
    
    iterator begin()
    {
        return _str;
    }
        
    iterator end()
    {
        return _str + _size;
    }
    string(const char* str = "")
    {
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
        _size = _capacity = strlen(str);
    }
    
    ~string()
    {
        delete[] _str;
        _size = _capacity = 0;
    }
    
    // 拷贝构造
    // 赋值构造

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }
    
    char& operator[](size_t i)
    {
        assert(i < _size);
        return _str[i];
    }
    
    const char& operator[](size_t i) const
    {
        assert(i < _size);
        return _str[i];
    }

    
    const char* c_str()
    {
        return _str;
    }

    // ostream& operator<<(ostream& out, const string& s)
    // {
    //     for(size_t i = 0; i < s.size(); i++)
    //     {
    //         cout<< s[i];
    //     }

    //     return out;
    // }
        
    // 输入

    void push_back(char ch)
    {
        if(_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
            char* tmp = new char[newcapacity + 1];
            strcpy(tmp, _str);
            delete[]  _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0'; // 最后一个位置你得存放斜杠零
    }
    
    void append(const char* str)
    {
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            size_t newcapacity = _size + len;
            char* newstr = new char[newcapacity + 1];
            strcpy(newstr, _str);
            delete[] _str;
            _str = newstr;
            _capacity = newcapacity;
        }

        strcpy(_str+_size, str);
        _size = _size + len;
    }

    void reserve(int n)
    {
        if(n > _capacity)
        {
            char* newstr = new char[n + 1];
            strcpy(newstr, _str);
            delete[] _str;
            _str = newstr;
            _capacity = n;
        }
    }
    
    string& operator+=(char ch)
    {
        this->push_back(ch);
        return *this;
    }

    string& operator+=(const char* str)
    {
        this->append(str);
        return *this;
    }


    void resize(size_t n, char ch)
    {
        

    }

    string& insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        // 判断容量
        if(_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
            reserve(newcapacity);
        }

        // 判断位置
        int end = _size;  // 从_size的位置开始移动
        while(end >= pos) // 指定位置的那个字符也要移走
        {
            _str[end + 1] = _str[end]; // 从斜杠零开始移动
            end--;
        }
        _str[pos] = ch;
        ++_size;
        return *this;
    }

    string& insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        int len = strlen(str);
            // 判断容量
         if(_size + len > _capacity)
         {
             reserve(_size + len );
         }
        
         int end = _size;
         while(end >= pos)
         {
            _str[end + len] = _str[end];
            end--;
         }

         for(int i = 0; i < len; ++i)
         {
             _str[pos + i] = str[i];
         }

         // strncpy(_str + pos, str, len);

         _size += len;
         _str[_size] = '\0'; // 一定要补上  
        return *this;
    }
    // void erase(size_t pos, size_t len = npos);
    // size_t find(char ch, size_t pos = 0);
    // size_t find(const char* str, size_t pos = 0);
    // bool operator<(const string& s);
    // bool operator>(const string& s);
    // bool operator<=(const string& s);
    // bool operator>=(const string& s);
    // bool operator==(const string& s);
    // bool operator!=(const string& s);
    
    


private:
    char* _str; // 指针
    size_t _size; // 有效数据个数
    size_t _capacity; // 容量，容量里面不计算斜杠零，每次都是要多开一个数据的。
    static size_t npos;
};

    size_t string::npos = -1;

    ostream& operator<<(ostream& out, const string& s)
    {
        for(size_t i = 0; i < s.size(); i++)
        {
            out<< s[i];
        }

        return out;
    }
    
void test()
{
    string s1;
    string s2("lic");
    cout<< s1 <<endl;
    cout<< s2 <<endl;

    for(size_t i = 0; i < s2.size(); i++)
    {
        s2[i] += 1;
        cout<< s2[i] << " ";
    }
    cout<<endl;

    string::iterator it = s2.begin();
    while(it != s2.end())
    {
        *it -= 1;
        cout<< *it << " ";
        it++;
    }

    cout<<endl;

// 范围for最终会被编译器替换成迭代器
// iterator begin() end()  有这三个东西才行的
    for(auto e : s2)
    {
        cout<< e << " ";
    }
    cout<<endl;

    s2.push_back('x');
    s2.push_back('x');
    s2.push_back('x');
    s2.push_back('x');
    s2.push_back('x');
    s2.push_back('x');
    s2.push_back('x');
    
    s2.append("lic");
    cout<< s2 <<endl;
    s2.append("fadssssss");
    s2 += "licda";
    s2 += 'c';
    
    cout<< s2 <<endl;

    s2.insert(3, 'o');
    cout<< s2 <<endl;


    s2.insert(0,"ddddd");
    cout<< s2 <<endl;
}

    
void test3()
{
    // string s("hello");
    // s.insert(5, ',');
    // s.insert(6, " world");

    // std::cout << s << std::endl;

    // s.erase(5, 7);
    // std::cout << s << std::endl;

    // size_t pos = s.find('l');
    // std::cout << "first l: " << pos << std::endl;

    // std::cout << (s == string("hello")) << std::endl;
}


}


int main()
{

    // test();
    lic3::test();
    // lic3::test3();
}

