#include <stdio.h>
int main()
{   int *ptr[60];
    printf("enter the no. of elements\n");
    int n;
    scanf("%d", &n);
    int var[60];
    printf("enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &var[i]);
    }
   
    for (int i = 0; i < n; i++)
    {
        ptr[i] = &var[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d= value,%d=address\n",*(ptr[i]),ptr[i]);
    }
}































// #include<stdio.h>



// int main()

// {

// int *arr[3];

// int p = 40, q = 60, r = 90, i;

// arr[0] = &p;

// arr[1] = &q;

// arr[2] = &r;

// for(i = 0; i < 3; i++)

// {

// printf("For the Address = %d  the Value would be = %d  ", arr[i], *arr[i]);

// }

// return 0;

// }