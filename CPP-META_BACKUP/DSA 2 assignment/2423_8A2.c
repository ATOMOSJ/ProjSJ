#include <stdio.h>
typedef struct person
{
    int age;
    float weight;
} person;
int main()
{
    person p;
    person *ptr;
    ptr = &p;
    printf("enter age\n");
    scanf("%d", &ptr->age);
    printf("enter weight\n");
    scanf("%f", &ptr->weight);
    printf("the age is : %d\n", ptr->age);
    // *ptr.age
    printf("the weight is: %f", ptr->weight);
    // *ptr.weight
    return 0;
}
