#include <iostream>
#include <string>
using namespace std;

void test()
{
    string s("hello lichermionex ");
    s += 'x';
    s += "xxxx";
    s.push_back('a');
    s.append("xxxx");
    
    for(int i = 0; i < s.size(); i++)
    {
        cout<< s[i] << " ";
    }

    cout<< endl;


    auto it = s.begin();
    while(it != s.end())
    {
        cout<< *it << " ";
        it++;
    }
    
    cout<<endl;

    for(auto e : s)
    {
        cout<< e  << " ";
    }
    cout<<endl;
}



void test2()
{



// c_str
// 返回一个指针

    string s("hello lichermionex ");

    // 获取字符数组首地址，用c字符串的形式遍历
    const char* str = s.c_str();

    while(*str)
    {
        cout<< *str;
        ++str;
    }
    cout<<endl;
    
    // string重载的是operator<<
    cout<< s <<endl;

    // 直接输出const char*
    cout<< s.c_str()  <<endl;


    // ????
    s += '\0';
    s += "world";
    cout<< s <<endl;

    cout<< s.c_str() <<endl;
    
    
    // ascii码表
    unsigned char ch = 0;
    do {
        cout << ch << endl;
        ch++;
    } while (ch != 0);  // ch 回到 0 就结束

    // unicode编码
    // 计算机去表示几百个国家的文字
    // 编码表：数值和符号一一对应
    // 了解
    char ch1[] = "李海军";
    cout<< ch1 <<endl;
    cout << u8"你好，世界！" <<endl;  // u8 表示 UTF-8 字符串
    wcout << L"你好，世界！" <<endl;  // L 表示宽字符
}





// 字符串查找
void test3()
{

    string s("string.cpp");
    string s1("string.cppx");
    string s2("string.txt");
    size_t pos1 = s.find('.');
    size_t pos2 = s.find('.');
    size_t pos3 = s.find('.');
    
    cout<< s.substr(pos1) <<endl;
    cout<< s1.substr(pos2) <<endl;
    cout<< s2.substr(pos3) <<endl;



    string s3("linux.cpp.tar");
    size_t pos4 = s3.rfind('.');
    cout<< s3.substr(pos4) <<endl;
}


void split_url(const string& url)
{

    size_t pos1 =  url.find(':');
    
    if(pos1 != string::npos)
    {
        cout<< url.substr(0, pos1) <<endl;
    }

    size_t pos2 = url.find('/', pos1 + 3);
    if(pos2 != string::npos)
    {
        cout<< url.substr(pos1 + 3, pos2-pos1-3) <<endl;
    }
    
    cout<< url.substr(pos2 + 2) <<endl;
}


void test4()
{
    
    string url("https://chatgpt.com/c/687b34ed-3584-8005-9a5e-9715503a491f");
    string giturl("https://gitee.cn/partner");
    string linux_url("https://github.com/torvalds/linux");
    // 协议
    // 域名
    // 资源名称

    // 分离出三部分
    split_url(url);
    split_url(giturl);
    split_url(linux_url);

}



void test5()
{

// 尽量使用+=
    // string s1("hello ");
    // string ret1 = s1 + "world ";

    // cout<< s1 <<endl;

    // string ret2 = s1 +="world ";
    
    // cout<< s1 <<endl;

    // cout<< ret1 <<endl;
    // cout<< ret1 <<endl;
    

    // string s1("asadf");
    // string s2("fda");

    // cout<< (s1 < s2) <<endl;
    // cout<< (s1 < "asdfas") <<endl;
    // cout<< ("TTTT" < s2) <<endl;





}








//getline()

void test6()
{

    string s;
    // cin遇到空格直接放弃读取
    // cin>>s;


    // getline只是遇到换行才结束的
    getline(cin, s);
    size_t pos =  s.rfind(' ');
    cout<< s.size() - (pos + 1) <<endl;

}









int main()
{
    
// 子串是起始位置，字符串长度
// s.substr();
    // test();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
        
    return 0;
}






































































