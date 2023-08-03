#include<stdio.h>
typedef struct date{
    int day;
    int mon;
    int yr;
}date;
void display(int a,int b,int d){
    printf("------>YOUR BIRTHDAY<------\n");
    printf("day= %d\n",a);
    printf("month= %d\n",b);
    printf("year= %d",d);

}
int main(){
date d= {9,10,2003};
display(d.day,d.mon,d.yr);

}
