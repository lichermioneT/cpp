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
        :_str(new char[strlen(str) + 1])     // 这里的strlen不会计算斜杠零的。所以多拷贝一个斜杠零
    {   
        int len = strlen(str);
        strcpy(_str, str);                   // 数据拷贝过去，strcpy会拷贝斜杠零的。
        _size = _capacity = len;
    }

    string(const string& s)
        : _str(new char[strlen(s._str) + 1])
        , _size(s._size)
        , _capacity(s._capacity)
    {
        strcpy(_str, s._str);
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
    
    ~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }


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

    void push_back(char ch)
    {
        if(_size == _capacity)
        {
            size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
            _capacity = newcapacity;
        }
        _str[_size] = ch;
        ++_size;
        _str[_size] = '\0';   // 维护字符串结
    }

    void reserve(int n)
    {
        if (n > _capacity)
        {
            char* newstr = new char[n + 1];
            memcpy(newstr, _str, _size);

            newstr[_size] = '\0'; // 保证是以 \0 结尾的字符串
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
            
            // 从_size开始添加数据
            for (size_t i = _size; i < n; ++i)
                _str[i] = ch;

            _size = n;
        }

        _str[_size] = '\0';

    }


    void append(const char* str)
    {
        if (str == nullptr)
        return;

        int len = strlen(str);
        if((len + _size) > _capacity)
        {
            reserve(len + _size + 1);
        }

        strcpy(_str + _size, str);
        _size += len;

        _str[_size] = '\0';
    }
    
    string& insert(size_t pos, const char* str)
    {
        assert(pos <= _size);

        int len = strlen(str); // 不会计算斜杠零
        if((_size + len) > _capacity)
        {
            reserve(_size  + len);  // 至今预留空间下来
        }

        int end = _size;

        for(end; end >= pos; end--)
        {
            _str[end+len] = _str[end]; // 移动出来len个空间
        }

        for(int i = 0; i < len; i++)
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
            if(len > (_size - pos))
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
    friend std::ostream& operator<<(std::ostream& out, const string& s)
    {
        out << s._str;
        return out;
    }

private:
    char* _str;
    size_t _size;
    size_t _capacity;
    static size_t npos;
};

size_t string::npos = -1;

int main()
{
    // 构造函数 & 输出初始内容
    string s1("abc");
    cout << "s1: " << s1 << " size: " << s1.size() << " capacity: " << s1.capacity() << "\n";

    // 拷贝构造
    string s2(s1);
    cout << "s2 (copy of s1): " << s2 << "\n";

    // 赋值运算符
    string s3;
    s3 = s1;
    cout << "s3 (assigned from s1): " << s3 << "\n";

    // push_back
    s1.push_back('d');
    cout << "s1 after push_back('d'): " << s1 << "\n";

    // append
    s1.append("efg");
    cout << "s1 after append(\"efg\"): " << s1 << "\n";

    // insert
    s1.insert(1, "XYZ");
    cout << "s1 after insert(1, \"XYZ\"): " << s1 << "\n";

    // erase
    s1.erase(1, 3);
    cout << "s1 after erase(1, 3): " << s1 << "\n";

    // resize（扩展）
    s1.resize(10, '*');
    cout << "s1 after resize(10, '*'): " << s1 << "\n";

    // resize（缩小）
    s1.resize(5);
    cout << "s1 after resize(5): " << s1 << "\n";

    // reserve
    s1.reserve(50);
    cout << "s1 after reserve(50), capacity: " << s1.capacity() << "\n";

    // find(char)
    size_t pos1 = s1.find('c');
    cout << "find 'c' in s1: " << pos1 << "\n";

    // find(const char*)
    size_t pos2 = s1.find("bc");
    cout << "find \"bc\" in s1: " << pos2 << "\n";

    // 比较运算符
    string a("abc");
    string b("abd");

    cout << "a < b: " << (a < b) << "\n";
    cout << "a <= b: " << (a <= b) << "\n";
    cout << "a == b: " << (a == b) << "\n";
    cout << "a != b: " << (a != b) << "\n";
    cout << "a > b: " << (a > b) << "\n";
    cout << "a >= b: " << (a >= b) << "\n";

    return 0;
}
