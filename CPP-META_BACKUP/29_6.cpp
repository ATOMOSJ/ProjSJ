#include<iostream>
using namespace std;
void rev(int y[],int l){
    int i;
    cout<<"the reverse order is:"<<endl;
    for(i=l-1;i>=0;i--){
        cout<<y[i];
    }
}
int main(){
    int n;
    cout<<"enter the no. of element"<<endl;
    cin>>n;
    int*t=new int[n];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    rev(t,n);

}
