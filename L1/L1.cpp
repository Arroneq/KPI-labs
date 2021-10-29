#include <iostream>
#include <vector>
using namespace std;

vector<int> m;

int fib(int n)
{
	int f0=1, f1=1, f;
	if (n==0 || n==1)
		return f0;
	
	if (n>1)
	{
		f=fib(n-1)+fib(n-2);
		m.push_back(f);
		return f;
	}
}

int main()
{
	int n;
   	cin >> n;
	cout << fib(n);
	cout << endl;
	cout << m[n+3];
	cout << endl;
}
