#include <stdio.h>
typedef struct student
{
    char name[50];
    int roll;
    float marks;
} student;
void sort(student list[90], int s)
{
    int i, j;
    student temp;
    for (i = 0; i < s; i++)
    {
        for (j = i+1; j < s; j++)
        {
            if (list[i].marks < list[j].marks)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
int main()
{
    int i, n;
    student s[90];
    printf("enter the total no of student\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the element of student %d\n", i + 1);
        printf("enter name:\n");
        scanf("%s", s[i].name);
        printf("enter roll number\n");
        scanf("%d", &s[i].roll);
        printf("enter marks\n");
        scanf("%f", &s[i].marks);
    }
    sort(s, n);
    printf("\t----->Report<------\n");
    printf("\t----->the highest marks will be shown in top<--------\n");
    printf("\t name \troll number \tmarks\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%s \t%d \t%f\n", s[i].name, s[i].roll, s[i].marks);
    }
}
