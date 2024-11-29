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
};
void myfunc(Stack s){
    s.Push(10);
    s.Push(20);
    int x;
    s.Pop(x);
    cout<<endl<<x;
    s.Pop(x);
    cout<<endl<<x;
}

int main()
{
    int size;
    cout<<"Enter size";
    cin>>size;
    Stack s2(size);
    s2.Push(10);
    s2.Push(40);
    s2.Push(30);
    s2.Push(20);
    myfunc(s2);
    int x =0;
     if(s2.Pop(x)==1)
        cout<<endl<<x;
    if(s2.Pop(x)==1)
        cout<<endl<<x;

    return 0;
}
