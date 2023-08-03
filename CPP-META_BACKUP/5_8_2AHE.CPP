#include <iostream>
using namespace std;
void ADD(int a, int b)
{

    cout << (a + b) << endl;
}
void ADD(int a, int b, int c)
{

    cout << (a + b + c) << endl;
}
void ADD(double c, double d)
{

    cout << (c+d) << endl;
}
int main()
{
    ADD(2, 4);
    ADD(3, 4, 5);
    ADD(2.398, 4.690);
    cout<<sizeof(float)<<"\n"<<sizeof(double)<<endl;
}