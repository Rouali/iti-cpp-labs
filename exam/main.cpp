#include <iostream>
using namespace std;
class Parent{
protected:
    int myVar;
public:
    Parent(int x){
        myVar=x;
    }
    void powerTwo(){
        cout<<myVar*myVar;
        }
    virtual void powerThree(){
        cout<<myVar*myVar*myVar;
    }
};
class Child:public Parent{
protected:
    int myData;
public:
    Child(int a,int b):Parent(a){
        myData=b;
    }
    void powerTwo(){
        cout<<myData*myData;
    }
    void powerThree(){
        cout<<myData*myData*myData;
    }

};


int main() {
    Child myCh(3,2);
    Parent *ptr;
    ptr = &myCh;
    ptr->powerTwo();
    ptr->powerThree();

    return 0;
}
