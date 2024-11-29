#include <iostream>
using namespace std;
class Complex{
    int real;
    int imag;
    static int counter;
public:
    static int getCounter(){
        return counter;
    }
    Complex(){
        real=0;
        imag=0;
        counter++;
    }
    Complex(int _real,int _imag){
        real = _real;
        imag = _imag;
        counter++;
        }
    void setReal(int _real){
        real = _real;
    }
    int getReal(){
        return real;
    }
    void setImag(int _imag){
        imag = _imag;
    }
    int getImag(){
        return imag;
    }
     Complex(int _real){
        real=_real;
        imag = 0;
        counter++;
    }
    print(){
        cout<<endl;
        if(imag>0)
            cout<<endl<<real<<"+"<<imag<<"i";
        else if (imag<0)
            cout<<endl<<real<<imag<<"i";
        else
            cout<<real;
    }
    ~Complex(){
        counter--;
    }
};
int Complex::counter=0;
int main()
{
    Complex arr[3]={Complex(10,20),Complex(20,30)};
    Complex* ptr[3];
    ptr[0]=new Complex(20,30);
    ptr[0]->print();
    ptr[1]=&arr[0] /*arr */;
    ptr[2]=&arr[1] /*arr+1*/;
    ptr[1]->print();
    delete ptr[0];
    for(int i = 0;i<3;i++){
            arr[i].print();
    }
    cout<<Complex::getCounter();
    return 0;
}
