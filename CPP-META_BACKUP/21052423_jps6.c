#include<stdio.h>
void NGE(int arr[],int n){
    int next,i,j;
    for(i=0;i<n;i++){
        next=-1;
        for (j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                next=arr[j];
                break;
            }
        }
        printf("%d -->\t %d",arr[i],next);
    }
}
int main()
{
    int arr[]={2, 5, 3, 9, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    NGE(arr,n);
    return 0;
}