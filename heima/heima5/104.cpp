#include<iostream>
#include<string>
using namespace std;

class Cube
{
public:
    void set_L(int x)
    {
        m_l = x;
    }

    int getl()
    {
        return  m_l;
    }

    void set_w(int x)
    {
        m_w = x;
    }
   int getw()
    {
        return  m_w;
    }

    void set_h(int x)
    {
        m_h = x;
    }

    int geth()
    {
        return  m_w;
    }

    int cals()
    {
        return 2 * m_h *m_l + 2 * m_h * m_w + 2 * m_l * m_w;
    }

    int calv()
    {
        return m_h * m_l * m_w;
    }

private:
    int m_l;
    int m_w;
    int m_h;

};

// 全局函数
bool issame(Cube &c1, Cube &c2)
{
    if(c1.getl() == c2.getl() && c1.geth() == c2.geth() && c1.getw() == c2.geth())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    Cube c1;
    c1.set_L(10);
    c1.set_w(10);
    c1.set_h(10);
    int s = c1.cals();
    int v = c1.calv();
    cout<< s <<endl;
    cout<< v <<endl;

    Cube c2;
    c2.set_L(10);
    c2.set_w(10);
    c2.set_h(100);

    bool ret = issame(c1, c2);
    cout<< ret <<endl;



    return 0;
}