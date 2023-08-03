#include <stdio.h>
int main()
{
    int ar[50], i, n, pos = 0, neg = 0;
    int *p;
    p = ar;
    printf("enter the no of elements\n");
    scanf("%d", &n);
    printf("enter your elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }
    for (i = 0; i < n; i++)
    {
        if (*(p+i) >= 0)
        {
            pos++;
        }
        else{
        

            neg++;
        }
    }
    printf("the positive are %d \n the negetive are %d",pos,neg);
}