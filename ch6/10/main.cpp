#include <iostream>
#include<conio.h>
#include <windows.h>

using namespace std;
class Angel{
    int degree;
    float minutes;
    char direction;
public:
    angle(int _degree = 0, float _minutes = 0.0, char _direction = 'N')
    : degrees(_degree), minutes(_minutes), direction(_direction) {}
    void getAngle(){
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }
    void display(){
        cout<<degree<<"\xF8"<<minutes<<"\xF8"<<direction;
    }
};
class Ship{
    static int shipCount;
    int serial;
    angle latitude;
    angle longitude;
public:
    ship() : serialNumber(++shipCount) {}
    void getPosition() {
        cout << "Enter latitude:\n";
        latitude.getAngle();
        cout << "Enter longitude:\n";
        longitude.getAngle();
    }
    void display() const {
        cout << "Ship Serial Number: " << serialNumber << endl;
        cout << "Latitude: ";
        latitude.display();
        cout << endl;
        cout << "Longitude: ";
        longitude.display();
        cout << endl;
    }

};
int ship::shipCount = 0;
int main()
{
    ship ship1, ship2, ship3;
    cout << "Enter details for Ship 1:\n";
    ship1.getPosition();
    cout << "Enter details for Ship 2:\n";
    ship2.getPosition();
    cout << "Enter details for Ship 3:\n";
    ship3.getPosition();

    cout << "\nDetails of Ships:\n";
    ship1.display();
    cout << endl;
    ship2.display();
    cout << endl;
    ship3.display();

     return 0;
}
