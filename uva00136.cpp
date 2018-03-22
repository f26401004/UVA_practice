#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int number[1510];
	number[0] = 1;
	int j, k, l;
	j = k = l = 0;
	for (int i = 1 ; i < 1500 ; ++i)
	{
		while(j < i)
		{
			if (number[j] * 2 > number[i - 1])
				break;
			++j;
		}
		while(k < i)
		{
			if (number[k] * 3 > number[i - 1])
				break;
			++k;
		}
		while(l < i)
		{
			if (number[l] * 5 > number[i - 1])
				break;
			++l;
		}
		number[i] = min(min(number[j] * 2, number[k] * 3), number[l] * 5);
	}
	cout << "The 1500'th ugly number is " << number[1499] << "." << endl;
	return 0;
}
