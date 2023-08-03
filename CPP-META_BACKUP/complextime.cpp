#include <iostream>
//substraction of 2 time object
using namespace std;
class Time
{
    private:
        int h;
        int m;
        int s;
    public:
        void input();
        int convert();
        void display(int fs);
};
void Time::input()
{
    cout<<"Enter hour of the time"<<endl;
    cin>>h;
    cout<<"Enter minute of the time"<<endl;
    cin>>m;
    cout<<"Enter second of the time"<<endl;
    cin>>s;
}
int Time::convert()
{
    int ts=(h*3600)+(m*60)+s;
    return ts;
}
void Time::display(int fs)
{
    int hour=fs/3600;
    int rfs=fs-(hour*3600);
    int min=rfs/60;
    int sec=rfs-(min*60);
    cout<<"After addition:"<<endl;
    cout<<"Time="<<hour<<"h"<<min<<"m"<<sec<<"s"<<endl;
}
int main()
{
    Time s1,s2,s3;
    s1.input();
    s2.input();
    int fs=s1.convert()+s2.convert();
    s3.display(fs);
    return 0;
}