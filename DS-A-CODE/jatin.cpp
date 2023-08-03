#include <iostream>
using namespace std;

void sum(int p[], int q)
{
    int i,sum=0;
    for (i=0;i<q;i++)
    {
        sum += p[i];
    }
    cout <<"the total sum is:"<<sum<<endl;;
}
void find(int p[], int q, int f )
{
    int i;
    for (i=0;i<f; i++)
    {
        if (p[i] == q)
        {
            cout <<"the element:"<<q<<"at pos is:"<<i+1<<endl;
			return;
        }
    }
	cout<<"Not found in the array"<<endl;
}
void oe(int p[], int q)
{
    int i,e=0,o=0;
    for (i=0;i<q;i++)
    {
        if (p[i]%2 == 0)
        {
            e +=p[i];
        }
        else
        {
            o +=p[i];
        }
    }
    cout<<"Sum of even numbers:"<<e<< endl;
    cout<<"Sum of odd numbers:"<<o<<endl;
}
void multi(int p[], int q, int m)
{
    int i, j;
    for (i=0;i<q;i++)
    {
        p[i]*= m;
    }
    for (i=0;i<q;i++)
    {
        cout << "Value after Multiplication is:\t" << p[i]<<endl;
    }
}
void sort(int a[], int b)
{
    int i,j,t;
    for (i=0;i<b;i++)
    {
        for (j=i+1;j<b;j++)
        {
            if (a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    cout << "Sorted array: "<<endl;
    for (int i=0;i<b;i++)
    {
        cout<< a[i]<<" ";
    }
	cout<<endl;
}
void reverse(int a[], int r)
{
    int i;
    cout << "Reverse of array is:" <<"\n";
    for (i=r-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
	cout<<endl;
}
int merge(int a[], int b[], int c[], int x, int y)
{
    int j,i=0;
    for (j=0;j<x;j++)
    {
        c[i]=a[j];
        i++;
    }
    for (j=0;j<y;j++)
    {
        c[i]=b[j];
        i++;
    }
    cout << "Merged array" << endl;
    for (i=0;i<x+y;i++)
    {
        cout<<c[i]<<" ";
    }
	cout<<endl;
	return 0;
}
int main()
{
    int a1, a2;
    cout<< "Enter size of array 1" << endl;
    cin >>a1;
    cout<<"Enter size of array 2" << endl;
    cin >>a2;
    int *p = new int[a1];
    int *q = new int[a2];
    int *r = new int[a1+a2];
    int i;
    cout<<"Input Elements of 1st array"<<endl;
    for (i=0; i<a1; i++)
    {
        cin>>p[i];
    }
    cout << "Input elements of 2nd array"<<endl;
    for (i=0;i<a2;i++)
    {
        cin>>q[i];
    }
    int e;
    sum(r, a1+a2);
    cout << "\n";
    cout << "to find the element in only first array enter the search element" << endl;
    cin >> e;
    int inta;
    cout << "enter the integer you want to multiply" << endl;
    cin >> inta;
    cout << "\n";
    find(r, e, a1+a2);
    cout << "\n";
    oe(r, a1+a2);
    cout << "\n";
    multi(r, a1+a2, inta);
    cout << "\n";
    sort(r, a1+a2);
    cout << "\n";
    reverse(r, a1+a2);
    cout << "\n";
    merge(p, q, r, a1, a2);
}