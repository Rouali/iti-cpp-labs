#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
  GetStdHandle( STD_OUTPUT_HANDLE ),
  coord
    );
  }
struct node{
    int id;
    int age;
    char name[30];
    node* prev;
    node* next;
};
class LinkedList{
    node* head;
    node* tail;
public:
    LinkedList(){
        head = tail = NULL;
        }
    void append(int id,char* name,int age){
        node* temp = new node();
        temp -> id = id;
        temp -> age = age;
        strcpy(temp->name , name);
        temp -> next = NULL;
        if(head == NULL){
            temp -> prev = NULL;
            head = tail = temp;
        }else{
            temp -> prev = tail;
            tail -> next = temp;
            tail = temp;
        }
    }
    void display(){
        node* temp = head;
        while(temp !=NULL){
            cout<<endl<<temp->id<<":"<<temp->name<<":"<<temp->age;
            temp = temp -> next;
        }
    }
    ~LinkedList(){
         node* temp = head;
         while(temp !=NULL){
            head=temp->next;
            delete temp;
            temp=head;
         }
         delete temp;
    }

};

int main()
{
    LinkedList l1;
    char menu[3][20]={"New","Display","Exit"};
    int n =0;
    int flag=0;
    int i;
    char ch;

     do{
        system("cls");

        for(i=0;i<3;i++){
            gotoxy(10,10+i);
            if(i==n)
                textattr(0x04);
        _cprintf("%s",menu[i]);
        textattr(0x07);
    }
    ch=_getch();
    switch(ch){
                //up
        case 72:
            n--;
            if(n<0)
                n=2;
            break;
            //down
        case 80:
            n++;
            if(n>2)
                 n=0;
            break;
            //enter
        case 13 :
            if(n==0){
                    system("cls");
                    int id;
                    char name[20];
                    int age;
                    cout<<"enter id :";
                    cin>>id;
                    cout<<"enter name :";
                    cin>>name;
                    cout<<"enter age :";
                    cin>>age;
                    l1.append(id,name,age);
                }
                else if(n==1){
                    system("cls");
                    l1.display();
                    }
                else
                  flag = 1;
        _getch();
    }
    }while(flag==0);
    return 0;
}
