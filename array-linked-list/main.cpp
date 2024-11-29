#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
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
class Array{
    LinkedList* arr;
    int size;
public:
    Array(int _size = 5){
        size = _size;
        arr = new LinkedList[size];
    }
    void add(int index, int id, char* name, int age) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        arr[index].append(id, name, age);
    }
    void print() {
        for (int i = 0 ; i < size ; i++) {
            cout <<endl<<"LinkedList at index " << i << ":";
            arr[i].display();
            cout << endl;
        }
    }
    ~Array() {
        delete[] arr;
    }
};
int main()
{
    Array a1(5);
    a1.add(0,1,"rawan",22);
    a1.add(1,2,"ali",50);
    a1.add(1,5,"mohammad",29);
    a1.add(2,3,"mariam",22);
    a1.add(2,4,"sara",22);

    a1.print();
    return 0;
}
