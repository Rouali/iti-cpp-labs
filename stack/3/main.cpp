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
        Stack operator+(Stack s){
        Stack res;
        res.size = size + s.size;
        for(int i=0;i<=tos;i++){
                res.Push(arr[i]);
            }
        for(int j=0;j<=s.tos;j++){
                res.Push(s.arr[j]);
            }
        return res;
    }
};

int main()
{
    Stack s1,s2,s3;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s2.Push(50);
    s2.Push(60);
    s2.Push(70);
    s2.Push(80);
    s3=s1+s2;
    cout<<endl;
    int x;
    if (s3.Pop(x)==1)
        cout<<x;
    return 0;
}
