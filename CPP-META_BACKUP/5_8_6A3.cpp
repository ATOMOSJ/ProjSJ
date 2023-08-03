#include <iostream>
using namespace std;
int S(int a)
{
    if (a > 0)
    {
        cout << "absolute is:" << a << endl;
    }
    else
    {
        cout << " absolute is" << -(a) << endl;
    }
}
float S(float d)
{
    if (d > 0)
    {
        cout << "the absolute is:" << d << endl;
    }
    else
    {
        cout << "the absolute is:" << -(d) << endl;
    }
}
int main()
{
    int n;
    float o;
    cout<<"enter the VALUE"<<"\n"<<endl;
    cin>>o>>n;
    S(o);
    S(n);

        
}
   