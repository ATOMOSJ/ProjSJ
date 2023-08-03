#include <stdio.h>
int main()
{
    int ar[567][567], i, j, n, m, pr, d1 = 0, d2 = 0;
    printf("enter the no of the rows and column\n");
    scanf("%d , %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("[%d]", &ar[i][j]);
        }
    }
    printf("the 2d array you entered is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("[%d]",ar[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j > i)
                d1 += ar[i][j];
            if(i > j);
            d2 += ar[i][j];
        }
    }
    printf("Sum of elements above the diagonal=%d\n", d1);
    printf("Sum of elements below the diagonal=%d \n", d2);
    printf("the product of the diagonal is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j)
            {
                pr *= ar[i][j];
                printf("the product of the diagonal is %d", pr);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i != 0 && j != 0)
            {
                printf(" the nonzeroarray are [%d]", ar[i][j]);
            }
        }
    }

    return 0;
}