#include <iostream>
using namespace std;

class Time{
    int h;
    int m;
    int s;
public:
    Time(int _h=0, int _m=0, int _s=0){
        h=_h;
        m=_m;
        s=_s;
    }
    void display(){
        cout << h << ":" << m << ":" << s;
    }
    void add(Time &t1, Time &t2){
        s = t1.s+t2.s;
        m = s/60 ;
        s %= 60;
        m = t1.m+t2.m;
        h = m/60;
        m %= 60;
        h=t1.h+t2.h;
    }
};
int main()
{
    Time t1(5, 45, 30);
    Time t2(3, 20, 40);
    Time result;

    result.add(t1, t2);
    result.display();
    return 0;
}
