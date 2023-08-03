#include <iostream>
#include <time.h>
using namespace std;
/*why use template*/         
// syntx     
// template<class name_class>         
template <class t>
class tempo
{
public:
    t *arr;
    int size;
    tempo(int m)
    {
        size = m;
        arr = new t[size];
    }
    t dot(tempo &v)
    {
        t d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }
};
class student
{
    int age;
    string name;

public:
    student()
    {
        name = "no name";
        age = 0;
    }
    student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void dis()
    {
        cout << "your name is:" << name << "\n"
             << "your age:" << age;
    }
    void *operator new(size_t s)
    {
        void *pointer;
        cout << "overloaded new size is" << s << endl;
        pointer = malloc(s);
        if (!pointer)
        {
            bad_alloc ba;
            throw ba;
        }
        return pointer;
    }
    void operator delete(void *pointer)
    {
        cout << "overload delete:" << endl;
        free(pointer);
    }
    friend ostream &operator<<(ostream &output, student &s);
    friend istream &operator>>(istream &input, student &s);
};
ostream &operator<<(ostream &output, student &s)
{
    cout << "<< overloaded" << endl;
    output << "my name is:\t" << s.name << "\n"
           << "age:" << s.age << endl;
    return output;
}
istream &operator>>(istream &input, student &s)
{
    cout << ">> overloaded" << endl;
    input >> s.name >> s.age;
    return input;
}
class mar
{
    int h;
    int sub[3];

public:
    mar()
    {
        h = 0;
    }
    mar(int x)
    {
        cout << "the constructor is being is called" << endl;
        h = x;
    }
    mar(int sub1, int sub2, int sub3)
    {
        sub[0] = sub1;
        sub[1] = sub2;
        sub[2] = sub3;
    }
    // new and delete operator overloaing

    mar operator()(int mk)
    {
        cout << "the function is being called" << endl;
        h = mk;
        return *this;
    }
    mar *operator->()
    {
        return this;
    }
    int operator[](int pos)
    {
        return sub[pos];
    }

    // special operator (no friend,also should be non static)

    void operator/=(int dev)
    {
        h = h / dev;
    }
    friend void operator*=(mar &con, int sus);
    friend mar operator+(mar &coo, mar sup);
    friend mar operator*(mar &coo, mar sup);

    void display()
    {
        cout << "value" << h << endl;
    }
    // increment and decrement operator/
    mar operator++(int)
    {
        mar duplicate(*this);
        h++;
        return duplicate;
        // return *this;
    }
    void operator--()
    {
        --h;
    }
    friend mar operator--(mar &);
    friend mar operator--(mar &, int);
};
mar operator--(mar &m)
{
    --m.h;
    return m;
}
mar operator--(mar &m, int)
{
    // mar duplicate(m);
    m.h--;
    // return duplicate;
    return m;
}
mar operator+(mar &coo, mar sup)
{
    mar temp;
    temp.h = coo.h + sup.h;
    return temp;
}
mar operator*(mar &coo, mar sup)
{
    mar temp;
    temp.h = coo.h * sup.h;
    return temp;
}
// 1 argument if  inside class
// and 2 if used with frends
// use a refereence if friend is there and
// use with a increment or decrement int value
void operator*=(mar &con, int sus)
{
    con.h *= sus;
}

int main()
{
    int d;
    tempo<float> v1(3);
    v1.arr[0] = 1.56;
    v1.arr[1] = 1.56;
    v1.arr[2] = 1.56;
    tempo<float> v2(3);
    v2.arr[0] = 1.67;
    v2.arr[1] = 1.45;
    v2.arr[2] = 1.88;
    float a = v1.dot(v2);
    cout << a << endl;
    mar mar1(300);
    mar1--;
    mar1.display();
    mar mar1(30), mar2(90);
    student *lol;
    try
    {
        lol = new student("kk", 69);
        lol->dis();
        delete lol;
    }
    catch (bad_alloc b)
    {
        cout << "t" << endl;
    }
    student op;
    cin >> op;
    cout << op;
    mar thisu(67);
    thisu.display();
    thisu->display();
    /*cannot alter  the the precedence of the operator*/
    /*(?),(::),(.),(.*) cannot be overloaded*/

    mar arraysubscript(44,55,66);
    cout<<arraysubscript[0]<<"\n"<<arraysubscript[1]<<"\n"<<arraysubscript[2];
    (mar1--).display();
    (mar1--).display();
    mar1.display();
    // function call overloading()
    mar1(34);
    mar1.display();
    mar m23 = mar1 * mar2;
    m23.display();
    (mar1++).display();
    mar1.display();
    mar1 *= 60;
    mar1.display();
    mar1 /= 500;
    mar1.display();
    mar mar4 = mar1 + mar2;
    mar4.display();
    // using inheritance you can redefine a operator in deriver class
}