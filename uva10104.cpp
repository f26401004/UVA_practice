#include <iostream>
using namespace std;

int exgcd(int a, int b, int& x, int&y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int gcd = exgcd(b, a % b, x, y);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return gcd;
	}
}

int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		int x, y;
		exgcd(a, b, x, y);
		cout << x << " " << y << " " << a * x + b * y << endl;
	}
	return 0;
}
