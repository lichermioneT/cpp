#include<iostream>
#include<cstring>


namespace bit
{
    class string
    {
        public:
            /*string() // 无参构造函数
                :_str(new char[1])
            {
                _str[0] = '\0';
            }

            string(const char* str) // 带参数构造函数
                :_str(new char[strlen(str) + 1])
            {
                // if(str)
                // {
                //     _str = new char[strlen(str) +1];
                //     strcpy(_str,str);
                // }
                // else
                // {
                //     _str = nullptr;
                // }
                strcpy(_str,str); // 会拷贝\0;
            }
            */
// string对象存储字指针，指针指向字符数组，字符数组\0结尾
// strlen 是 C 语言标准库中的一个函数，用于计算字符串的长度（不包括结尾的空字符 \0）。它定义在 <string.h> 头文件中。
// size_t strlen(const char *str);

           string(const char* str = "")
                :_str(new char[strlen(str) + 1])  // 开辟一段空间 + \0
           {
                strcpy(_str, str);  // 把值给拷贝过去
           }
            
           ~string()
           {
              delete[] _str;
              _str = nullptr;
           }

           string(const string & s)
                :_str(new char[strlen(s._str) + 1])
           {
                strcpy(_str, s._str);
           }

            char& operator[](size_t i)
            {
                return _str[i];
            }

            string& operator=(const string& s)
            {
                if(&s != this)
                {
                    char* temp = new char[strlen(s._str) + 1];
                    strcpy(temp,s._str);
                    _str = temp;
                    delete[] _str;
                }
                return *this;
            }
            
            size_t size()
            {
                return strlen(_str);
            }

            const char* c_str()
            {
                return _str;
            }
        private:
        char* _str ;

    };


    void test()
    {
        string s1("hello"); // 这是常亮字符串
        for(int i = 0; i< s1.size(); i++)
        {
            std::cout<< s1[i] <<std::endl;
        }
    }

    void test1()
    {
        string s1("heloo");
        string s2(s1);
        std::cout<< s1.c_str() <<std::endl;
        std::cout<< s2.c_str() <<std::endl;
    }


};



namespace nit2
{

    class string
    {
    private:
        char* _str;
        size_t _size;
        size_t _capacity;

    public:
        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str,str);
        }
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
            return _str[i];
        }
        
        const char& operator[](size_t i)const
        {
            return _str[i];
        }

        const char* c_str()
        {
            return _str;
        }

    // std::ostream& operator<<(std::ostream& out, const std::string& s)
    // {
    //     for(size_t i = 0; i < s.size(); ++i)
    //     {
    //         out << s[i];
    //     }
    //     return out;
    // }

        void push_back(char ch)
        {
            if(_size == _capacity)
            {
                size_t newcapacity = _capacity == 0? 2 : _capacity * 2;
                char* temp = new char[newcapacity + 1]; // 多开一个空间存放\0;
                strcpy(temp,_str);
                delete[] _str;
                _str = temp;

                _capacity = newcapacity;
            }

            _str[_size] = ch;
            ++_size;
            
        }

        void append(const char* str)
        {
            size_t len= strlen(str);
            if(_size + len > _capacity)
            {
                size_t newcapacity = _size + len;
                char* newstr = new char[newcapacity + 1];
                strcpy(newstr,_str);
                delete[] _str;
                _str = newstr;
                _capacity = newcapacity;
            }
            strcpy(_str+_size,str);
            _size += len;
        }

        string& operator+=(char ch)
        {
            this->push_back(ch);
            return*this;
        }

        string& operator+=(const char* str)
        {
            this->append(str);
            return*this;
        }


    };

    void test()
    {
        string s1("hello");
        s1.push_back('c');
        s1.push_back('c');
        s1.push_back('c');
        s1.push_back('c');
    }







};




int main()
{
    // bit::test();
    nit2::test();











    return 0;
}