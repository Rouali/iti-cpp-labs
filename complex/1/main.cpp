#include <iostream>

using namespace std;
class Complex{
    int real ;
    int imag ;
public:
    Complex():real(0.0),imag(0.0){}
    Complex(int _real,int _imag){
         real = _real;
         imag = _imag;
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
    void print(){
        cout << real << " + " << imag <<"i" <<endl;
         }
    Complex operator+(Complex c){
        Complex res;
        res.real= real + c.real;
        res.imag= imag + c.imag;
        return res;
    }
    Complex operator+(int x){
        Complex res(real+x,imag);
        return res;
    }
    friend Complex operator+(int x,Complex c);
    int operator == (Complex c){
    return real == c.real && imag == c.imag;
    }
    int operator != (Complex c){
    return !(*this==c);
    }
    explicit operator int(){
        return real;
    }
    Complex operator++ (int){
        Complex temp =*this;
        real = real+1;
        return temp;
    }
    Complex operator++(){
        real = real + 1;
        return *this;
    }
};
Complex operator+(int x,Complex c){
        Complex res;
        res.real= c.real+x ;
        res.imag= c.imag;
        return res;
    }
int main()
{
    Complex c1(10,20);
    Complex c2(10,20);
    Complex c3;
    c3=c1+c2;
    c3.print();
    Complex c4(20,30);
    Complex c5;
    c5 = c4 + 2;
    c5.print();
    Complex c6;
    c6 = 3 + c4;
    c6.print();
    if(c1==c2)
        cout<<"\nEqual";
    else
        cout<<"\nNot equal";
    if(c1!=c4)
        cout<<"\nNot equal";
    else
        cout<<"\nEqual";
    int x;
    x =(int)c1;
    cout<<endl;
    cout<<x;
    cout<<endl;
    c1++.print();
    c1++.print();
    ++c2;
    c2.print();


    return 0;
}

