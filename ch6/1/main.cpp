#include <iostream>

using namespace std;
class Int{
    int x;
public:
    Int(){
        x=0;
    }
    Int(int _x){
        x=_x;
    }
    void print(){
        cout <<endl<<x;
    }
    Int add(Int &a){
        return x + a.x;
    }
};
int main()
{
    Int i1;
    Int i2(5);
    Int i3(6);
    i1.print();
    Int result=i2.add(i3);
    result.print();
    return 0;
}
