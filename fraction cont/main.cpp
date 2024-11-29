#include <iostream>

using namespace std;
class Fraction{
    int num;
    int dom;
    int commonDivisor(int a, int b) {
        while( b != 0 ) {
            int temp= b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    void simplify() {
        int divisor = commonDivisor(num, dom);
        num /= divisor;
        dom /= divisor;
    }
public:
    void setNum(int _num){
        num=_num;
    }
    int getNum(){
        return num;
    }
    void setDom(int _dom){
        dom=_dom;
    }
    int getDom(){
        return dom;
    }
    Fraction(){
        num = 1 ;
        dom = 1 ;
        simplify();
    }
    Fraction(int _num){
        num = _num ;
        dom = 1 ;
        simplify();
    }
    Fraction(int _num,int _dom){
        num = _num;
        dom = _dom;
        simplify();
    }
    void print(){
        if( dom == 1)
            cout<<num<<endl;
        else
            cout<<num<<"/"<<dom<<endl;
    }
   Fraction operator+(Fraction& f){
       Fraction res;
       res.num = ( f.num * dom ) + ( num * f.dom );
       res.dom = dom * f.dom;
       res.simplify();
       return res;
   }
   Fraction operator-(Fraction& f) {
        Fraction res;
        res.num = ( f.num * dom ) - ( num*f . dom ) ;
        res.dom = dom * f.dom ;
        res.simplify();
        return res;
    }
    Fraction operator*(Fraction& f) {
        Fraction res;
        res.num = num*f . num ;
        res.dom = dom * f.dom ;
        res.simplify();
        return res;
    }
    Fraction operator/(Fraction& f) {
        Fraction res;
        res.num = num * f.dom;
        res.dom = dom * f.num;
        res.simplify();
        return res;
    }
    Fraction& operator++(){
        num += dom;
        simplify();
        return *this;
    }
    Fraction& operator--(){
        num -= dom;
        simplify();
        return *this;
    }
    explicit operator float(){
        return (float)num/(float)dom;
    }
};
int main()
{
    Fraction f1(5,5);
    f1.print();
    Fraction f2(8,2);
    f2.print();
    Fraction f3(10,20);
    Fraction f4(5,6);
    Fraction f5 = f3 + f4;
    f5.print();
    Fraction f6 = f3 - f4;
    f6.print();
    Fraction f7 = f3 * f4;
    f7.print();
    Fraction f8 = f3 / f4;
    f8.print();
    ++f3;
    f3.print();
    --f4;
    f4.print();
    float result =(float)f4;
    cout << "Fraction f3 as float: " << result << endl;

    return 0;
}
