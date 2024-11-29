#include <iostream>
using namespace std;
class Queue{
    int* arr;
    int size;
    int top;
public:
    Queue(int _size = 5){
        size = _size;
        arr = new int[size];
        top = -1;
    }
    void enQueue(int d){
        if(top < size-1){
            top++;
            arr[top] =d;
        }
        else
            cout<<"\n Queue is full";
    }
    int deQueue(int &d){
        if(top != -1){
            d = arr[0];
            for(int i = 0 ; i < top ; i++)
                arr[i]=arr[i]+1;
            top--;
            return 1;
        }
        cout<<"\n Queue is empty";
        return 0;
    }
    int isEmpty(){
        return top == -1;
    }
    int isFull(){
        return top == size-1;
    }

};
int main()
{
    Queue q1(3);
    q1.enQueue(10);
    q1.enQueue(11);
    q1.enQueue(12);
    q1.enQueue(13);
    int x;
    if (q1.deQueue(x)==1)
        cout<<endl<<x;
    if (q1.deQueue(x)==1)
        cout<<endl<<x;
    if (q1.deQueue(x)==1)
        cout<<endl<<x;
    if (q1.deQueue(x)==1)
        cout<<endl<<x;
    return 0;
}
