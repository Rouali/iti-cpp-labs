#include <iostream>

using namespace std;
class Stack{
    int size;
    int* arr;
    int tos;
    public:
        Stack(){
        tos=-1;
        size=5;
        arr=new int[size];
        }
        Stack(int _size){
            size=_size;
            tos=-1;
            arr=new int[size];
            }
        Stack(Stack& s){
            tos=s.tos;
            size=s.size;
            arr=new int[size];
            for(int i=0;i<=tos;i++){
                arr[i]=s.arr[i];
            }
        }
        void Push(int d){
        if(tos < size-1){
            tos++;
            arr[tos]=d;
        }
        else
            cout<<"\n stack is full";
        }
        int Pop(int& d){
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
        ~Stack(){
            cout<<"\n destructor";
            delete[] arr;
        }
        Stack operator = (Stack& s){
            tos=s.tos;
            size=s.size;
            delete[] arr;
            arr=new int[size];
            for(int i=0;i<=tos;i++){
                arr[i]=s.arr[i];
            }
            return *this;
        }
};

int main()
{
    Stack s1;
    s1.Push(10);
    s1.Push(40);
    s1.Push(30);
    s1.Push(20);
    Stack s2;
    s2=s1;
    cout<<endl;
    int x;
    if (s2.Pop(x)==1)
        cout<<x;
    return 0;
}
