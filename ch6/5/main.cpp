#include <iostream>

using namespace std;
struct date{
    int day;
    int month;
    int year;
    char s;
};
class Date{
    date d1;
public:
    Date(){
        d1.day = d1.month = d1.year =0;
    }
    Date(int _d,int _m,int _y){
        d1.day = _d;
        d1.month = _m;
        d1.year = _y;
    }
    void getdate(){
        cout << "enter date (dd/mm/yy):";
        cin >> d1.day>>d1.s>>d1.month>>d1.s>>d1.year;

    }
    void showdate(){
        cout << d1.day<<d1.s<<d1.month<<d1.s<<d1.year;
    }
};
int main()
{
    Date d;
    d.getdate();
    d.showdate();
    return 0;
}
