// // liner search
// #include <stdio.h>
// #include <stdlib.h>
// int search(int arr[], int xor, int x)
// {
//     for (int i = 0; i < xor; i++)
//
//         if (arr[i] == x)

//             return i;

//         return -1;
//
// }
// int main()
// {
//     int arr[50];
//     int i, n, x;
//     printf("enter your no. of elements\n");
//     scanf("%d", &n);
//     printf("now enter your elements\n");
//     int N = sizeof(arr) / sizeof(arr[0]);

//     for (i = 0; i < n - 1; i++)
//     {
//         scanf("%d\n", &arr[i]);
//     }

//     printf("enter the element you wanna search\n");
//     scanf("%d\n", &x);
//     int result = search(arr, N, x);
//     if (result == -1)
//     {
//         printf("element not found");
//     }
//     else
//     {
//         printf("element found");
//     }
//     return 0;
// }
// #include <stdio.h>

// int search(int arr[], int N, int x)
// {
//     int i;
//     for (i = 0; i < N; i++)
//         if (arr[i] == x)
//             return i;
//     return -1;
// }

// int main(void)
// {
//     int arr[] = { 2, 3, 4, 10, 40 };
//     int x = 10;
//     int N = sizeof(arr) / sizeof(arr[0]);
//     int result = search(arr, N, x);
//     (result == -1)
//         ? printf("Element is not present in array")
//         : printf("Element is present at index %d", result);
//     return 0;
// }
// binary search
// #include<stdio.h>
// int binarysearch(int arr[],int size,int element){
//     int mid, high,low;
//     low=0;
//     high=size-1;
//     while(low<=high){

//     mid=(low+high)/2;
//     if(arr[mid]==element){
//         return mid;
//     }if(arr[mid]<element){
//         low=mid+1;
//     }else{
//         high=mid-1;
//     }
//     }
//     return -1;
// }
// int main()
// {
//     int arr[] = { 2, 3, 4, 10, 40 };
//     int x = 10;
//     int N = sizeof(arr) / sizeof(arr[0]);
//     int result = binarysearch(arr, N, x);
//     if(result==-1){
//         printf("Element is not present in array");

//     }else{
//          printf("Element %d is present at index %d",x, result);

//     }
//     return 0;
// }
// bubble sort
#include <stdio.h>
void printfarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void bubbleSortAdaptive(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
    } 
}
int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = 11;
    printfarray(a, n);
    bubbleSortAdaptive(a,n);
    printfarray(a, n);

    return 0;
}
