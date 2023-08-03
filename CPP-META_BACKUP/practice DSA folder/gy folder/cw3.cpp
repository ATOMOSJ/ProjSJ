#include<iostream>
using namespace std;
int main()
{
int a,b,c,d,i;
cout<<"enter a positive integer\n";
cin>>a;
if(a<=0){
    cout<<"does'nt exist\n";

}else{
    for(int i=1;i<=a;i++){
        c*=i;
    }
    cout<<"factorial of"<<a<<"="<<c;

}
return 0;
}