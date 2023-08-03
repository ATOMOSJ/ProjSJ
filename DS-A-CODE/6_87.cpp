#include<iostream>
using namespace std;
void callbyval(int x, int y){
    int swap;
    swap=x;
    x=y;
    y=swap;
    cout<<"Value of x after swapping by call by value "<<x<<endl;
    cout<<"Value of y after swapping by call by val"<<y<<endl;
}
void callbyadress(int *x,int *y){
    int swap;
    swap=*x;
    *x=*y;
    *y=swap;
}
void callbyref(int &xref, int &yref){
    int swap;
    swap=xref;
    xref=yref;
    yref=swap;
}
int main(){
    int x=45,y=63;
    cout<<"Value of x before swapping "<<x<<endl;
    cout<<"Value of y before swapping "<<y<<endl;
    callbyval(x,y);

    callbyadress(&x,&y);
    cout<<"Value of x after swapping by call by adress "<<x<<endl;
    cout<<"Value of y after swapping by call by adress  "<<y<<endl;
    callbyref(x,y);
    cout<<"Value of x after swapping by call by reference "<<x<<endl;
    cout<<"Value of y after swapping by call by reference "<<y<<endl;
    return 0;
}