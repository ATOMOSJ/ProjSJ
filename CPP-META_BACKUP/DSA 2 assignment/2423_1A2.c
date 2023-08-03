#include <stdio.h>
int main()
{
    int a[20], i, n;
    int *p=a;
    printf("enter the no. of elements\n");
    scanf("%d", &n);
    printf("enter the array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
    }
    printf("\n");
    printf("the array you entered is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\t");
        printf("%d", *(p + i));
    }
    return 0;
}