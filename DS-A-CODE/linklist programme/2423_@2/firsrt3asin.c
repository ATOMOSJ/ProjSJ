#include <stdio.h>
typedef struct distance
{
    float km;
    float m;
} distance;
void convert(distance d1)
{
    float r;
    float sum;
    printf("enter in km and meter\n");
    scanf("%f\n", &d1.km);
    scanf("%f", &d1.m);
    r = d1.m/ 1000;
    sum = d1.km + r;
    printf("the total sum will be %f km", sum);
}
int main()
{
    distance d1;

       
    convert(d1);
    return 0;
}