// array with dynamic memory allocation and deallocation
// using new and delete operator
#include<iostream>
using namespace std;
void display(int *q,int m){
    cout<<

}
int main()
{
    int n;
    cout<<"array size";
    cin>>n;

    // int*p=(int*)malloc(sizeof(int));
    int*p=new int[n];
    cout<<"enter array elements\n";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<"\t";
    }

    // cout<<"enter value\n";
    // cin>>*p;
    // cout<<"the address is:"<<p<<endl;
    // cout<<"value"<<*p;
    return 0;
}