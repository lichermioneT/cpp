#include <iostream>
#include <cstring>
#include <cassert>
using std::cout;
using std::cin;

// 如果一个类需要显式定义析构函数、拷贝构造函数或拷贝赋值运算符中的任何一个，那么通常也需要显式地定义另外两个。
// Rule of Three

class  string
{
public:
    string(const char* str = "")
        :_str(new char[strlen(str) + 1]) // 这里的strlen不会计算斜杠零的。所以多拷贝一个斜杠零
    {   
        int len = strlen(str);
        strcpy(_str, str); // 数据拷贝过去，strcpy会拷贝斜杠零的。
        _size = _capacity = len;
    }

    string(const string& s)
        : _str(new char[strlen(s._str) + 1])
        , _size(s._size)
        , _capacity(s._capacity)
    {
        strcpy(_str, s._str);
    }

    ~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    string& operator=(const string& s)
    {
        if(this != &s)
        {
            char* temp = new char[strlen(s._str) + 1];
            strcpy(temp, s._str);

            delete[] _str;

            _str = temp;
            _size = s._size;
            _capacity = s._capacity;
        }

        return *this;
    }

    size_t size() const 
    {
        return _size; 
    }

    size_t capacity() const
    { 
        return _capacity; 
    }

    void push_back(char ch)
    {
        if(_size == _capacity)
        {
            size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
            _capacity = newcapacity;
        }
        _str[_size] = ch;
        ++_size;
    }




private:
    char* _str;
    size_t _size;
    size_t _capacity;
};



int main()
{
    
    string s("lll");





}