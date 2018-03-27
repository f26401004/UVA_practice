#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define MAX 10000000
using namespace std;

bool is_prime[MAX];
int dePrime[MAX] = {0};
vector<int> prime;
void makePrime()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 2 ; i <= MAX ; ++i)
	{
		if (is_prime[i])
		{
			prime.push_back(i);
			dePrime[i] = i;
		}
		for(int j = 0 ; i * prime.at(j) < MAX && j < prime.size() ; ++j)
		{	
			is_prime[ i * prime.at(j)] = false;
			if (i % prime.at(j) == 0)
			{
				dePrime[i*prime.at(j)] = dePrime[i];
				break;
			}
			else
				dePrime[i*prime.at(j)] = dePrime[i] + prime.at(j);
		}
	}
}


int main()
{
	int n, m;
	makePrime();
	while(cin >> n)
	{
		if (n == 0)
			break;
		cin >> m;
		int count = 0;
		for (int i = n ; i <= m ; ++i)
			if (is_prime[dePrime[i]])
				++count;
		cout << count << endl;
	}
	return 0;
}
