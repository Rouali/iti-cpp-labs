#include <iostream>
#define esc 27
using namespace std;
class tollBooth{
    unsigned int totalCars;
    double totalToll;
public:
    tollBooth(unsigned int _totalCars = 0, double _totalToll = 0.0){
        totalCars = _totalCars;
        totalToll = _totalToll;
    }
    void payingCar(){
        totalCars++;
        totalToll += 0.50;
    }
    void nopayCar(){
        totalCars++;
    }
     void display() const {
        cout << "Total cars: " << totalCars << endl;
        cout << "Total Toll collected: $" << totalToll << endl;
    }
};
int main()
{
    tollBooth t1;
    char chois;
    cout << "enter 'p' for paying car, 'n' for non-paynig car, 'q' to exit:";
    while(true){
        cin >> chois;
        if (chois == 'p'){
            t1.payingCar();
        }
        else if (chois == 'n'){
            t1.nopayCar();
        }
        else if (chois == 'q'){
            cout << "exiting...";
            break;
        }

    }
    t1.display();
    return 0;
}
