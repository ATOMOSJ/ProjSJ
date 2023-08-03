#include<iostream>
using namespace std;
int sum(int q[],int m){
    int sum=0;
    for(int i=0;i<m;i++){
        sum+=q[i];
        
    }return sum;
}
int main(){
    cout<<"enter the no of elements\n";
    int n;
    cin>>n;
    int*p=new int[n];
    cout<<"enter the element of array\n";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"the elements of the array are\n";
    for(int i=0;i<n;i++){
        cout<<p[i];
    }
    cout<<"\n";
    
    cout<<"the sum is =\t"<<sum(p,n);


}