// WAP to demonstrate use of multipath inheritance by taking base class student and two derived class sports and exam. a class result is derived from both the classes. illustrate the usage in main using parameterised constructors.
#include <iostream>
using namespace std;

class student
{
protected:
    string name;
    int rollno;

public:
    student(string nam, int roll)
    {
        name = nam;
        rollno = roll;
    }
};

class sports : virtual public student
{
protected:
    int s_grade;

public:
    sports(int sg, string nam, int roll) : student(nam, roll)
    {
        s_grade = sg;
    }
};

class exam : virtual public student
{
protected:
    int e_grade;

public:
    exam(int eg, string nam, int roll) : student(nam, roll)
    {
        e_grade = eg;
    }
};

class results : public sports, public exam
{
protected:
    char a[3];

public:
    results(int sg, int eg, string nam, int roll) : sports(sg, nam, roll), exam(eg, nam, roll), student(nam, roll)
    {
        if (s_grade > 30)
        {
            if (e_grade > 50)
            {
                a[0] = 'A';
                a[1] = 'A';
                a[2] = 'A';
            }
            else
            {
                a[0] = 'A';
                a[1] = 'B';
                a[2] = 'B';
            }
        }
        else
        {
            if (e_grade > 50)
            {
                a[0] = 'B';
                a[1] = 'A';
                a[2] = 'B';
            }
            else
            {
                a[0] = 'B';
                a[1] = 'B';
                a[2] = 'C';
            }
        }
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll number: " << rollno << endl;
        cout << "Score in Sports: " << s_grade << "\nGrade: " << a[0] << endl;
        cout << "Score in Exam: " << e_grade << "\nGrade: " << a[1] << endl;
        cout << "Total Score: " << s_grade + e_grade << "\nFinal Grade: " << a[2] << endl;
    }
};

int main()
{
    results ob(36, 52, "Sriansh", 2882);
    ob.display();
    return 0;
}