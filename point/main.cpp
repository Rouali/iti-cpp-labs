#include <iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
    Point(){
        x=y=0;
        cout<<"\n point CTOR";
    }
    Point(int _x){
        cout<<"\n point CTOR";
        x=y=_x;
    }
    Point(int _x,int _y){
        x=_x;
        y=_y;
        cout<<"\n point CTOR";
    }
    void setX(int _x){
        x=_x;
    }
    int getX(){
        return x;
    }
    void setY(int _y){
        y=_y;
    }
    int getY(){
        return y;
    }
    void print(){
        cout<<"\n("<<x<<","<<y<<")";
    }
    ~Point(){
        cout<<"\n destructor";
    }
};
class Rect{
    Point UL;
    Point LR;
public:
    Rect(){
        cout<<"Rect CTOR";
    }
    void setUL(Point _UL){
        UL=_UL;
    }
    Point getUL(){
        return UL;
    }
    void setLR(Point _LR){
        LR=_LR;
    }
    Point getLR(){
        return UL;
    }
    void setUL(int x, int y){
        UL.setX(x);
        UL.setY(y);
    }
    Rect(int x1,int y1,int x2,int y2):UL(x1,y1),LR(x2,y2){
        UL.setX(x1);
        UL.setY(y1);
        LR.setX(x2);
        LR.setY(y2);
    }
    void print(){
        UL.print();
        LR.print();
    }
    ~Rect(){
        cout<<"\n Rect destructor";
    }

};
class Circle{
    int radius;
    Point center;
public:
    Circle(){
        radius=1;
        center=0;
    }
    void setRadius(int _radius){
        radius=_radius;
    }
    int getRadius(){
        return radius;
        }
    void setCenter(Point _center){
        center=_center;
    }
    Point getCenter(){
        return center;
        }
    void print(){
        cout << "circle point is : ";
        center.print();
        cout << endl<< "radius is : ";
        cout << radius;
        }
    Circle(int x,int y,int r):center(x,y){
        radius = r;
    }

};
int main()
{
    Point p1(5);
    Point p2(5,6);
    p1.print();
    p2.print();
    Rect r1(10,20,3,40);
    r1.print();
    Circle c1(10,20,5);
    c1.print();
    return 0;
}
