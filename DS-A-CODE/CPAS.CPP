#include <iostream>
using namespace std;
struct marks
{
    int a, b, c, d, e;
};
struct op
{
    char name[40];
};
int main()
{
    marks f, g, h, i, j;
    int roll;
    op nam;
    cout << "enter your name\n";
    gets(nam.name);
    cout << "enter roll no.\n";
    cin >> roll;
    cout << "enter your 5 subject marks\n";
    cin >> f.a >> g.b >> h.c >> i.d >> j.e;
    cout << "you name= "
         << nam.name;
    cout << "\tyou roll no="
         << roll;
    cout << "\nyour marks are\n"
         << f.a << "\n"
         << g.b << "\n"
         << h.c << "\n"
         << i.d << "\n"
         << j.e << endl;
    return 0;
}