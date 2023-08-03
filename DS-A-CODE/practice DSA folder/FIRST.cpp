#include<iostream>
using namespace std; 
struct akt{
    char name[20];
    int roll;
    char sub_n[20];
    int sub_m;

    void input()
    {
        cout<<"enter your name="<<endl;
        cin>>name;
        cout<<"enter your roll number="<<endl;
        cin>>roll;
        cout<<"now enter your subject name and the marks you obtained"<<endl;
        cin>>sub_n>>sub_m;
    }
    void display()
    {
        cout<<"your name"<<name<<endl;
        cout<<"your roll no."<<roll<<endl;
        cout<<"your subject name and the marks you obtained"<<sub_n<<sub_m<<endl;
    }
};
int main(){
    int n;
    akt S[100],input,display;
    cout<<"enter the no of subject you want to enter\n";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
      S[i].input();
    }
    cout<<"the details you want"<<"\n";
    for(int i=0;i<=n;i++)
    {
        S[i].display();
    }
    cout<<"thanks for visiting\n";
    return 0;
}