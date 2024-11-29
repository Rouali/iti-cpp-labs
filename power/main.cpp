#include <iostream>

using namespace std;
int power(int x,int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    return x*power(x,y-1);
}
int main()
{
    cout << power(2,5);
    return 0;
}
