#include <iostream>

using namespace std;
class Fraction{
    int numerator;
    int denominator;
public:
    Fraction(int _numerator=0,int _denominator=0){
        numerator = _numerator;
        denominator = _denominator;
    }
    void display(){
        cout<<numerator<<"/"<<denominator;
    }
    Fraction Add(const Fraction& f)const{
        int newNumerator = numerator * f.denominator + f.numerator * denominator;
        int newDenominator = denominator * f.denominator;
        return Fraction(newNumerator,newDenominator);
    }

};
int main()
{
    Fraction f1(10,5);
    Fraction f2(8,4);
    Fraction res = f1.Add(f2);
    cout << "Result of addition: ";
    res.display();
    return 0;
}
