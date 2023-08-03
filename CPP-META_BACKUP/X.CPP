#include <iostream>
using namespace std;
struct employee
{
    char name[30];
    int id;
    int age,b_salary;
    float da,hra,g_salary;
    void input()
    {
        cout<<"Enter name,id,age and basic salary";
        cin>>name>>id>>age>>b_salary;
    }
    void gross_salary()
    {
       float da,hra,g_salary;
       da=((80.0*b_salary)/100);
       hra=((10.0*b_salary)/100);
       g_salary=b_salary+da+hra;
    }
    void display()
    {
        cout<<"---------------Employee Card-------------------------\n";
        cout<<"Name ="<<name<<endl;
        cout<<"ID ="<<id<<endl;
        cout<<"Age ="<<age<<endl;
        cout<<"Basic Salary="<<b_salary<<endl;
        cout<<"Gross Salry ="<<g_salary<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter total no of employee";
    cin>>n;
    employee *emp[n],e[n];
    for(int i=0;i<n;i++)
    {
        emp[i]=&e[i];
    }
    for(int i=0;i<n;i++)
    {
        emp[i]->gross_salary();
        emp[i]->input();
        emp[i]->display();
    }
    return 0;
}