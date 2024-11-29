#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
class Publication{
protected:
    char* title;
    float price;
public:
    Publication() {
        title = new char[100];
    }
    void setTitle(char* _title){
        strcpy(title,_title);
    }
    char* getTitle(){
        return title;
    }
    virtual void getdata() {
        cout << "Enter title: ";
        cin>>title;
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
    virtual ~Publication(){
        delete[] title;
    }

};
class Book : public Publication{
    int pageCount;
public:
    void getdata(){
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putdata(){
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};
class Tape : public Publication{
    float time;
public:
    void getdata(){
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> time;
    }
    void putdata(){
        Publication::putdata();
        cout << "Playing Time: " << time << " minutes" << endl;
    }
};
int main()
{
    Book b;
    Tape t;
    Publication* ptrb=&b;
    Publication* ptrt=&t;
    cout << "Enter details for Book:\n";
    ptrb->getdata();
    cout << "\nEnter details for Tape:\n";
    ptrt->getdata();
    cout << "\nDetails of Book:\n";
    ptrb->putdata();
    cout << "\nDetails of Tape:\n";
    ptrt->putdata();
    return 0;
}
