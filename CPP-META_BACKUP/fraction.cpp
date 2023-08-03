#include <iostream>
using namespace std;

class FRACTION
{
private:
    int denominator;
    int numerator;

public:
    void getdata();
    void mul(FRACTION, FRACTION);
    void add(FRACTION, FRACTION);
    void sub(FRACTION, FRACTION);
    int lcm(FRACTION A, FRACTION B)
    {
        int lcm, hcf, temp;
        hcf = A.denominator;
        temp = B.denominator;

        while (hcf != temp)
        {
            if (hcf > temp)
                hcf -= temp;
            else
                temp -= hcf;
        }

        lcm = (A.denominator * B.denominator) / hcf;

        cout << "LCM = " << lcm;
    }
};


void FRACTION::getdata()
{
    cout << "Fraction";
    cout << "\n"
         << "Enter the numerator: ";
    cin >> numerator;
    cout << "\n"
         << "Enter the denominator: ";
    cin >> denominator;
    ;
}
void FRACTION::mul(FRACTION A, FRACTION B)
{
    int x, y, z, p;
    x = A.denominator * B.denominator;
    y = A.numerator * B.numerator;
}
int FRACTION::add(FRACTION A, FRACTION B)
{
    int c;
    c.lcm(A.denominator,B.denominator);
}

// cout<<"Result of addition:"<<<<"/"<<<<"\n";
// z=A.numerator*B.denominator-A.numerator*A.denominator;
// p=B.numerator*A.denominator-B.numerator*B.denominator;
//     if(z>0)
//     {
//         cout<<"Result of subtraction is: "<<z<<"/"<<x<<"\n";
//     }
//     else
//     {
//         cout<<"Result of subtraction is: "<<p<<"/"<<x<<"\n";
//     }
//     cout<<"Result of multiplication is:"<<y<<"/"<<x<<"\n";
// }
int main()
{
    FRACTION e, f, g;
    e.getdata();
    f.getdata();
    g.mul(e, f);
}
