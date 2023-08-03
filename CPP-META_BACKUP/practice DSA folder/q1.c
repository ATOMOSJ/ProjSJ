#include<stdio.h>
int main()
{
    int a=8;
    int*p=&a;
printf("%d\n",&p);
printf("%p",&p);
printf("%d\n",*p);
printf("%x\n",&a);
printf("%d\n",p);


     return 0;
}