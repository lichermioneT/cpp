#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <algorithm>
namespace lic
{

template<class T>
class vector
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endofstorage(nullptr)
    {

    }

    ~vector()
    {
        delete[] _start;
        _start = _finish = _endofstorage = nullptr;
    }

    // vector(const vector<T>& v )
    // {
    //     _start = new T[v.capacity()];
    //     _finish = _start;
    //     _endofstorage = _start + v.capacity();

    //     for(size_t i = 0; i < v.size(); i++)
    //     {
    //         *_finish = v[i];
    //         ++_finish;
    //     }
    // }

    vector(const vector<T>& v)
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endofstorage(nullptr)
    {   
        reserve(v.capacity());
        for(const auto& e : v)
        {
            push_back(e);
        }
    }

    
    // vector<T>& operator=(const vector<T>& v)
    // {
    //     if(this != &v)
    //     {
    //         delete[] _start;
    //         _start = new T[capacity()];
    //         memcpy(_start, v._start, sizeof(T) * v.size());
    //     }
    //     return *this;
    // }

    vector<T>& operator=(vector<T> v)
    {
        // std::swap(_start, v._start);
        // std::swap(_finish, v._finish);
        // std::swap(_endofstorage, v._endofstorage);
        swap(v);
        return *this;
    }

    void swap(vector<T>& v)
    {
        std::swap(_start, v._start);
        std::swap(_finish, v._finish);
        std::swap(_endofstorage, v._endofstorage);
    }

    void push_back(const T& x)
    {
        if(_finish == _endofstorage)
        {
            size_t newcapacity = (capacity() == 0 ? 2 : capacity() * 2);
            reserve(newcapacity);
        }
        *_finish = x;
        ++_finish;
    }
    
    void pop_back()
    {
        assert(_start < _finish);
        --_finish;
    }

    void insert(iterator pos , const T& x)
    {
        assert(pos <= _finish);

        if(_finish == _endofstorage)
        {   
            size_t n = pos - _start;
            
            size_t newcapacity = (capacity() == 0 ? 2 : capacity() * 2);
            reserve(newcapacity);

            pos = _start + n;
        }

        iterator end = _finish - 1;
        while(end >= pos)
        {
            *(end + 1) = *(end);
            end--;
        
        }

        *pos = x;
        ++_finish;
    }
    
    iterator erase(iterator pos)
    {
        assert(pos < _finish);
        iterator it = pos;

        while(it < _finish)
        {
            *it = *(it + 1);
            it++;
        }
        --_finish;
        return pos;
    }

    size_t size() const
    {
        return _finish - _start;
    }

    size_t capacity() const
    {
        return _endofstorage - _start;
    }

    void reserve(int n)
    {
        if(n > capacity())
        {
            size_t sz = size();
            T* tmp = new T[n];
            if(_start)
            {   
                // memcpy(tmp, _start, sizeof(T) * sz);  浅拷贝
                
                for(size_t i = 0; i < sz; i++)
                {
                    tmp[i] = _start[i];
                }

                delete[] _start;
            }
            _start = tmp;
            _finish = tmp + sz;
            _endofstorage = tmp + n;
        }
    }

    void resize(size_t n, const T& val = T())
    {
        if(n < size())
        {
            _finish = _start + n;
        }
        else
        {
            if(n > capacity())
            {
                reserve(n);
            }

            while(_finish < _start + n)
            {
                *_finish = val;
                ++_finish;
            }
        }
         
    }


    iterator begin()
    {
        return _start;
    }

    const_iterator begin() const
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    const_iterator end() const
    {
        return _finish;
    }
    
    T& operator[](size_t i)
    {
        assert(i < size());
        return _start[i];
    }

    const T& operator[](size_t i) const
    {
        assert(i < size());
        return _start[i];
    }
    

private:
    iterator _start;
    iterator _finish;
    iterator _endofstorage;
};

void fun(const vector<int> v)
{   
        for(auto e : v)
        {
            std::cout<< e << "  ";
        }
        std::cout<<std::endl;
}


// void test()
// {
    
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(1);
//     v.push_back(1);
    
//     vector<int>::iterator it = v.begin();
//     while(it != v.end())
//     {   
//         *it += 3;
//         std::cout<< *it << "  ";
//         ++it;
//     }
    
//     std::cout<<std::endl;



//     for(auto& e: v)
//     {   
//         e += 3;
//         std::cout<< e << "  ";
//     }
//     std::cout<<std::endl;
    
//     for(size_t i = 0; i < v.size(); i++)
//     {
//          v[i] += 2;
//         std::cout<< v[i] << "  ";
//     }
//     std::cout<<std::endl;
    
//     fun(v);


//     v.insert(v.begin(),50);
//     v.insert(v.begin(),41);
//     v.insert(v.begin(),36);
//     v.insert(v.begin(),21);
//     v.insert(v.begin(),11);
//     v.insert(v.begin(),34);
//     v.insert(v.begin(),42);
//     for(auto e : v)
//     {
//         std::cout<< e << "  ";
//     }
//     std::cout<<std::endl;

//     vector<int>::iterator it1 = v.begin();
//     while(it1 != v.end())
//     {
//         if(*it1 % 2 == 0)
//         {
//             it1 = v.erase(it1);
//         }
//         else
//         {
//             it1++;
//         }
//     }


//     for(auto e : v)
//     {
//         std::cout<< e << "  ";
//     }
//     std::cout<<std::endl;
    


//     v.resize(20,2);

//     for(auto e : v)
//     {
//         std::cout<< e << "  ";
//     }
//     std::cout<<std::endl;



//     vector<int> v3;
//     v3.push_back(1);
//     v3.push_back(1);
//     v3.push_back(1);
//     v3.push_back(1);
//     v3.push_back(1);
//     v = v3;

//     for(auto e : v3)
//     {
//         std::cout<< e << "  ";
//     }
//     std::cout<<std::endl;
// }




void test2()
{
    vector<std::string> v;
    v.push_back("abfdsadasf");


}



}


int main()
{



    // lic::test();
    


    // int arr[10] = {0};
    // memset(arr, 22, 40);

    // for(auto e : arr)
    // {
    //     std::cout<< std::hex << e << "  ";
    // }
    // std::cout<<std::endl;






    return 0;
}

