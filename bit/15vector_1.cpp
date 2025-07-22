#include <iostream>
#include <vector>
using namespace std;


void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    vector<int> v2(v);
    
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<< v[i] << " ";
    }
    cout<<endl;

    vector<int> v3;
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(4);


    v = v3;
    for(size_t i = 0; i < v3.size(); i++)
    {
        cout<< v3[i] << " ";
    }
    cout<<endl;
}




void test2()
{



    vector<int> v = {1,2,4,5,7,6,7,5,41,22,23,33,1};
    
    cout<< 1 <<endl;
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<< v[i] << "  ";
    }
    cout<<endl;

    cout<< 2 <<endl;
    auto it = v.begin();

    for(size_t i = 0; i < v.size(); i++)
    {
        cout<< *it << "  ";
        it++;
    }
    cout<<endl;


// 范围for本质是迭代器
    cout<< 3 <<endl;
    for(auto e : v)
    {
        cout<< e <<"  ";
    }
    cout<<endl;
}

void test3()
{
    vector<int> v = {1,22,33,44,77,66,44,22,22,5551,11,656};

    auto it = v.begin();
    while(it != v.end())
    {   
        cout<< *it << "  ";
        it++;
    }
    cout<<endl;

    auto itc = v.cbegin();
    while(itc != v.cend())
    {
        // *cit += 1;
        cout<< *itc << "  ";
        itc++;
    }
    cout<<endl;


    auto itr = v.rbegin();
    while(itr != v.rend())
    {
        cout<< *itr << "  ";
        itr++;
    }
    cout<<endl;
}

void test4()
{

    vector<int> v = {1,2,5,6,4,88,5,5111,222222,55,211};
    cout<< v.size() <<endl;
    cout<< v.capacity() <<endl;

    for(size_t i = 0; i < 100; i++)
    {
        v.push_back(i);
        if(v.size() == v.capacity())
        {
            cout<< v.size() <<endl;
        }
    }
    
    cout<< v.size() <<endl;
    cout<< v.capacity() <<endl;

}


void test5()
{

    vector<int> v = {1,2,3,4,5};
    // v[5];
    // v.at[5];
}


































int main()
{
    // test();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}

