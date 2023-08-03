#include <iostream>
using namespace std;
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
         << even<<endl;
    cout << "odd sum:" << odd<<endl;
}
int main()
{
    cout<<"enter the no of elements\n";
    int n;
    cin>>n;
    int*p=new int[n];
    cout<<"enter the element of array\n";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"the elements of the array are\n";
    for(int i=0;i<n;i++){
        cout<<p[i];
    }
    oe(p,n);
}