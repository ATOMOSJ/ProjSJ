#include <iostream>
class distance
{
private:
    float feet;
    float inches;

public:
    void input();
    void display();
    int add(distance, distance);
};
void distance::input()
{
    std::cout << "enter in feets";
    std::cin >> feet;
    std::cout << "enter in inches";
    std::cin >> inches;
}
int distance::add(distance a, distance b)
{
    feet = a.feet + b.feet;
    inches = a.inches + b.inches;
}
void distance::display()
{
    std::cout << "the distance is"
              << "\n"
              << feet << "feet"
              << "and" << inches << "inches";
}
int main()
{
    distance p, n, d;
    p.input();
    n.input();
    d.add(p, n);
    d.display();
    return 0;
}
