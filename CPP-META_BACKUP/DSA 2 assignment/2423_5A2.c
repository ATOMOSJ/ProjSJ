#include <stdio.h>
typedef struct employee
{
    int e_id;
    char name[200];
    int salary;
} employee;
typedef struct organisation
{
    char og_name[50];
    char og_num[80];
    employee emp;
} organisation;
int main()
{
    organisation org;
    printf("enter the organisation name\n");
    scanf("%s", org.og_name);
    printf("enter the organisation number\n");
    scanf("%s", org.og_num);
    printf("enter the employee id\n");
    scanf("%d", &org.emp.e_id);
    printf("enter the name of employee\n");
    scanf("%s", org.emp.name);
    printf("enter the salary of the employee\n");
    scanf("%d", &org.emp.salary);
    printf("\t------>DOCUMENT<------\n");
    printf("\toranisation name: %s\n\torganisation number: %s\n\temployee id: %d\n\t employee name: %s\n\t salary: %d\n\t", org.og_name, org.og_num, org.emp.e_id, org.emp.name, org.emp.salary);
}