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
class Sales {
protected:
    float sales[3];

public:
    void getdata(){
        cout << "Enter sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << (i + 1) << " sales: $";
            cin >> sales[i];
        }
    }
    void putdata(){
        cout << "Sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << (i + 1) << ": $" << sales[i] << endl;
        }
    }
};
class Book : public Publication, public Sales{
    int pageCount;
public:
    void getdata(){
        Publication::getdata();
        Sales::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }
    void putdata(){
        Publication::putdata();
        Sales::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};
class Tape : public Publication, public Sales{
    float time;
public:
    void getdata(){
        Publication::getdata();
        Sales::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> time;
    }
    void putdata(){
        Publication::putdata();
        Sales::putdata();
        cout << "Playing Time: " << time << " minutes" << endl;
    }
};
int main()
{
    Book b;
    Tape t;
    cout << "Enter details for Book:\n";
    b.getdata();
    cout << "\nEnter details for Tape:\n";
    t.getdata();
    cout << "\nDetails of Book:\n";
    b.putdata();
    cout << "\nDetails of Tape:\n";
    t.putdata();
    return 0;
}
