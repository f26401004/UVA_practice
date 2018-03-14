#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int main()
{
	int n1, n2;
	while(cin >> n1 >> n2)
	{
		if (gcd(n1, n2) == 1)
			cout << setw(10) << n1 << setw(10) << n2 << "    " << "Good Choice" << endl;
		else
			cout << setw(10) << n1 << setw(10) << n2 << "    " << "Bad Choice" << endl;
		cout << endl;
	}
	return 0;
}
