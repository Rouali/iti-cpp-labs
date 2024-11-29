#include <iostream>
using namespace std;
class Fraction{
    int num;
    int den;
public:
    Fraction(){
        num = 1 ;
        den = 1 ;
    }
    Fraction(int _num,int _den){
        num = _num;
        den = _den;
    }
    Fraction(int _num){
        num = _num;
        den = 1 ;
    }
    void setNum(int _num){
        num = _num;
        }
    int getNum(){
        return num;
    }
    void setDen(int _den){
        den = _den;
    }
    int getDen(){
        return den;
    }
    void print(){
        cout << num << "/" << den ;
         }
    Fraction operator+(Fraction n){
        Fraction res;
        res.num = num * n.den + n.num * den ;
        res.den = den * n.den;
        return res;
    }

};
int main()
{
    Fraction number1(10,20);
    Fraction number2(5,10);
    Fraction number3(10);
    Fraction number4;
    number1.print();
    cout<<endl;
    number3.print();
    cout<<endl;
    number4.print();
    cout<<endl;
    Fraction num4= number1+number2;
    num4.print();

    return 0;
}
