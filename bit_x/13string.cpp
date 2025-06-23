#include<iostream>
#include<cstring>
#include<assert.h>
namespace lic{

    class string{
    
    public:
        // string()
        //     :_str(new char[1])
        // {
        //     _str[0] = '\0';
        // }

        // string(const char* str)
        //     :_str(new char[(strlen(str) + 1)])
        // {
        //     strcpy(_str,str);
        // }

        string( const char* str = "") // 里面只有\0
            :_str(new char[(strlen(str) + 1)])
        {
            strcpy(_str,str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

        size_t size()
        {
            return strlen(_str);
        }   

// 深拷贝
        string(const string& s)
            :_str(new char[(strlen(s._str) + 1)]) // 先开空间

        {
            strcpy(_str,s._str); // 把值复制给新的空间
        }

// 复制构造也是深拷贝
        // s1 = s3 返回值是s1
        string& operator=(const string& s)
        {
           if(&s != this) // 防止自己给自己赋值
           {
                char* temp = new char[(strlen(s._str) + 1)];
                strcpy(temp,s._str);
                delete[] _str;
                _str = temp;
                return *this;
           }
        }



        char& operator[](size_t i)
        {
            return _str[i];
        }

        const char* c_str()
        {
            return _str;
        }



    private:
        char* _str;
    };


    void test1()
    {
        string s("helll");
        for(size_t i = 0; i < s.size(); i++ )
        {
            std::cout<< s[i] <<std::endl;
        }
        for(size_t i = 0; i < s.size(); i++ )
        {   
            s[i] += 1;
            std::cout<< s[i] <<std::endl;
        }
    }
    
    void test2()
    {
        string s1("hello");
        string s2(s1);

        for(size_t i = 0; i < s2.size(); i++ )
        {
            std::cout<< s2[i] <<std::endl;
        }
        for(size_t i = 0; i < s2.size(); i++ )
        {   
            s2[i] += 1;
            std::cout<< s2[i] <<std::endl;
        }
    }

};


namespace bit2
{

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
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity + 1];    // \0不是有效字符
        strcpy(_str,str);
    }

// 拷贝构造和赋值

    ~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    size_t size()const
    {
        return _size;
    }

    size_t capacity()const
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

    const char* c_str()const
    {
        return _str;
    }

    void puhs_back(char ch)
    {
        // 空间满了直接增容
        if(_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 2 : 2 * _capacity;
            char* temp = new char[newcapacity + 1];
            strcpy(temp,_str);
            delete[] _str;
            _str = temp;
            newcapacity  = newcapacity;

        }
        _str[_size] = ch;
        ++_size;
    }

    void apppend(const char* str)
    {
        // 必须先检查容量
        size_t len = strlen(str);
        if(_size + len > _capacity)
        {
            size_t newcapacity = _size +len;
            char * temp = new char[newcapacity + 1];
            strcpy(temp,_str);
            _str = temp ;
            _capacity = newcapacity;
        }

        strcpy(_str+_size,str);
        _size = len;


    }

// 输出 
    // ostream& operator<<(ostream& out, const string& s)const
    // {
    //     for(size_t i = 0; i < s.size(); i++)
    //     {
    //         cout<< s[i];
    //     }
    // }

// 输入











private:
    char* _str;
    size_t _size;
    size_t _capacity;
};




    void test()
    {   string s("asdfsdfasd");
        // string::iterator it = s.begin();
        // while(it != s.end())
        // {
        //     std::cout<< *it << std::endl;
        //     ++it;
        // }

// 范围for最终会被替换成迭代器
// iterator begin() end()
        // for(auto e : s)
        // {
        //     std::cout<< e << std::endl;
        // }

        s.puhs_back('c');
        s.puhs_back('c');
        s.puhs_back('c');
        s.puhs_back('c');

        string::iterator it = s.begin();
        while(it != s.end())
        {
            std::cout<< *it << std::endl;
            ++it;
        }

    }

































};



int main()
{

    // lic::test1();
    // lic::test2();
// 深拷贝就是先开空间，然后指向新空间，释放旧空间

    bit2::test();













    return 0;
}