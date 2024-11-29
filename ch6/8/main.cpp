#include <iostream>

using namespace std;
class serial{
    int serialNum;
    static int count;
public:
    serial(){
        serialNum = ++count;
    }
    void display() const {
        cout << "I am object number " << serialNum<< endl;
    }
};
int serial::count=0;
int main()
{
    serial obj1;
    serial obj2;
    serial obj3;

    obj1.display();
    obj2.display();
    obj3.display();
    return 0;
}
