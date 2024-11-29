#include <iostream>
#include <string.h>
using namespace std;
class String{
    int size;
    char* str;
public:
    void setValue(char* _str) {
        if (strlen(_str) + 1 > size) {
            delete[] str;
            size = strlen(_str) + 10;
            str = new char[size + 1];
        }
        strcpy(str,_str);
    }
    char* getValue(){
        return str;
    }
    String() {
        size=10;
        str=new char[size + 1];
        str[0]='\0';
    }
    String(int _size) {
        size = _size;
        str = new char[size + 1];
        str[0] = '\0';
        }
    String(char* _str) {
        size = strlen(_str) + 10;
        str = new char[size + 1];
        strcpy(str,_str);
    }
    String(const String& s) {
        size = s.size;
        str = new char[size + 1];
        strcpy(str,s.str);
    }
    void print() const {
        cout << str <<endl;
    }
    String operator=(String& s) {
        delete[] str;
        size = s.size;
        str = new char[size];
        strcpy(str, s.str);
        return *this;
    }
    String operator+(String& s) {
        String res;
        res.size = this->size + s.size;
        res.str = new char[res.size + 1];
        strcpy(res.str, this->str);
        strcat(res.str,s.str);
        return res;
    }
    ~String(){
        delete[] str;
    }
};
int main()
{
    String s1,s3;
    s1.print();
    s1.setValue("rawan");
    s1.print();
    String s2("ali");
    s2.print();
    s3 = s1;
    s3.print();
    String s4 = s1 + s2;
    s4.print();


    return 0;
}
