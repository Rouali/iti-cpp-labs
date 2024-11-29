#include <iostream>
using namespace std;
class Duration{
    int hours;
    int minutes;
    int seconds;
    public:
    void setHours(int _hours){
        hours = _hours;
    }
    int getHours(){
        return hours;
    }
    void setMinutes(int _minutes){
        minutes = _minutes;
        myfunc();
    }
    int getMinutes(){
        return minutes;
    }
    void setSeconds(int _seconds){
        seconds = _seconds;
         myfunc();
    }
    int getSeconds(){
        return seconds;
    }
    Duration() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Duration(int _hours,int _minutes,int _seconds){
        hours = _hours;
        minutes = _minutes;
        seconds = _seconds;
        myfunc();
    }
    Duration(int totalSec) {
        hours = totalSec / 3600;
        totalSec %= 3600;
        minutes = totalSec / 60;
        seconds = totalSec % 60;
        }
    void myfunc(){
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }
    void print(){
        if (hours == 0){
            cout<<"Minutes :"<<minutes<<" Seconds :"<<seconds;
        }
        else{
            cout<<"Hours :"<<hours<<" Minutes :"<<minutes<<" Seconds :"<<seconds;
        }
         cout << endl;
    }
    Duration operator+(Duration d){
        Duration res;
        res.hours = hours + d.hours;
        res.minutes = minutes + d.minutes;
        res.seconds = seconds + d.seconds;
        res.myfunc();
        return res;
    }
    Duration operator+(int x){
        Duration res(hours,minutes,seconds+x);
        res.myfunc();
        return res;
        }
    friend Duration operator+(int x,Duration d);
    Duration operator++ (int){
        Duration temp =*this;
        minutes = minutes+1;
        return temp;
    }
    Duration operator--(){
        minutes = minutes - 1;
        return *this;
    }
    int operator>(Duration d){
        return (hours*3600+ minutes*60+seconds)>(d.hours*3600+d.minutes*60+d.seconds);
    }
    int operator<=(Duration d){
        return (hours*3600+ minutes*60+seconds)<=(d.hours*3600+d.minutes*60+d.seconds);
    }

};
Duration operator+(int x,Duration d){
        Duration res(d.hours,d.minutes,d.seconds+x);
        res.myfunc();
        return res;
        }
int main()
{
    Duration* d = new Duration (1,10,15);
    d->print();
    delete d;

    Duration* d1 = new Duration (3600);
    d1->print();
    delete d1;

    Duration* d2 = new Duration (7800);
    d2->print();
    delete d2;

    Duration* d3 = new Duration (666);
    d3->print();
    delete d3;

    Duration d4(2,10,15);
    Duration d5(3,10,15);
    Duration D(666);
    Duration d6,d7,d8;
    d6 = d4+d5;
    d6.print();
    d7 = d4 + 3600;
    d7.print();
    d8 = 666 + D;
    d8.print();
    d4++.print();
    d4++.print();
    --d5;
    d5.print();
    if (d4>d5)
        cout<<"\n d4 > d5";
    else
        cout<<"d4 < d5";
    cout << endl;
    if(d4<=d5)
        cout<<"d4 < d5";
    else
        cout<<"d5 > d4";
    return 0;
}
