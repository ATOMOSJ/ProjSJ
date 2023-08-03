#include <iostream>
using namespace std;
class complex
{
private:
    int x, y;

public:
    int input();
    int add(complex, complex);
    void dis();
};
int complex::input()
{
    cout << "enter the complex number"
         << endl;
    cout << "enter the real and imaginary" << endl;
    cin >> x >> y;
}
int complex::add(complex a, complex b)
{
    
    x = a.x + b.x;
    y = a.y + b.y;
   
}
void complex::dis(){
 cout << "the result is"
         << "\n"
         << x<< "+" << y << "i" << endl;
}

int main()
{
    complex a, b, c;
    a.input();
    b.input();
    c.add(a, b);
    c.dis();
    return 0;
}