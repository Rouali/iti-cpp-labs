#include <iostream>

using namespace std;
class Stack{
    int size;
    int arr[5]={0};
    int tos;
    public:
        Stack(){
        tos=-1;
        size=5;
        }
        void Push(int d){
        if(tos < size-1){
            tos++;
            arr[tos]=d;
        }
        else
            cout<<"\n stack is full";
        }
        int pop(int& d){
            if(tos != -1){
                d =arr[tos];
                tos--;
                return 1;
            }
            else{
                cout<<"\n stack is empty";
                return 0;
            }
        }
};

int main()
{
    Stack s1;
    s1.Push(10);
    s1.Push(40);
    s1.Push(30);
    s1.Push(20);
    int x =0;
    if(s1.pop(x)==1)
        cout<<endl<<x;
    if(s1.pop(x)==1)
        cout<<endl<<x;
    return 0;
}
