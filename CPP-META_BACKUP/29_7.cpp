#include <iostream>
using namespace std;
void merge(int s[], int e[], int x[], int f, int u)
{
    int i = 0, j;
    for (j = 0; j < f; j++)
    {
        x[i] = s[j];
        i++;
    }
    for (j = 0; j < u; j++)
    {
        x[i] = e[j];
        i++;
    }
    cout << "after merge" << endl;
    for (i = 0; i < f + u; i++)
    {
        cout << x[i];
    }
}
int main()
{
    int n, m;
    cout << "enter the size of both array" << endl;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    int *c = new int[n + m];
    cout << "enter the elements of 1st and second array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    merge(a, b, c, n, m);
    delete a;
    delete b;
    delete c;
}