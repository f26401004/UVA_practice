#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1000000
using namespace std;

bool is_prime[MAX];
void eratosthenes()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2 ; i < sqrt(MAX) ; ++i)
		if (is_prime[i])
			for (int j = i + i ; j < MAX ; j += i)
				is_prime[j] = false;
}

int countDivisor(int num)
{
	int divisor_number = 1;
	int buffer = num;
	for (int i = 2 ; i <= sqrt(num) ; ++i)
	{
		int temp = 1;
		if (is_prime[i])
		{
			while(buffer % i == 0)
			{
				buffer = buffer / i;
				++temp;
			}
			divisor_number = divisor_number * temp;		
			if (buffer == 1) 
				return divisor_number;
		}
	}
	if (buffer > 1)
		return divisor_number * 2;
	return divisor_number;
}

int maxIndex(int* array, int size)
{
	int max = 0, index = 0;
	for (int i = 0 ; i < size ; ++i)
	{
		if (max < array[i])
		{
			max = array[i];
			index = i;
		}
	}
	return index;
}


int main()
{
	eratosthenes();
	int number[10010];
	int case_num = 0;
	cin >> case_num;
	for (int i = 0 ; i < case_num ; ++i)
	{
		int upper, lower;
		cin >> lower >> upper;
		int max_index;
		for(int j = lower ; j < upper + 1 ; ++j)
			number[j - lower] = countDivisor(j);
		max_index = maxIndex(number, upper - lower + 1);
		cout << "Between "<< lower << " and "<< upper << ", " << (lower + max_index) << " has a maximum of " << number[max_index] << " divisors." << endl;
	}
	return 0;
}
