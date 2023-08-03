#include <iostream>
using namespace std;
class employee
{
private:
    static int id;
    static int num;
    static int y;
    char name[90];
    int age;
    char des[80];
    float hra;
    float da;
    int bs;
    int gs;
    

public:
    // int total(employee);
    void input();
    int display(employee);
    void employees();
   
};
int employee::id = 6969;
int employee::y=0;
void employee::input()
{
    cout << "enter name" << endl;
    cin >> name;
    cout << "enter age" << endl;
    cin >> age;
    cout << "enter the designation" << endl;
    cin >> des;
    cout << "enter the base salary" << endl;
    cin >> bs;
}
int employee::display(employee a)
{
    hra = a.bs * 0.2;
    da = a.bs * 0.4;
    gs = a.bs + hra + da;
    id++;
    y+=gs;
    cout << name << "\t" << age << "\t" << des << "\t" << bs << "\t\t" << gs << "\t\t" << id << "\t\t" << hra << "\t\t" << da << "\t" <<y<<"\t" << endl;
}
// int employee::num;
// inline int employee::total(employee c)
// {
//     int tot = c.gs;
//     // for (int i = 0; i < n; i++)
//     // {

//         tot += c.gs;
//         c.gs++;
//     // }
//     return tot;

// }

int main()
{
    int n, i;
    int count = 0;
    employee w[90];
    cout << "enter the no. of employees" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        w[i].input();
        count++;
    }
    cout << "name"
         << "\t"
         << "age"
         << "\t"
         << "rank"
         << "\t"
         << "salaray"
         << "\t\t"
         << "net"
         << "\t\t"
         << "ID"
         << "\t\t"
         << "HRA"
         << "\t\t"
         << "DA" <<"\t"<<"total"<< endl;

    for (int i = 0; i < n; i++)
    {
        w[i].display(w[i]);
    }
    cout << "total no. of employess are " << count << endl;
}
