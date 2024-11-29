#include <iostream>

using namespace std;
class Angle{
    int degree;
    float minute;
    char direction;
public:
    Angle(int d,float m,char _d){
        degree = d;
        minute = m;
        direction = _d;
    }
    void setAngle(){
        cout << "enter angel(angel minutes direction):";
        cin >> degree >> minute >> direction;
    }
    void displayAngle(){
        cout << degree << "\xF8" << minute << "' " << direction << endl;
    }
};
int main()
{
    Angle a1(179, 59.9, 'E');
    a1.displayAngle();
    char choise;
    do{
        Angle a2(0, 0.0, 'N');
        a2.setAngle();
        a2.displayAngle();
        cout << "add another angel(y/n)?";
        cin >> choise;
    }while (choise == 'y');
    return 0;
}
