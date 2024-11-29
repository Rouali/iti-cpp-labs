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
        cout<<"\n Number of obj = "<<counter;
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
    Complex c1(10,20);
    Complex c2;
    Complex c3(8);
    c1.print();
    cout<<Complex::getCounter();
    return 0;
}
