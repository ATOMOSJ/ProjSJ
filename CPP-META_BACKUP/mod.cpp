#include <iostream>
using namespace std;
class shop
{
private:
    static int grand;
    char name[50];
    int code;
    int price;
    int quant;
    int total;

public:
    void scan();
    void print();
    int calculate(int);
};
void shop::scan()
{
    cout << "name" << endl;
    cin >> name;
    cout << "price" << endl;
    cin >> price;
    cout << "Quantity" << endl;
    cin >> quant;
    cout << "code" << endl;
    cin >> code;
}
void shop::print()
{
    grand += price * quant;
    cout << name << "\t" << price << "\t" << quant << "\t" << code << "\t" << price * quant << "\t\t" << grand << endl;
}
int shop::grand;

int main()
{
    shop s[90];
    int n, i, tot = 0;
    cout << "enter the no of items";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s[i].scan();
    }
    cout << "\t\t----->BILL<------" << endl;
    cout << "name"
         << "\t"
         << "price"
         << "\t"
         << "quant"
         << "\t"
         << "code"
         << "\t"
         << "total price"
         << "\t"
         << "grand total"
         << "\t" << endl;
    for (int i = 0; i < n; i++)
    {

        s[i].print();
    }
}
