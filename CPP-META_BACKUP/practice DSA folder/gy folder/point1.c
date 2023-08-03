#include<stdio.h>
int adr(int *p,int a){
    int *p=&a;
    printf("enter a single element\n");

scanf("%d",&a);
printf("the address the element you want is %x\n",&a);
printf("the address of the pointer is %p\n",p);
}
int main()
{
    // int a=2;
    // int*p=&a;
    // int**c=&p;
    // int*l=&c;
    int ar[100],n,i,k;
    int *u,z;
    printf("enter the no. of element\n");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<=n-1;i++){
        printf("diplaying Array a[%d] is at position %d \n",ar[i],i);
    }
    printf("\n");
    printf("enter the index of the element you want to find the address of \n");
    scanf("%d",&i);
    printf("the element at this place is [%d] and the adress for it is given as %u and %x in hexadecimal\n",ar[i],&ar[i],&ar[i]);
   k=adr(*u,&z);
   printf("the value you got is %d",k);


    // printf("enter the index get address of\n");
    // scanf("enter the no.= %d",&i);

    // printf("%d\n",*p+1);
    // printf("%d\n",p+1);
    // printf("%d\n",&a+1);
    // printf("%d\n",**c);
    // printf("%u\n",l);
    // printf("%d\n",&c);
    // printf("%d\n",&a);

     return 0;
}
