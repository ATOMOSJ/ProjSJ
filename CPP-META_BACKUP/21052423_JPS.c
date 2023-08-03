#include<stdio.h>
int main()
{
    int num[20];
    int i,j,a,n;
    printf("enter the elements\n");
    scanf("%d",&n);
    printf("fill the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(num[i]>num[j]){
                a=num[i];
                num[i]=num[j];
                num[j]=a;
            }
        }
    }
    printf("the sorted array is\n");
    for(i=0;i<n;i++){
        printf("%d\n",num[i]);
    }
}