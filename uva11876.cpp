#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000010
using namespace std;

int list[MAX];
int divisor_num[MAX];

int main()
{
	memset(list, 0, sizeof(list));
	memset(divisor_num, 0, sizeof(divisor_num));
	for (int i = 1 ; i < MAX ; ++i)
	{	
		for (int j = i ; j < MAX ; j = j + i)
			divisor_num[j]++;
	}
	list[0] = 1;
	for (int i = 1 ; i < MAX ; ++i)
		list[i] = list[i - 1] + divisor_num[list[i - 1]];
	int test_num = 0;
	cin >> test_num;
	int count = 1;
	while(test_num--)
	{
		int lower, upper, ans;
		cin >> lower >> upper;
		if (*lower_bound(list, list + MAX, upper) != upper)
			ans = lower_bound(list, list + MAX, upper) - lower_bound(list, list + MAX, lower); 
		else
			ans = lower_bound(list, list + MAX, upper) - lower_bound(list, list + MAX, lower) + 1; 
		cout << "Case " << count++ << ": " << ans << endl;
	}
	return 0;
}
