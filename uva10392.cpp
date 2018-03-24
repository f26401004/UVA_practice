#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 1000000
using namespace std;

bool is_prime[MAX];

void  make_prime()
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	
	for (int i = 2 ; i <= sqrt(MAX) ; ++i)
		if (is_prime[i])
			for (int j = i + i ; j < MAX ; j += i)
				is_prime[j] = false;
}


int main()
{
	unsigned long long num;
	make_prime();
	while(cin >> num)
	{
		if (num == -1)
			break;
		unsigned long long buffer = num;
		unsigned long long  sqrt_value = min((unsigned long long)sqrt((double)num), (unsigned long long)MAX);
		for (unsigned long long i = 2 ; i <= sqrt_value ; ++i)
		{
			
			if (is_prime[i])
			{
				while(buffer % i == 0)
				{
					cout << "    " << i << endl; 
					buffer = buffer / i;
				}
			}
		}
		if (buffer > 1)
			cout << "    " << buffer << endl;
		cout << endl;
	}
	return 0;
}
