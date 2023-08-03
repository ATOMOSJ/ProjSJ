// WAP to demonstrate use of hieracrchical inheritance by 
// taking base class circle and derived class rectangle and calculate area
// . again derived class cylinder from circle and calculate 
// volume using parameterised constructors.
#include <iostream>
using namespace std;
class CIRCLE
{
protected:
    float radius, cir_area;

public:
    CIRCLE(float cr)
    {
        radius = cr;
    }
    void c_area()
    {
        cir_area = 3.141 * radius * radius;
    }
};
class RECTANGLE : public CIRCLE
{
protected:
    int breadth, aarea;

public:
    RECTANGLE(float cr, int rb): CIRCLE(cr)
    {
        breadth = rb;
    }
    void areaa()
    {
        aarea = radius * breadth;
    }
    void display_rect()
    {
        cout << "\nThrough Rectangle -->";
        cout << "\nArea of circle is: " << cir_area;
        cout << "\nArea of rectangle is: " << aarea;
    }
};
class CYLINDER : public CIRCLE
{
protected:
    float height, vol;

public:
    CYLINDER(float cr, float clh): CIRCLE(cr)
    {
        height = clh;
    }
    void volume()
    {
        vol = cir_area * height;
    }
    void display()
    {
        cout << "\nThrough Cylinder -->";
        cout << "\nArea of circle is: " << cir_area;
        cout << "\nVolume of the cylinder is: " << vol;
    }
};
int main()
{
    RECTANGLE obj2(12, 10);
    obj2.c_area();
    obj2.areaa();
    obj2.display_rect();
    cout << "\n" << endl;
    CYLINDER obj1(12, 8);
    obj1.c_area();
    obj1.volume();
    obj1.display();
    return 0;
} 