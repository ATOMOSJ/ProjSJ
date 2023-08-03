// Write a program to demonstrate the concept of call-by-value, call-by-reference & call-by-
// address by taking swapping of two numbers as an example.
#include <iostream>
using namespace std;
int swapcbv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << "b=" << b;
}
int swapcbr(int &e, int &f)
{
   int temp;
   temp=e;
   e=f;
   f=temp;
    cout << "a=" << e << "b=" << f;
}
int swapcba(int *c, int *d)
{
    int temp;
    temp = *c;
    *c = *d;
    *d = temp;
    cout << "a=" << *c << "b=" << *d;
}

int main()
{
    int x, y;
    cout << "enter the integers to swap" << endl;
    cin >> x >> y;  
    swapcbv(x, y);
    cout << "\n";
    swapcbr(x, y);
    cout << "\n";
    swapcba(&x, &y);
}
