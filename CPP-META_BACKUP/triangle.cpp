#include<iostream>
using namespace std;
class triangle{
private:
int base;
int height;
// int dis;
static int num;
public:
void getData();
void areaTrin();
// void display();
};
void triangle::getData(){
    cout<<"enter the base and the height"<<endl;
    cin>>base>>height;
}
void triangle::areaTrin(){
int dis=0.5*base*height;

num++;
cout<<"the area of "<<num<<"is"<<"\t"<<dis<<endl;
}
// void triangle::display(){
// }
int triangle::num=0;
int main(){
    triangle T[90];
    cout<<"enter the no. of triangle you want to perform"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      T[i].getData();
      T[i].areaTrin();
    //   T[i].display();
    }
    return 0;
}