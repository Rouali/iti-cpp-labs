#include <iostream>
using namespace std;
class Shape{
protected:
    int dim1;
    int dim2;
public:
    Shape(){
        dim1 = dim2 = 0;
    }
    Shape(int _dim1){
        dim1 = _dim1;
        dim2 = _dim1;
    }
    Shape(int _dim1,int _dim2){
        dim1 = _dim1;
        dim2 = _dim2;
    }
    virtual void setDim1(int _dim1){
        dim1 = _dim1;
    }
    virtual void setDim2(int _dim2){
        dim2 = _dim2;
    }
    virtual float calcArea() = 0;
};
class Rect : public Shape{
public:
    Rect():Shape(){
    }
    Rect(int _dim1):Shape(_dim1){
    }
    Rect(int _dim1,int _dim2):Shape(_dim1,_dim2){
    }
    float calcArea(){
        return dim1*dim2;
    }
};
class Square : public Rect{
public:
    Square():Rect(){
    }
    Square(int _dim1):Rect(_dim1){
    }
    void setDim1(int _dim1){
        dim1=dim2=_dim1;
    }
    void setDim2(int _dim2){
      dim1=dim2=_dim2;
    }
};
class Circle : public Shape{
public:
    Circle(int _dim1):Shape(_dim1){
    }
    void setDim1(int _dim1){
        dim1 = dim2 = _dim1;
    }
    void setDim2(int _dim1){
        dim1 = dim2 = _dim1;
    }
    float calcArea(){
        return 22/7*dim1*dim2;
    }
};
class Traingle : public Shape{
public:
    Traingle(int _dim1,int _dim2):Shape(_dim1,_dim2){
    }
    float calcArea(){
        return 0.5*dim1*dim2;
    }
};
int myfunc(Shape* arr[],int s){
    int sum=0;
    for(int i = 0 ; i < s ; i++ )
        sum += arr[i]->calcArea();
    return sum;
}
void shapeArea(Shape* s){
    cout<<s->calcArea();
}
int main()
{
    Rect r1(10,20);
    Shape* ptrr = &r1;
    cout<<ptrr->calcArea()<<endl;
    ptrr->setDim1(5);
    cout<<ptrr->calcArea()<<endl;

    Circle c1(10);
    Shape* ptrc = &c1;
    cout<<ptrc->calcArea()<<endl;

    Traingle t1(5,10);
    Shape* ptrt = &t1;
    cout<<ptrt->calcArea()<<endl;
    shapeArea(&t1);

    Square s1(5);
    Shape* ptrs = &s1;
    cout<<endl<<ptrs->calcArea()<<endl;

    Shape* arr[4]={&r1,&c1,&t1,&s1};
    cout<<myfunc(arr,4);
    return 0;
}
