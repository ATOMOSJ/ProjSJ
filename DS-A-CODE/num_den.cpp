#include <iostream>
using namespace std;
class fraction
{
private:
    int n;
    int d;

public:
    void input();
    int sum(fraction a, fraction b);
    int sub(fraction &a, fraction &b);
    int mul(fraction *a, fraction *b);
};
void fraction::input()
{
    cout << "enter the numerator"
         << "\t" << endl;
    cin >> n;
    cout << "enter the denomenator"
         << "\t" << endl;
    cin >> d;
}
int fraction::sum(fraction a, fraction b)
{
    int x, y;
    y = a.n * b.d + a.d * b.n;
    x = a.d * b.d;
    cout << "the sum of the fraction is"
         << "\t" << y << "/" << x << endl;
}
int fraction::sub(fraction &a, fraction &b)
{
    int x, y, o, p;
    if (y > o)
    {

        y = (a.n) * (b.d) - (a.d) * (b.n);
        x = (a.d) * (b.d);
        cout << "the sum of the fraction is"
             << "\t" << y << "/" << x << endl;
    }
    else
    {
        o = (b.n) * (a.d) - (b.d) * (a.n);
        p = (a.d) * (b.d);
        cout << "the sum of the fraction is"
             << "\t" << o << "/" << p << endl;
    }
}
int fraction::mul(fraction *a, fraction *b)
{
    int c, g;
    c = (a->n) * (b->n);
    g = (a->d) * (b->d);
    cout << "the multiplication is"
         << "\t" << c << "/" << g << endl;
}
int main()
{
    fraction a, b, c, c1;
    a.input();
    b.input();
    c.sum(a, b);
    c.sub(a, b);
    c1.mul(&a, &b);
}