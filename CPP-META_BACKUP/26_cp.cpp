// #include <iostream>
// class temp
// {
// private:
//     float c, f;

// public:
//     void input();
//     float display();
//     friend float con(temp A);
// };
// void temp::input()
// {
//     std::cout << "enter"
//               << "\n";
//     std::cin >> c;
// }
// float con(temp A)
// {
//     float f = (A.c) * 1.8 + 32;
//     return f;
// }
// float temp::display()
// {
//     std::cout << "float f*==" << f;
// }
// int main()
// {
//     temp obj1, obj2;
//     obj1.input();
//     con(obj1);
//     obj1.display();
//     return 0;
// }
// //
// from here//
// #include <iostream>
// class B;
// class A
// {
// private:
//     int a, b;

// public:
//     void input();
//     void show(B);
// };
// void A::input()
// {
//     std::cout << "enter"
//               << "\n";
//     std::cin >> a >> b;
// }
// class B
// {
//     int c;
//     friend void A::show(B);
// };
// void A::show(B obj)
// {
//     obj.c = a + b;
//     std::cout << a << "+" << b << "=" << obj.c;
// }
// int main()
// {
//     A obj1;
//     obj1.input();
//     B obj2;
//     obj1.show(obj2);
// }
// #include <iostream>
// using namespace std;

// class temp2;
// class temp
// {
// private:
//     float c;

// public:
//     void input()
//     {
//         std::cout << "enter"
//                   << "\n";
//         std::cin >> c;
//     }
//     void display(temp2);
// };
// class temp2
// {
//     float f;
//     friend void temp::display(temp2);
// };
// void temp::display(temp2 obj){
//     obj.f=(c*9)/5+32;
//     cout<<"display"<<obj.f<<endl;
// }
// int main(){
//     temp obj;
//     temp2 obj2;
//     obj.input();
//     obj.display(obj2);

// }

// using friend class
// #include<iostream>
// using namespace std;
// class area;
// class rectanglesquare{
//     int l,b,side;
//     public:
//     void input(){
//         cout<<"Enter sides of rectangle and square";
//         cin>>l>>b>>side;
//     }
//     int display(area);
// };
// class area{
//     int a,a2;
//     friend int rectanglesquare::display(area);
// };
// int rectanglesquare::display(area ar){
//     ar.a=l*b;
//     ar.a2=side*side;
//     cout<<" rectangle\n"<<ar.a;
//     cout<<"square"<<ar.a2;
// };
// int main(){
//     rectanglesquare s;
//     s.input();
//     area are;
//     s.display(are);
//     return 0;
// }
// #include<iostream>
// using namespace std;
// class area;
// class rectangle{
//     int l,b;
//     public:
//     void input(){
//         cout<<"Enter sides of rectangle";
//         cin>>l>>b;
//     }
//     int display(area);
// };
// class area{
//     int a;
//     friend int rectangle::display(area);
// };
// int rectangle::display(area ar){
//     ar.a=l*b;
//     cout<<"Area of rectangle"<<ar.a;
// };
// int main(){
//     rectangle s;
//     s.input();
//     area are;
//     s.display(are);
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void tra(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
struct node *removeDuplicates(struct node *head)
{
    struct node *ptr = head;
    struct node *next_next;
    if (ptr == NULL)
        printf("not valid");
    exit;
    while (ptr != NULL)
    {

        if (ptr->next != NULL && ptr->data == ptr->next->data)
        {

            next_next = ptr->next;
            ptr->next=next_next->next;
            free(ptr->next);
            
        }
        else
        {

            ptr = ptr->next;
        }
    }
    

    return ptr;
}

int main()
{
    node *y;
    node *o;
    node *t;
    node *r;
    y = (node *)malloc(sizeof(node));
    o = (node *)malloc(sizeof(node));
    t = (node *)malloc(sizeof(node));
    r = (node *)malloc(sizeof(node));
    y->data = 1;
    y->next = o;

    o->data = 2;
    o->next = t;
    t->data = 2;
    t->next = r;
    r->data = 3;
    r->next = NULL;

    // int n;
    // struct node *x, *y, *p;
    // printf("Number of nodes: ");
    // scanf("%d", &n);

    // x = (struct node *)malloc(sizeof(struct node));
    // printf("Enter Node 1 data: ");
    // scanf("%d", &x->data);

    // y = x;

    // for (int i = 2; i <= n; i++)
    // {
    //     p = (struct node *)malloc(sizeof(struct node));
    //     printf("Enter Node %d data: ", i);
    //     scanf("%d", &p->data);
    //     y->next = p;
    //     y = p;
    // }

    // y->next = NULL;
    // y = x;
    tra(y);
    printf("\n");
    y = removeDuplicates(y);
    tra(y);
}
