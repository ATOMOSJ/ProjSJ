// create a function template that prints the swap of two numbers.

#include <iostream>
using namespace std;

template <class T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <>
void swap(int &a, T &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "custom" << endl;
}

int main()
{

	cout << endl
		 << endl
		 << "After Swap" << endl;
	cout << swap<int, int>(3, 4);
	cout << swap<float, float>(6.66, 6.77);

	return 0;
}