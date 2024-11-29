#include <iostream>

using namespace std;
class Point{
    int x,y;
public:
    Point() {
        x=y=0;
    }
    Point(int _x) {
        x=y=_x;
    }
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
    void setX(int _x) {x=_x;}
    void setY(int _y) {y=_y;}
    int getX() {return x;}
    int getY() {return y;}
    void print(){
        cout<<endl<<"("<<x<<","<<y<<")";
    }
    ~Point() {
        cout<<endl<<"point deleted.";
    }
};
class Rect{
     Point* UL;
     Point* LR;
public:
    Rect(){
        UL = NULL;
        LR = NULL;
        cout << "rectangle created" << endl;
    }
    Rect(Point* _UL,Point* _LR){
        UL =_UL;
        LR = _LR;
    }
    void setUL(Point* _ul){UL =_ul;}
    Point* getUL(){return UL;}
    void setLR(Point* _lr){LR =_lr;}
    Point* getLR(){return LR;}
    void setUL(int x1,int y1){
        UL->setX(x1);
        UL->setY(y1);
    }
    void setLR(int x2,int y2){
        LR->setX(x2);
        LR->setY(y2);
    }
    void print(){
        UL->print();
        cout << " ";
        LR->print();
    }
    ~Rect(){
        delete UL;
        delete LR;
        cout<<endl<<"rectangle destroyed.";
    }
};

int main()
{
    Point p1(10,20);
    Point p2(5,20);
    Rect r1(&p1,&p2);
    r1.print();
    return 0;
}
