#include <stdio.h>
#include <stdlib.h>

int main()
{
 int y=30;
 int* ptr=&y;
 scanf("%d",ptr);
 printf("%d",y);
 return 0;
}
