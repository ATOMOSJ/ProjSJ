#include <iostream>
// #include <cmath>      used for sqrt
#include <math.h>
using namespace std;
int main()
{
    int a, b, c, s, area;
    cout << "enter the sides of tringle";
    cin >> a >> b >> c;
    s = a + b + c / 2;
    area = sqrt( s*(s - a)*(s - b)*(s - c));
    cout << "your area is =\t" << area;
    return 0;
}