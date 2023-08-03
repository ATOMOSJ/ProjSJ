#include <iostream>

class a
{
protected:
    int c;

public:
    a() {}
    a(int c)
    {
        std::cout << "constructor is being called\t" << std::endl;
        this->c = c;
    }
    void dis()
    {
        std::cout << "cout from base class=\t" << c << std::endl;
    }
    ~a()
    {
        std::cout << "destructor is being called\t" << std::endl;
    }
};
class b : public a
{
protected:
    int d;
    static int counter;

public:
    b(const b &d1)
    {
        d = d1.c;
        c = d1.d;
    }

    b(int d, int c) : a(c)
    {
        counter++;
        std::cout << "constructor is being called\t" <<counter<<"times"<< std::endl;

        this->d = d;
    }

    void dis()
    {

        std::cout << "cout from derived class=\t"
                  << "(" << d << "," << c << ")" << std::endl;
    }
    int retreve()
    {
        return d * c;
    }
    ~b()
    {
        counter--;
        std::cout << "destructor is being called\t" <<abs(counter)<<"times"<< std::endl;
    }
};
int b::counter;
int main()
{
    b bc(90, 34);
    bc.a::dis();
    // single inheritance amiguity;
    bc.dis();
    b bcc(90, 89);
    b bv(bcc);
    bv.dis();
    b mc(24, 67);
    std::cout << mc.retreve() << std::endl;
}
