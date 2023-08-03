#include <iostream>
using namespace std;
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
        cout<<"\n";
    }
   
}
int main()
{
    int n, t;
    cout << "enter the no of elements\t";
    cin >> n;
    cout << "enter the element you want to multiply with each element\t";
    cin >> t;
    int *p = new int[n];
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout<<"the elements you have entered";
     for(int i=0;i<n;i++){
        cout<<p[i];
    }
    mul(p,n,t);
}