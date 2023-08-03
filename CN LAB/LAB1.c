#include<stdio.h>
#include<stdlib.h>
void Swapf(int n,int i);
void Swapp(int *p1,int *p2);
int main(int x , char *y[]){
    
    int a=atoi(y[1]);
    int b = atoi(y[2]);      

    Swapp(&a,&b);
    printf("%d %d",a,b);
    return 0;

}
//swap using pointer (call by address)
void Swapp(int *p1,int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
