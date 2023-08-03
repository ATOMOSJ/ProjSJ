#include<stdio.h>
int main()
{
    int n,i,a,b,c=0;
    printf("enter the size\n");
    scanf("%d",&n);
    printf("enter array");
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    } 
    printf("enter the lower and upper limit\n");
    scanf("%d %d",&a,&b);
    for(i=0;i<n;i++){
        if(arr[i]==a || arr[i]==b){
            c++;
            
        }
        if(arr[i]>a && arr[i]<b){
            c++;
        }
    }
     printf("the no. between these inclusive elements is = %d",c);
        return 0;
}