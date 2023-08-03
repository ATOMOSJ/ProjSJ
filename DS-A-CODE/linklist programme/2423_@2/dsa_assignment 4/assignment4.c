#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int ar[100];
int n = sizeof(ar) / sizeof(ar[0]);
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selection(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int d;
    double time_compile = 0.0;
    int i, num, upper = 100000, lower = 0;
    srand(time(0));
    for (i = 0; i <= 100; i++)
    {
        num = (rand() % (upper - lower + 1) + lower);
        ar[i] = num;
    }
    printf("before\n");
    for (int j = 0; j <= 100; j++)
    {
        printf("%d\t", ar[j]);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // clock_t beign = clock();
    // bubble(ar, n);
    // sleep(1);
    // clock_t end = clock();
    // time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    // printf("after bubble sorting\n");
    // display(ar, n);
    // printf("The compile time is %lf milliseconds for bubble sort", time_compile * 1000);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // clock_t beign = clock();
    // insertionsort(ar, n);
    // sleep(1);
    // clock_t end = clock();
    // time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    // printf("after insertion sort\n");
    // display(ar, n);
    // printf("The elapsed time is %lf milliseconds for insertion sort", time_compile*1000);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // clock_t beign = clock();
    // selection(ar, n);
    // sleep(1);
    // clock_t end = clock();
    // time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    // printf("after selection sorting\n");
    // display(ar, n);
    // printf("The compile time is %lf milliseconds for selection sort", time_compile * 1000);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // clock_t beign = clock();
    // mergeSort(ar,0,n-1);
    // sleep(1);
    // clock_t end = clock();
    // time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    // printf("after merge sorting\n");
    // display(ar, n);
    // printf("The compile time is %lf milliseconds for merge sort", time_compile*1000 );
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    clock_t beign = clock();
    quickSort(ar, 0, n - 1);
    sleep(1);
    clock_t end = clock();
    time_compile += (double)(end - beign) / CLOCKS_PER_SEC;
    printf("after quick sorting\n");
    display(ar, n);
    printf("The compile time is %lf milliseconds for quick sort", time_compile * 1000);
}