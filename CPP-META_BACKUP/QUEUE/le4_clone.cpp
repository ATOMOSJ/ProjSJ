// WAP to demonstrate use of multipath inheritance by taking base class student and two derived class sports and exam. a class result is derived from both the classes. illustrate the usage in main.
#include <iostream>
using namespace std;

class student
{
protected:
    char name[30];
    int rollno;

public:
    student()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No.: ";
        cin >> rollno;
    }
};

class sports : virtual public student
{
protected:
    int s_grade;

public:
    sports()
    {
        cout << "Enter score in sports (Out of 40): ";
        cin >> s_grade;
    }
};

class exam : virtual public student
{
protected:
    int e_grade;

public:
    exam()
    {
        cout << "Enter score in exam (Out of 60): ";
        cin >> e_grade;
    }
};

class results : public sports, public exam
{
protected:
    char a[3];

public:
    void result()
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
        cout << "Score in Sports: " << s_grade << "\nGrade: " << a[0] << endl;
        cout << "Score in Exam: " << e_grade << "\nGrade: " << a[1] << endl;
        cout << "Total Score: " << s_grade + e_grade << "\nTotal Grade: " << a[2] << endl;
    }
};

int main()
{
    results ob;
    ob.result();
    ob.display();
    return 0;
}