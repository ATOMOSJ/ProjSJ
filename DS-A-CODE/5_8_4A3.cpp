#include <iostream>
using namespace std;
int funarea(int r)
{
    int cir;
    cir = 3.14 * (r * r);
    cout << "the circle area is:" << cir << endl;
}
int funarea(int l, int b)
{
    int rec;
    rec = l * b;
    cout << "the area of the reactangle is" << rec << endl;
}
int funarea(int s, int e, int o)
{
    int vol;
    vol = s * e * o;
    cout << "the volume is:" << vol << endl;
}
int main()
{
    int a, b, c;

    cout << "enter"
         << "\n";
    cin >> a >> b >> c;
    if (a != 0)
    {
        funarea(a);
    }
    else
    {
        cout << "Invalid";
    }
    if (a && b != 0)
    {
        funarea(a, b);
    }
    else
    {
        cout << "Invalid";
    }
    if (a && b && c != 0)
    {
        funarea(a, b, c);
    }
    else
    {
        cout << "Invalid";
    }
}