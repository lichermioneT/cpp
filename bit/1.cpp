#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "abcdef";

    string s1 = s.substr(2);      // 从下标 2 开始提取，直到结尾 → "cdef"
    string s2 = s.substr(1, 3);   // 从下标 1 开始提取 3 个字符 → "bcd"

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
