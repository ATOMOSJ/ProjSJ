#include <stdio.h>
int main()
{
    int a[40], i, n, large, small;
    printf("enter the no. of elements");
    scanf("%d", &n);
    printf("now fill the array");
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    large = small = a[0];
    for (i = 1; i < n; ++i)
    {
        if (a[i] > large)  
            // large=a[0]
            large = a[i];
        if (a[i] < small)
            // small=a[0]
            small = a[i];
    }
    printf("the largest element %d", large);
    printf("\n thesmallest element is %d", small);
    return 0;
}
       
       
       
       
       
       
       
       
       
       
       
       
       
       
        //   ALgo 
// Input the array elements.
// Initialize small = large = arr[0]
// Repeat from i = 1 to n.
// if(arr[i] > large)
// large = arr[i]
// if(arr[i] < small)
// small = arr[i]
// Print small and large.