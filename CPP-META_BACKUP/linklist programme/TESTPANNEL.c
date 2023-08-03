#include <stdio.h>

struct distance
{
    float km;
    float m;
};
void display(struct distance d1,struct distance d2)
{

    printf("Input First distance is\n");
    printf("Kilometers:");
    scanf("%f",&d1.km);
    printf("\nMeters:");
    scanf("%f",&d1.m);
    printf("Input Second distance");
    printf("Kilometers:");
    scanf("%f",&d2.km);
    printf("\nMeters:");
    scanf("%f",&d2.m);
    
    float a1,a2;
    a1=d1.km+d2.km;
    a2=d1.m+d2.m;
    while(a2>=1000)
    {
        a2=a2-1000;
        a1++;
    }
    printf("The sum of both the distances is %fkms and %f m",a1,a2);
   
}
 int main(){
     struct distance d1,d2;
     display(d1,d2);

    }