#include <stdio.h>
int nonzero(int n, int (*ptr)[n])
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (ptr[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}
int sum(int n, int (*ptr)[n])
{
    int i, j, sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
            {
                sum += ptr[i][j];
            }
        }
    }
    return sum;
}
void display(int n, int (*ptr)[n])
{
    int i, j;
    printf("\nAll elements below minor diagonal: ");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (j >= (n - i) && j < n)
            {
                printf("%d ", ptr[i][j]);
            }
        }
    }
}
int productdiagonal(int n, int (*ptr)[n])
{
    int i, j, product = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                product *= ptr[i][j];
            }
        }
    }
    return product;
}
int main()
{
    int i, j, n;
    printf("What is the order of the matrix--> ");
    scanf("%d", &n);
    int a[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            printf("element in[%d][%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }



    printf("\nTotal number of non zero elemenets is %d.\n", nonzero(n, a));
    printf("\nSum of elements above leading diagonal is %d.\n", sum(n, a));
    display(n, a);
    printf("\n\nThe product of all diagonal elements is %d.", productdiagonal(n, a));
    return 0;
}