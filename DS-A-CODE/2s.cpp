#include <iostream>
using namespace std;
struct student
{
    char name[30];
    int roll_no;
    int maths,phy,eng,bio,chem,tm;
    double p_age;
    void input()
    {
        cout<<"Enter name,roll,and marks of 5 subjects";
        cin>>name;
        cin>>roll_no;
        cin>>maths>>phy>>eng>>bio>>chem;
    }
    void percentage()
    {
       tm=maths+phy+eng+bio+chem;
       p_age=((tm*1.0)/500)*100;
    }
    void display()
    {
        cout<<"---------------Report Card-------------------------\n";
        cout<<"Name of the student="<<name<<endl;
        cout<<"roll no of the student="<<roll_no<<endl;
        cout<<"Maths score="<<maths<<endl;
        cout<<"physics score="<<phy<<endl;
        cout<<"English score="<<eng<<endl;
        cout<<"Biology score="<<bio<<endl;
        cout<<"Chemistry score="<<chem<<endl;
        cout<<"Total Marks="<<tm<<endl;
        cout<<"percentage="<<p_age<<endl;
    }
};

int main()
{
    int n,check_roll,l_lmt,u_lmt;
    cout<<"Enter total no of student";
    cin>>n;
    student s[n];
    for(int i=0;i<n;i++)
        {
            s[i].input();
            s[i].percentage();
        }    
    cout<<"Enter the roll no of the student";
    cin>>check_roll;
    for(int i=0;i<n;i++)
    {
        if (check_roll==s[i].roll_no)
        s[i].display();
    }
    cout<<"Enter the lower and upper limit of %age range";
    cin>>l_lmt;
    cin>>u_lmt;
    for(int i=0;i<n;i++)
    {
        if (s[i].p_age>=l_lmt &&s[i].p_age<=u_lmt)
        s[i].display();
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j].tm>s[j+1].tm)     //ascending order
            {
                int temp=s[j].tm;
                s[j].tm=s[j+1].tm;
                s[j+1].tm=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t\n%f",s[i].roll_no,s[i].tm,s[i].p_age);
    }
    return 0;
}