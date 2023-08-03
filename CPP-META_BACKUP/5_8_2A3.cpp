#include <iostream>  
using namespace std;  

int num = 50;  
int main ()  
{  
   
int num = 100;  
  
 
cout << " The value of the local variable num: " << num;  
   
cout << "\n The value of the global variable num: " << ::num;   
return 0;  
}  