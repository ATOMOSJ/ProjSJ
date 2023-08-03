#include<iostream>
using namespace std;
int sort(int num[],int n){
    int a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                a=num[i];
                num[i]=num[j];
                num[j]=a;
            }

        }
    }
    cout<<"the sorted array is\n";
    for(int i=0;i<n;i++){
        cout<<"\n"<<num[i];
    }
}
int main(){;
    int i;
    cout<<"enter the no of elements\n";
    int n;
    cin>>n;
    int*p=new int[n];
    cout<<"enter the element of array\n";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i];
    }
    sort(p,n);
    return 0;
}