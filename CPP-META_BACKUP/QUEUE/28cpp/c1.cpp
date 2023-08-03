// #include<iostream>
// using namespace std;
// class test{
// 	int a;
// 	float b;
// 	public:
// 		test(int x,int y)
// 		{
// 			a=x;
// 			b=y;
// 		}
// 		operator int()
// 		{
// 			return a;
// 		}
// 		void show()
// 		{
// 			cout<<a<<endl;
// 			cout<<b<<endl;
// 		}
// };
// int main()
// {
// 	test t(5,10.2);
// 	t.show();
// 	test m=t;
// 	float n=t;
// 	cout<<m<<endl;
// 	cout<<n<<endl;
// }
// #include<iostream>
// using namespace std;
// class Distance{
// 	int feet;
// 	int inches;
// 	public:
// 		Distance(int f,int i)
// 		{
// 			feet=f;
// 			inches=i;
// 		}
// 		void operator=(const Distance &D){
// 			feet=D.feet;
// 			inches=D.inches;
// 		}
// 		void display()
// 		{	
// 			cout<<feet<<inches<<endl;
// 		}
// };
// int main()
// {
// 	Distance D1(11,10),D2(5,6);
// 	D1.display();
// 	D2.display();
// 	D1=D2;
// 	D1.display(); 
// }
// (this pointer)
// #include <iostream>
// using namespace std;
// class  item {
//     int x;
//     public:
//     void set(int x){
//         this->x=x;
//     }
//     void show(){
//         cout<<"x="<<x<<endl;
//     }

// };
// int main(){
//     item u4;
//     int x=69;
//     u4.set(x);
//     u4.show();

// }
// pointer to an object
// #include <iostream>
// using namespace std;
// class co
// {
//     int r, i;

// public:
//     void set(int a, int b)
//     {
//         r = a;
//         i = b;
//         cout <<"("<< a <<","<< b<<")"<<endl;
//     }
// };
// int main()
// {

//     co *p=new co ;
//     (*p).set(1, 3);
// }
//virtual function
// #include<iostream>
// using namespace std;
// class bbc;
// class kbc;
// class abc{

// };
//pointer for derived class
// #include<iostream>
// using namespace std;
// class BaseClass{
//     public:
//         int var_base;
//         void display(){
//             std::cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
//         }
// };

// class DerivedClass : public BaseClass{
//     public:
//             int var_derived;
//             void display(){
//                 cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
//                 cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
//             }
// };
//  int main(){
//     BaseClass * base_class_pointer;
//     BaseClass obj_base;
//     DerivedClass obj_derived;
//     base_class_pointer = &obj_derived; 

//     base_class_pointer->var_base = 34;
//     // base_class_pointer->var_derived= 134;
//     base_class_pointer->display();

//     base_class_pointer->var_base = 3400; 
//     base_class_pointer->display();

//     DerivedClass * derived_class_pointer;
//     derived_class_pointer = &obj_derived;
//     derived_class_pointer->var_base = 9448;
//     derived_class_pointer->var_derived = 98;
//     derived_class_pointer->display();

//     return 0;
// }
