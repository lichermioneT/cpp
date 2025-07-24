#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums)
{
    int val = 0;
    for(int i = 0; i < nums.size(); i++)
    {
         val ^= nums[i]; // 异或，相异为1，相同为0.
                         // 0异或任何数等于任何数。
    }
    return val;
}



class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {   
        int bitsArray[32]={0};
        for(auto val : nums)
        {
            for(size_t i = 0; i < 32; i++)
            {
                if(val & (1<<i))
                {
                    bitsArray[i]++;
                }
            }
        }

        int num = 0;
        for(size_t i = 0; i < 32; ++i)
        {
            if(bitsArray[i] % 3 == 1)
            {
                num |= (1 << i);
            }
        }

        return num;
    }
};


// 迭代器失效
void test()
{
    
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // vector<int>::iterator it = v.begin();
    // 这里的迭代器失效了，因为数据扩容，
    // 数据不在原来的地方
    v.push_back(66);
    v.push_back(66);
    v.push_back(66);

    for(auto e: v)
    {
        cout<< e << " ";
    }
    cout<<endl;
}

void test2()
{
    
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it = v.begin();

    while(it != v.end())
    {
        if(*it % 2 == 0)
        {
            it = v.erase(it); //  erase有返回值，就是删除值的下一个位置的迭代器。 
        }
        else
        {
            ++it;
        }
    }

    for(auto e : v)
    {
        cout<< e << " ";
    }
    cout<<endl;


}











































int main()
{
    // test();
    test2();
    return 0;
}

