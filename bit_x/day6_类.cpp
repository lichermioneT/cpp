// #include<iostream>
// using namespace std;

// class date
// {
// private:
//     int _year;
//     int _month;
//     int _day;

// public:
//     int GetMonthDay(int year, int month)
//     {
//         static int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//         if((year % 4 == 0 && year % 100 != 0) || year % 400 ==0)
//         {
//             return 29;
//         }
//         else
//         {
//             return daysInMonth[month];
//         }
//     }

//     // 构造函数
//     date(int year = 2000, int month = 1, int day = 1)
//     {
//         if(year >= 0 && month >0 && month < 13 && day > 0 && day<=GetMonthDay(year,month) )
//         {
//             this->_year = year;
//             this->_month = month;
//             this->_day = day;
//         }
//         else    
//         {
//             cout<< "时间已经被重置为1949年10月1日" <<endl;
//             this->_year = 1949;
//             this->_month = 10;
//             this->_day = 1;
//         }
//     }

//     // 析构函数
//     ~date()
//     {

//     }

//     // 拷贝构造
//     date(const date & d)
//     {
//         this->_year = d._year;
//         this->_month = d._month;
//         this->_day = d._day;
//     }

//     /* d1  - d2
//     int operator - (const date& d)
//     {   
//         int flag = 1;
//         date max = *this; // 拷贝构造
//         date min = d;  // 拷贝构造  max min 修改不会 影响*this和d
//         if(*this < d)
//         {
//             max = d;
//             min = *this; // operator=
//             flag = -1;
//         }
        
//         int n  = 0;
//         while(min != max)
//         {
//             ++min;
//             ++n;
//         }
//         return n*flag;
//     }

//     */
    

//     void  print()
//     {
//         cout<< _year << " - " << _month << " -  " << _day <<endl;
//     }
// };


// int main()
// {
//     date d1(2025,5,5);
//     date d2(d1);
//     d2.print();
//     return 0;
// }



// #include<iostream>
// using    namespace std;
// class date
// {
// private:
//     int _year;
//     int _month;
//     int _day;
// public:

//     // 函数体内初始化
//     // date(int year = 0, int month = 1, int day = 1)
//     // {
//     //     _year = year;
//     //     _month  = month;
//     //     _day  = day;
//     // }

//     // 初始化列表 初始化引用变量 
//     date(int year = 0, int month = 1, int day = 1)
//     :_year(year)
//     ,_month(month)
//     ,_day(day)



//     // const修饰成员函数 
//     // 修饰this指针指向的对象
//     // const date* p1 修饰指向的数据
//     // date const* p2 修饰指向的数据
//     // date*  const p3 指针本身

//     // const date& this
//     void print() const
//     {
//         cout<< _year << "-" << _month << "-"<< _day<<endl;
//         //  this->_year = 1000; 不能修改成员变量 const修饰保护了*this
//     }

//     // this指针调用成员函数
//     /* 
//      void f1()
//     {
//         f2(); // 可以的
//     }

//     void f2() const
//     {

//     }
//     void f3()
//     {

//     }
//     void f4() const
//     {
//         f3(); // 不行的
//     }
    
//      */
//     date* operator&()
//     {
//         return this;
//     }
  
// };

// // 权限放大了
// void print(const date& d)
// {
//     d.print(); 
// }

int main()
{

// const修饰函数
// 什么时候成员函数加上const当成员函数不需要修改变量的值
// 不修变量的时候就添加const
    // date d1(2020,4,18);
    // print(d1);
    // d1.print();  // 权限给你了 你可以缩小不能放大的
// this指针调用成员函数
    // date d1;
    // date d2;
    // cout<< &d1 <<endl;
    // cout<< &d2 <<endl;
    // const date d3; // 权限放大了


// 初始化列表初始化  引用变量 类 const修饰的数据































    return 0;
}