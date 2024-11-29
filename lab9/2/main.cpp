#include <iostream>
#include <string.h>

using namespace std;

class Emp
{
    int id;
    char name[30];
    int age;
    int salary;
public:
    void setId(int _id)
    {
        id=_id;
    }
    void setName(char _name[30])
    {
        strcpy(name,_name);
    }
    void setAge(int _age)
    {
        age=_age;
    }
    void setSalary(int _salary)
    {
        salary=_salary;
    }
    int getId()
    {
        return id;
    }
    char *getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getsalary()
    {
        return salary;
    }
    void print(){
        cout<<endl<<id<<":"<<name<<":"<<age<<":"<<salary<<endl;
    }
    Emp(int _id, char _name[30])
    {
        id=_id;
        strcpy(name,_name);
        age=30;
        salary=2000;
    }
    Emp(int _id, char _name[30],int _age)
    {
        id=_id;
        strcpy(name,_name);
        age=_age;
        salary=2000;
    }
    Emp(int _id, char _name[30],int _age,int _salary)
    {
        id=_id;
        strcpy(name,_name);
        age=_age;
        salary=_salary;
    }

    ~Emp()
    {
        cout<<"\nTHIS IS THE DESTRUCTOR ";
    }
};
void print(Emp e);
int main()
{
    Emp e1(1,"rawan",22);
    Emp e2(2,"ali",50,5000);
    e1.print();
    e2.print();
    return 0;
}
