#include<stdio.h>
typedef struct student{
    int id;
    char name[80];
    float pr;

}student;
void fun(student record){
    printf("----------->records<----------\n");
printf("\tid is %d\n",record.id);
printf("\tname is %s\n",record.name);
printf("\tpercentage is %f ",record.pr);

}
int main(){
    student record;
printf("enter id\n");
scanf("%d",&record.id);
printf("enter name\n");
scanf("%s",record.name);
printf("enter percentage\n");
scanf("%f",&record.pr);
fun(record);
return 0;

    
}


