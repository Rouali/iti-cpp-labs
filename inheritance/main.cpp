#include <iostream>
#include <string.h>
using namespace std;
class Person{
protected:
    int id;
    int age;
    char name[30];
public:
    void setId(int _id){
        id = _id;
    }
    int getId(){
        return id;
    }
    void setAge(int _age){
        age = _age;
    }
    int getAge(){
        return age;
    }
    void setName(char* _name){
        strcpy(name,_name);
    }
    char* getName(){
        return name;
    }
    void print(){
        cout<<"person data :"<<endl<<"id : "<<id<<" , name : "<<name<<" , age : "<<age<<endl;
    }
    Person(){
        id = 0;
        age = 0;
        strcpy(name,"no name");
    }
    Person(int _id){
        id = _id;
        age = 0;
        strcpy(name,"no name");
    }
    Person(int _id,int _age){
        id = _id;
        age = _age;
        strcpy(name,"no name");
    }
    Person(char* _name){
        strcpy(name,_name);
        id = 0;
        age = 0;
    }
    Person(int _id,char* _name,int _age){
        id = _id;
        age = _age;
        strcpy(name,_name);
    }
    ~Person(){
        cout<<"\ndestructor";
    }
};
class Emp:public Person{
    int salary;
public:
    void setSalary(int _salary){
        salary = _salary;
    }
    int getSalary(){
        return salary;
    }
    Emp(int _id,char* _name,int _age,int _salary):Person(_id,_name,_age){
       salary = _salary;
    }
    void print(){
         cout<<"Employee data :"<<endl<<"id : "<<id<<" , name : "<<name<<" , age : "<<age<<" , salary : "<<salary<<endl;
    }
    ~Emp(){
        cout<<"\ndestructor";
    }
};
class Student:public Person{
    int grade;
public:
    void setGrade(int _grade){
        grade = _grade;
    }
    int getGrade(){
        return grade;
    }
    Student(int _id,char* _name,int _age,int _grade):Person(_id,_name,_age){
      grade = _grade;
    }
    void print(){
         cout<<"Student data :"<<endl<<"id : "<<id<<" , name : "<<name<<" , age : "<<age<<" , grade : "<<grade<<endl;
    }
    ~Student(){
        cout<<"\ndestructor";
    }
};
void myfunc(Person e1){
    e1.print();
}
int main()
{
    Person p1(1);
    Person p2(2,"rawan",22);
    p1.print();
    p2.print();

    Emp e1(3,"ali",50,2000);
    e1.print();

   Student s1(4,"mariam",22,95);
   s1.print();

    return 0;
}
