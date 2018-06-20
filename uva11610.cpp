#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000005
using namespace std;

int BIT_1[MAX], BIT_2[MAX];

bool is_prime[MAX];
int factory[MAX];
vector<int> prime, r_prime;
map<int, int> set;

int low_bit(int target)
{
	return target & (-target);
}

int get_sum(int* array, int index)
{
	int ans = 0;
	while(index  > 0)
	{
		ans += array[index];
		index -= low_bit(index);
	}
	return ans;
}

void modify(int* array, int index, int value)
{
	while(index <= prime.size())
	{
		array[index] += value;
		index += low_bit(index);
	}
}

int reverse(int target)
{
	int result = 0;
	for(int i = 0 ; i < 6 ; ++i)
	{
		result = result * 10 + target % 10;
		target = target / 10;
	}
	while(target > 0)
	{
		result = result * 10 + target % 10;
		target = target / 10;
	}
	return result;
}

void build_prime()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for(int i = 2 ; i < MAX ; ++i)
		if (is_prime[i])
		{
			for(int j = i + i ; j < MAX ; j += i )
				is_prime[j] = false;
			prime.push_back(i);
		}
	for(int i = 0 ; i < prime.size() ; ++i)
		r_prime.push_back(reverse(prime.at(i)));
	sort(r_prime.begin(), r_prime.end());
	for(int i = 1 ; i <= r_prime.size() ; ++i)
		set[r_prime.at(i - 1)] = i;
	for(int i = 1 ; i <= r_prime.size() ; ++i)
	{
		factory[i] = 2;
		int temp = r_prime.at(i - 1);
		for(int j = 0 ; j < prime.size() && prime.at(j) * prime.at(j) <= temp ; ++j)
		{
			while(temp % prime.at(j) == 0)
			{
				factory[i]++;
				temp = temp / prime.at(j);
			}
		}
		if (temp > 1)
			factory[i]++;
	}
}

void init()
{
	set.clear();
	prime.clear();
	r_prime.clear();
	build_prime();		
	memset(BIT_1, 0, sizeof(BIT_1));
	memset(BIT_2, 0, sizeof(BIT_2));
}

int main()
{
	init();
	for(int i = 1 ; i <= prime.size() ; ++i)
		modify(BIT_1, i, 1);
	for(int i = 1 ; i <= prime.size() ; ++i)
		modify(BIT_2, i, factory[i]);
	string type;
	int value;
	while(cin >> type >> value)
	{
		if (type.at(0) == 'd')
		{
			int pos = set[value / 10];
			modify(BIT_1, pos, -1);
			modify(BIT_2, pos, -factory[pos]);
		}
		else
		{
			value++;
			int left = 1, right = prime.size(), mid;
			while(left <= right)
			{
				mid = (left + right) >> 1;
				int temp = get_sum(BIT_1, mid);
				if (temp == value)
					break;
				if (temp < value)
					left = mid + 1;
				else
					right = mid - 1;
			}
			cout << get_sum(BIT_2, mid) << endl;
		}
	}
	return 0;
}
