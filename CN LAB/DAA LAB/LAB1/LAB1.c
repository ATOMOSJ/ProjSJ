// Write a program to find out the second smallest and second largest
// element stored in an array of n integers.
#include <stdio.h>
#include <stdlib.h>
void checkar(int arr[], int n)
{
    if (n < 2)
    {
        printf("The array doesn't contain 2 elements");
        return;
    }
    int sn = arr[0];
    int ln = arr[0];
    int ssn = arr[1];
    int sln = arr[1];
    for (int i = 2; i < n; i++)
    {
        if (arr[i] < sn)
        {
            ssn = sn;
            sn = arr[i];
        }
        else if (arr[i] < ssn)
        {
            ssn = arr[i];
        }

        if (arr[i] > ln)
        {
            sln = ln;
            ln = arr[i];
        }
        else if (arr[i] > sln)
        {
            sln = arr[i];
        }
    }

    printf("Second Smallest: %d\n", ssn);
    printf("Second Largest: %d\n", sln);
}
int main()
{
    int n = 15;
    int arr[15];
    for (int i = 0; i < n; i++)
    {
        // rand()%100 means it genrate no. between 0 and 99
        arr[i] = rand() % 10;
    }
    checkar(arr, n);
    return 0;
}
