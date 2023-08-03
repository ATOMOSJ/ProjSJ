#include <iostream>
#include <fstream>
using namespace std;
class product
{
    int id;
    int quant;
    int price;

public:
    void getdata()
    {
        cin >> id >> quant >> price;
    }
    void display()
    {
        cout << id << quant << price;
    }
};
int main()
{
    product ob1[12];
    ofstream hout("simp.txt");
    cout << "id"
         << "quantity"
         << "price" << endl;
    for (int i = 0; i < 10; i++)
    {
        ob1[i].getdata();

        hout.write((char *)&ob1[i], sizeof(ob1[i]));
    }
    // file write and read syntax
    hout.close();
    ifstream hin("simp.txt");
    product ob[10];
    for (int j = 0; j < 10; j++)
    {
        hin.read((char *)&ob[j], sizeof(ob[j]));
        ob[j].display();
    }

    hin.close();
    return 0;
}