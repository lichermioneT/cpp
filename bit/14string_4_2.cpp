#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>  // 声明 std::swap
using std::swap;
namespace lic3
{   
    using std::endl;
    using std::cout;
    using std::cin;
    using std::ostream;
    using std::istream;

class string
{
public:
    typedef char* iterator;

    iterator begin() { return _str; }
    iterator end() { return _str + _size; }

    string(const char* str = "")
    {
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    string(const string& s)
    {
        _size = s._size;
        _capacity = s._capacity;
        _str = new char[_capacity + 1];
        strcpy(_str, s._str);
    }

    string& operator=(const string& s)
    {
        if (this != &s)
        {
            char* tmp = new char[s._capacity + 1];
            strcpy(tmp, s._str);
            delete[] _str;
            _str = tmp;
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }

    ~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

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

    const char* c_str() const { return _str; }

    void push_back(char ch)
    {
        if (_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
            reserve(newcapacity);
        }
        _str[_size++] = ch;
        _str[_size] = '\0';
    }

    void append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }

    void reserve(int n)
    {
        if (n > static_cast<int>(_capacity))
        {
            char* newstr = new char[n + 1];
            strcpy(newstr, _str);
            delete[] _str;
            _str = newstr;
            _capacity = n;
        }
    }

    void resize(size_t n, char ch = '\0')
    {
        if (n < _size)
        {
            _size = n;
        }
        else
        {
            if (n > _capacity)
                reserve(n);
            for (size_t i = _size; i < n; ++i)
                _str[i] = ch;
            _size = n;
        }
        _str[_size] = '\0';
    }

    string& operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }

    string& operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    string& insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        if (_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
            reserve(newcapacity);
        }
        for (int end = _size; end >= static_cast<int>(pos); --end)
        {
            _str[end + 1] = _str[end];
        }
        _str[pos] = ch;
        ++_size;
        _str[_size] = '\0';
        return *this;
    }

    string& insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        int len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        for (int end = _size; end >= static_cast<int>(pos); --end)
        {
            _str[end + len] = _str[end];
        }
        for (int i = 0; i < len; ++i)
        {
            _str[pos + i] = str[i];
        }
        _size += len;
        _str[_size] = '\0';
        return *this;
    }


    string& erase(size_t pos, size_t len  = npos)
    {       
            // 删除长字符串
            if(len > (_size - npos))
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else  // 还有剩余的字符串
            {
                size_t i = pos + len;
                while (i <= _size)
                {
                    _str[i - len] = _str[i];
                    ++i;
                }
                
                _size -= len;   
            }
            return *this;
    }

    size_t find(char ch, size_t pos = 0)
    {
        for(size_t i = pos; i < _size; i++)
        {
            if(_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }

    size_t find(const char* str, size_t pos = 0)
    {
        char* p = strstr(_str, str);
        if(p == nullptr)
        {
            return npos;
        }
        else
        {
            return (p - _str);
        }
    }

    bool operator<(const string& s)
    {
        int ret = strcmp(_str, s._str);
        return ret < 0;
    }

    bool operator==(const string& s)
    {
        int ret = strcmp(_str, s._str);
        return ret == 0;
    }

    bool operator<=(const string& s)
    {
       
        return *this < s || *this == s;
    }

    bool operator>(const string& s)
    {
   
        return !(*this <= s);
    }

    bool operator>=(const string& s)
    {
        return !(*this < s);
    }

    bool operator!=(const string& s)
    {
        return !(*this == s);
    }
    


private:
    char* _str;
    size_t _size;
    size_t _capacity;
    static size_t npos;
};

size_t string::npos = -1;

ostream& operator<<(ostream& out, const string& s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        out << s[i];
    }
    return out;
}

istream& operator>>(istream& in, string& s)
{
    while (1)
    {
        char ch;
        ch = in.get();
        if(ch == '\0' || ch == '\n')
        {
            break;
        }
        else
        {
            s += ch;
        }
    }
    return in;
}

void test()
{
    string s1;
    string s2("lic");
    cout << s1 << endl;
    cout << s2 << endl;

    for (size_t i = 0; i < s2.size(); i++)
    {
        s2[i] += 1;
        cout << s2[i] << " ";
    }
    cout << endl;

    for (auto& ch : s2)
    {
        ch -= 1;
        cout << ch << " ";
    }
    cout << endl;

    for (auto e : s2)
    {
        cout << e << " ";
    }
    cout << endl;

    s2.append("xxxxxxx");
    s2.append("lic");
    cout << s2 << endl;
    s2.append("fadssssss");
    s2 += "licda";
    s2 += 'c';
    cout << s2 << endl;

    s2.insert(3, 'o');
    cout << s2 << endl;

    s2.insert(0, "ddddd");
    cout << s2 << endl;

    cin>>s2;
    cout<< s2 <<endl;



}

} // namespace lic3



namespace copy
{



class string
{

public:

    string(const char* str = "")
        :_str(new char[strlen(str) + 1])
    {
            strcpy(_str, str);
    }

// 传统拷贝
    // string(const string& s)
    //     :_str(new char[strlen(s._str) + 1])
    // {
    //     strcpy(_str, s._str);
    // }

// 现代拷贝构造
    string(const string& s)
        :_str(nullptr)
    {
        string temp(s._str); // 构造一个一模一样的
        swap(_str, temp._str);
    }

// 传统赋值构造
    // string& operator=(const string& s)
    // {   
    //     if(this != &s)
    //     {
    //         char* tmp = new char[strlen(s._str) + 1];
    //         strcpy(tmp, s._str);

    //         delete[] _str;
            
    //         _str = tmp;
    //     }

    //     return *this;
    // }


// 现代写法

    string& operator=(const string& s)
    {

        if(this != &s)
        {
            string temp(s);
            swap(_str, temp._str);
        }
        return *this;

    }


    string& operator=(string& s)
    {
        if(this != &s)
        {
            string temp(s);
            swap(_str, temp._str);
        }
        return *this;
    }


    ~string()
    {
        delete[] _str;
        _str = nullptr;
    }



private:
    char* _str;
};




}



int main()
{


    lic3::test();

}
