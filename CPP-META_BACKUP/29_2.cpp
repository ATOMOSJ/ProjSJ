#include <iostream>
using namespace std;
void find(int q[],int t, int m){
    for (int i = 0; i < t; i++)
    {
        if (q[i] == m)
        {
            cout << "the element\n " <<m <<"at pos is\n"<< i + 1 ;
        }else{
        cout << "not found\n";
        }
    }
}
int main()
{
    int n;
    cout << "enter the size of array\n";
    cin >> n;
    int*ar=new int[n];
    cout << "enter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
    }
    cout << "\n";
    int el;
    cout << "enter the element you want to search\n";
    cin >> el;
    find(ar,n,el);
    
    
    return 0;
}
