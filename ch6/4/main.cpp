#include <iostream>

using namespace std;
class Employee{
    int empNumb;
    float compensation;
public:
    Employee(int _number=0, float _comp=0.0){
        empNumb = _number;
        compensation = _comp;
    }
    void setData(){
        cout << "Enter employee number: ";
        cin >> empNumb;
        cout << "Enter employee compensation: ";
        cin >> compensation;

    }
    void display(){
        cout << empNumb << ":" << compensation<<"$"<<endl;
    }
};
int main()
{
    Employee employees[3];
    cout << "enter data for 3 employees:\n";
    for (int i = 0; i < 3; i++){
        cout << "employee " << i+1 <<":\n";
        employees[i].setData();
    }
    cout << "employees data is:\n" ;
    for (int i = 0; i < 3; i++){
        employees[i].display();
    }
    return 0;
}
