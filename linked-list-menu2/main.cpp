#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
#define row 5
#define col 20
#define null -32
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
    char name[30];
    int age;
    node* prev;
    node* next;
};
class LinkedList{
    node* head;
    node* tail;
    node* searchbyidpriv(int id){
        node* temp = head;
        while(temp!=NULL){
            if(id == temp->id)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    node* searchbynamepriv(char* name){
        node* temp = head;
        while( temp != NULL ){
            if(strcmp(name ,temp->name) == 0)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
public:
    LinkedList(){
        head = tail = NULL;
        }
    LinkedList(LinkedList& l){
        head = tail = NULL;
        node* temp = l.head;
        while(temp != NULL){
            append(temp->id,temp->name,temp->age);
            temp = temp->next;
        }
    }
    LinkedList& operator=(const LinkedList& l) {
        if (this != &l) {
            this->~LinkedList();
            head = tail = NULL;
            node* temp = l.head;
            while (temp != NULL) {
                append(temp->id, temp->name, temp->age);
                temp = temp->next;
            }
        }
        return *this;
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
    int count(){
        int c = 0;
        node* temp = head;
        while(temp!=NULL){
            c++;
            temp = temp -> next;
        }
        return c;
    }
    node searchbyid(int id){
        node* resadd = searchbyidpriv(id);
        node res;
        if(resadd != NULL){
            res.next = NULL;
            res.prev = NULL;
            res.id = resadd->id;
            strcpy(res.name,resadd->name);
            res.age = resadd -> age;
        }
        else
            res.id=-1;
        return res;
    }
    node searchbyname(char* name){
        node* resadd = searchbynamepriv(name);
        node res;
        if(resadd != NULL){
            res.next = NULL;
            res.prev = NULL;
            res.id = resadd -> id;
            strcpy(res.name,resadd->name);
            res.age = resadd->age;
        }
        else
            strcpy(res.name,NULL);
        return res;
    }
    void updateByID(int id){
        node* nodeUpdate = searchbyidpriv(id);
        if (nodeUpdate==NULL)
        {
            cout<<"member with this ID "<<id<<" not found.\n";
            return;
        }
        cout<<"Current Name: "<<nodeUpdate->name<<"\n";
        cout<<"Enter New Name: ";
        cin>>nodeUpdate->name;
        cout<<"Current Age: "<<nodeUpdate->age<<"\n";
        cout<<"Enter New Age: ";
        cin>>nodeUpdate->age;
    }
    void insertbyid(int id,char* name,int age,int existingid){
        if(head==NULL){
            append(id,name,age);
            return;
        }
        node* res = searchbyidpriv(existingid);
        if(res==tail)
            append(id,name,age);
        else{
            node* temp = new node;
            temp -> id = id;
            temp -> age = age;
            strcpy(temp->name , name);
            temp->prev = res;
            temp->next = res->next;
            res->next = temp;
            temp->next->prev=temp;
        }
    }
    void deletebyid(int id){
        node* res = searchbyidpriv(id);
        if(res == NULL)
            return;
        if(head == tail)
            head=tail=NULL;
        delete res;
    }
    void deletebyname(char* name){
        node* res = searchbynamepriv(name);
        if(res == NULL)
            return;
        if(head == tail)
            head=tail=NULL;
        delete res;
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
    LinkedList l1,l2;
    char menu[10][20]={"New","Display","Search by id","Search by name","Insert by id","delete by id","delete by name","Count","Update","Exit"};
    int n =0;
    int flag=0;
    int id,exid,i,age;
    char name[20];
    char ch;
   /* l2.append(1, "rawan", 22);
    l2.append(2, "ali", 50);
    l1=l2;
*/
     do{
        system("cls");

        for(i=0;i<10;i++){
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
                n=9;
            break;
            //down
        case 80:
            n++;
            if(n>9)
                 n=0;
            break;
            //enter
        case 13 :
            if(n==0){
                    system("cls");
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
                else if(n==2){
                    system("cls");
                    cout<<"Search by id : \nEnter Id:";
                    cin>>id;
                    node res = l1.searchbyid(id);
                    if(res.id !=-1)
                        cout<<res.id<<":"<<res.name<<":"<<res.age;
                    }
                else if(n==3){
                    system("cls");
                    cout<<"Search by name : \nEnter Name:";
                    cin>>name;
                    node res = l1.searchbyname(name);
                    if(res.name != NULL)
                        cout<<res.id<<":"<<res.name<<":"<<res.age;
                    }
                else if(n==4){
                    system("cls");
                    cout<<"Insert member :";
                    cout<<"enter id :";
                    cin>>id;
                    cout<<"enter name :";
                    cin>>name;
                    cout<<"enter age :";
                    cin>>age;
                    cout<<"check if id is exist:";
                    cin>>exid;
                    l1.insertbyid(id,name,age,exid);
                    }
                else if(n==5){
                    system("cls");
                    cout<<"Delete by ID : \nEnter ID:";
                    cin>>id;
                    l1.deletebyid(id);
                    }
                else if(n==6){
                    system("cls");
                    cout<<"Delete by Name : \nEnter Name:";
                    cin>>id;
                    l1.deletebyname(name);
                    }
                else if(n==7){
                    system("cls");
                    cout<<"Count = ";
                   cout<<l1.count();
                }
                else if(n==8){
                    system("cls");
                    cout << "Enter ID to update: ";
                    cin >> id;
                    l1.updateByID(id);
                }
                else
                  flag = 1;
        _getch();
    }
    }while(flag==0);
    return 0;
}
