#include <iostream>
using namespace std;
int sum(int a, int b)
{
    int c = a + b;
    cout << c;
}
int sum(int a, int b, int c)
{
    int d = a + b + c;
    cout << d;
}
int sum(int a, int b, int c, int d)
{
    int e = a + b + c + d;
    cout << e;
}
int main()
{
    sum(4, 5);
    cout << "\n";
    sum(4, 6, 7);
    cout << "\n";
    sum(3, 4, 5, 6);
}