#include <iostream>
using namespace std;

class Date
{
public:
    int GetMonthsDays(int year, int month)
    {
        int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        if(year >= 0 && month >0 && month < 13)
        {
            
            if(month == 2 &&((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            {
                return 29;
            }
            else
           {
              return daysInMonth[month];
            }
        }
        else
        {
            cout<< "日数输入有误" <<endl;
            return -1;
        }
    }


    Date(int year = 2000, int month = 2, int day = 10)
    {
        if(day <= GetMonthsDays(year, month))
        {
            this->_year = year;
            this->_month = month;
            this->_day = day;
        }
        else
        {
            cout<< " 日期初始化有误 " <<endl;
        }
    }












private:
    int _year;
    int _month;
    int _day;
};


int main()
{

    Date d(200,2,55);
    return 0;
}

