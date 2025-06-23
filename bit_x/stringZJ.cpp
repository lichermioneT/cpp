#include<iostream>
#include<string.h>

class string
{
public:
    string()
    {
        _str = new char[1];
        _str[1] = '\0';
        _size=_capacity = 0;
    }

    string(const char* str)
    {   
        _size = _capacity = strlen(str); // strlen不会计算\0
        _str = new char[strlen(str) + 1]; // 多开一个用来存放\0
        strcpy(_str,str); // strcpy会拷贝\0
    }

    string(const string& s)
    {
        _size=s._size;
        _capacity=s._capacity;
        _str=new char[s._capacity+1];
        
        strcpy(_str,s._str);
    }









private:
    char * _str;
    size_t _size;
    size_t _capacity;
};


int main()
{


}