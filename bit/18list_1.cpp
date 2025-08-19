#include <iostream>
#include <list>
using namespace std;
int main()
{

    list<int> l;
    l.push_back(2);
    l.push_back(2);
    l.push_back(2);
    l.push_back(2);
    l.push_back(2);
    l.push_back(2);
    l.push_front(3);

    auto it  = l.begin();
    while(it != l.end())
    {
        cout<< *it <<"  ";
        it++;
    }
    cout<<endl;

    for(auto e : l)
    {
        cout<< e << "  ";
    }
    cout<<endl;

    auto rit = l.rbegin();
    while(rit != l.rend())
    {
        cout<< *rit << "  ";
        rit++;
    }
    cout<<endl;

    return 0;
}

