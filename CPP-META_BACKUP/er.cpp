#include <bits/stdc++.h>
using namespace std;
int kthLargestSum(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> heap;
	vector<int> X;
	int i, j, s = 0;
	for (i = 0; i < n - 1; i++)
	{
		X.push_back(arr[i]);
		s = arr[i];
		for (j = i + 1; j < n; j++)
		{
			s += arr[j];
			X.push_back(s);
		}
	}
	X.push_back(arr[n - 1]);
	for (i = 0; i < X.size(); i++)
	{

		if (heap.size() < k)
		{
			heap.push(X[i]);
		}
		else
		{
			if (heap.top() < X[i])
			{
				heap.pop();
				heap.push(X[i]);
			}
		}
	}
	return (heap.top());
}
int main()
{
	int a[] = {20, -5, -1};
	int n = sizeof(a) / sizeof(a[0]);
	int k = 3;
	cout << kthLargestSum(a, n, k);
	return 0;
}