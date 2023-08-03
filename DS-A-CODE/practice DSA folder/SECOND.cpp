#include <iostream>
using namespace std;
struct akt
{
    char name[20];
    int roll;
    char sub_n[20];
    int sub_m;

    void input()
    {
        cout << "enter your name=" << endl;
        cin >> name;
        cout << "enter your roll number=" << endl;
        cin >> roll;
        cout << "now enter 5 subjects and their marks you obtained out of 80" << endl;
        cin >> sub_n >> sub_m;
    }
    void display()
    {
        cout << "your name" << name << endl;
        cout << "your roll no." << roll << endl;
        cout << "your subject name and the marks you obtained" << sub_n << sub_m << endl;
    }
    void tp(int a, int b, int c, int d, int e, int f, int p)
    {
        f = a + b + c + d + e;
        cout << "the total marks you obtained" << f << endl;
        p = f / 80 * 100;
        cout << "the percentile you got" << p << endl;
    }
    void range(int p)
    {
        if (p < 40)

            cout << "good" << endl;
    }
    else if (p > 40)
    {
        cout << "excelent" << endl;
    }
};
