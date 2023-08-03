#include<iostream>
using namespace std;

int area_vol(int r)
{
    int t;
    t=3.14*r*r;
    return t;
}
float area_vol(float r)
{
    float t;
    t=1.33*3.14*r*r*r;
    return t;
}

int main(){
    cout<<"the area of circle "<<area_vol(4)<<endl;
    cout<<"volume of sphere "<<area_vol(5)<<endl;
    return 0;

}
