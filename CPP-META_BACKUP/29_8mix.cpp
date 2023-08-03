#include <iostream>
using namespace std;
void sum(int q[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += q[i];
    }
    cout << "the total sum is" << sum;
}
void find(int q[], int t, int m)
{
    for (int i = 0; i < t; i++)
    {
        if (q[i] == m)
        {
            cout << "the element\n " << m << "at pos is\n"
                 << i + 1;
        }
        else
        {
            cout << "not found\n";
        }
    }
}
void oe(int q[], int m)
{
    int i, even = 0, odd = 0;
    for (i = 0; i < m; i++)
    {
        if (q[i] % 2 == 0)
        {
            even += q[i];
        }
        else
        {
            odd += q[i];
        }
    }
    cout << "sum even:"
         << even << endl;
    cout << "odd sum:" << odd << endl;
}
void mul(int q[], int m, int r)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        q[i] *= r;
    }
    for (i = 0; i < m; i++)
    {
        cout << "the multiplication is:\t" << q[i];
        cout << "\n";
    }
}
void sort(int num[], int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (num[i] > num[j])
            {
                a = num[i];
                num[i] = num[j];
                num[j] = a;
            }
        }
    }
    cout << "the sorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << num[i];
    }
}
void rev(int y[], int l)
{
    int i;
    cout << "the reverse order is:" <<"\n";
    for (i = l - 1; i >= 0; i--)
    {
        cout << y[i];
        cout<<"\n";
    }
}
int merge(int s[], int e[], int x[], int f, int u)
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
    cout << "enter the elements for 2nd array"<<endl;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << "the programme is  applicable for the merge of 1st and 2nd array exclude merge \n";
    int el;
    cout << "enter the search element" << endl;
    cin >> el;
    int inti;
    cout << "enter the integer you want to multiply" << endl;
    cin >> inti;
    cout << "\n";
    merge(a, b, c, n, m);
    cout << "\n";
    find(c, n+m, el);
    cout << "\n";
    sort(c, n+m);
    cout << "\n";
    rev(c, n+m);
    cout << "\n";
    sum(c, n+m);
    cout << "\n";
    oe(c, n+m);
    cout << "\n";
    mul(c, n+m, inti);
    delete a;
    delete b;
    delete c;
    return 0;
}