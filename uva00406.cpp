#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 10000000
using namespace std;

bool is_prime[MAX];
vector<int> prime;

void build()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = true;
	prime.push_back(1);
	for (int i = 2 ; i <= sqrt(MAX) ; ++i)
	{
		if (is_prime[i])
		{
			prime.push_back(i);
			for(int j = i + i ; j < MAX ; j = j + i)
				is_prime[j] = false;
		}
	}
}

int main()
{
	build();
	int number, range;
	while(cin >> number >> range)
	{
		int prime_count = 0;
		for(int i = 0 ; i < prime.size() ; ++i)
		{
			if (prime.at(i) > number)
				break;
			++prime_count;
		}
		cout << number << " " << range << ":";
		int start, end;
		start = prime_count / 2 - range + 1 + (prime_count % 2 == 0 ? -1 : 0);
		end = prime_count / 2 + range;
		if (start > -1)
			for(int i = start ; i < end ; ++i)
				cout << " " << prime.at(i);
		else
			for(int i = 0 ; i < prime_count ; ++i)
				cout << " " << prime.at(i);
		cout << endl << endl;
	}
}
