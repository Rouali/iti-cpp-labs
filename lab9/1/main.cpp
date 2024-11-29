#include <iostream>

using namespace std;
class Complex{
    double real ;
    double imag ;
public:
    Complex():real(0.0),imag(0.0){}
    void setReal(double _real){
        real = _real;
    }
    double getReal(){
        return real;
    }
    void setImag(float _imag){
        imag = _imag;
    }
    double getImag(){
        return imag;
    }
    void print(){
        cout << real << " + " << imag <<"i" <<endl;
         }
Complex Add(Complex c){
        Complex res;
        res.real= real + c.real;
        res.imag= imag + c.imag;
        return res;
    }
};
Complex Add(Complex c3 , Complex c4);
int main()
{
    Complex c1,c2;
    c1.setReal(5.5);
    c1.setImag(3.2);
    c2.setReal(6.2);
    c2.setImag(1.2);
    cout<<"number 1 :"<<endl;
    c1.print();
    cout <<endl<<"number 2 :"<<endl;
    c2.print();
    cout <<endl<<"result = "<<endl;
    Complex res = c1.Add(c2);
    res.print();
    Complex c = Add(c1,c2);
    c.print();

    return 0;
}
Complex Add(Complex c3 , Complex c4){
    Complex res;
    res.setReal(c3.getReal()+c4.getReal());
    res.setImag(c3.getImag()+c4.getImag());
    return res;
}

