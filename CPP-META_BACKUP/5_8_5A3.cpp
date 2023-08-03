#include <iostream>
using namespace std;
void SUM(float a = 0, float b = 10, float c = 20)
{
    cout << "your output is"<< "\n"<< (a + b + c) << endl;
}
int main()
{
    float a, b, c;
    cout << "enter" << endl;
    cin >> a >> b >> c;
    if (a!=0)
    {
        SUM(a);
    }
    if(b!=0)
    {
        
        SUM(a, b);
        
    }
    if(c!=0){
        SUM(a, b, c);
    }
    else{
        cout<<"SUM(NOT VALID)"<<endl;
    }
}