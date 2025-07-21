#include "Date.h"

int main() {
    // 构造函数测试
    date d1(2024, 7, 20);
    d1.print();  // 2024 - 7 - 20

    // 拷贝构造函数测试
    date d2 = d1;
    d2.print();  // 2024 - 7 - 20

    // 赋值运算符测试
    date d3;
    d3 = d1;
    d3.print();  // 2024 - 7 - 20

    // 比较运算符测试
    date d4(2024, 8, 1);
    cout << boolalpha;
    cout << (d1 == d2) << endl;   // true
    cout << (d1 != d4) << endl;   // true
    cout << (d1 < d4) << endl;    // true
    cout << (d1 > d4) << endl;    // false
    cout << (d1 <= d4) << endl;   // true
    cout << (d1 >= d4) << endl;   // false

    // += 运算符测试
    d1 += 15;
    d1.print();  // 2024 - 8 - 4

    // + 运算符测试
    date d5 = d1 + 10;
    d5.print();  // 2024 - 8 - 14

    // ++前置 后置测试
    ++d1;
    d1.print();  // 2024 - 8 - 5
    d1++;
    d1.print();  // 2024 - 8 - 6

    // -= 运算符测试
    d1 -= 10;
    d1.print();  // 2024 - 7 - 27

    // - 运算符测试
    date d6 = d1 - 20;
    d6.print();  // 2024 - 7 - 7

    // --前置 后置测试
    --d1;
    d1.print();  // 2024 - 7 - 26
    d1--;
    d1.print();  // 2024 - 7 - 25

    // 两个日期之间的天数差
    int diff = d4 - d1;
    cout << "d4 - d1 = " << diff << " 天" << endl;

    // 取地址运算符测试
    cout << "d1 address: " << &d1 << endl;

    return 0;
}
