#include<iostream>
using namespace std;

class time
{
    private:
    int h;
    int m;
    int s;
    public:
    void input();
    void S(time,time);
    void disp();
};
void time::input()
{
    cout<<"Enter the time in hour minute and seconds:"<<endl;
    cin>>h>>m>>s;
}
void time::S(time x,time y)
{
       s=x.s+y.s;
       m=s/60; 
       m=m+x.m+y.m;
       h=m/60;
       h=h+x.h+y.h;
       s=s%60;
       m=m%60;
}   
void time::disp()
{
       cout<<h<<"hours "<<m<<"minutes "<<s<<"seconds";
}
int main()
{
    time j,k,l;
    j.input();
    k.input();
    l.S(j,k);
    l.disp();
}