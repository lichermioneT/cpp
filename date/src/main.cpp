#include "Date.h"
int main() {
    // cout<< " --- " <<endl;
    // date d1(2000, 2, 10);
    // date d2 = d1 + 10000;
    // d2.print();
    // cout << d1 - d2 << endl;
    // cout << d2 - d1 << endl;
    // cout<< " --- " <<endl;

    date d(2000,2,10);
    d += -10;
    d.print();
    cout<< " ii "<<endl;
    return 0;
}