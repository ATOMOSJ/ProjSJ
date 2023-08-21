#include <stdio.h>
int arrC(int arr[],int n);
int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int s = sizeof(arr)/sizeof(arr[0]);
    printf("your max sum is: %d\n",arrC(arr,s));
}
int arrC(int arr[],int n)
{
    int upto =arr[0];
    int till =arr[0];
    for (int i = 1; i < n; i++)
    {
        upto = upto + arr[i]>arr[i]?upto + arr[i] :arr[i];
        till =till>upto?till:upto;
    }
    return till;
}