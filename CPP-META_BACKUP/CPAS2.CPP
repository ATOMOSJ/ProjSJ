#include <iostream>
using namespace std;
struct student
{
    char name[50];
    int roll;
    int marks[5];
    int total_marks;
    float p;
};
void map(struct student s1, int m)
{
    int i, j, n;
    printf("enter the no. of students\n");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        s1[i].total_marks = 0;
        s1[i].p = 0.0f;
        for (j = 0; j < n; j++)
            s1[i].total_marks += s1[i].marks[j];
        s1[i].p += s1[i].total_marks / 5;
    }
    cout << "total marks= " << s1[i].total_marks;
    cout << "percentage= " << s1[i].p;
}

int main()
{
    int ar[300];
    int n, i;
    cout << "put the no. of students\n";
    cin >> n;
    for (i = 0; i = n; i++)
    {
        cin >> ar[i];
    }
}