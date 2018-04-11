#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;
	for(int i = 0 ; i < test_case ; ++i)
	{
		int car_num;
		cin >> car_num;
		int list[car_num];
		for (int j = 0 ; j < car_num ; ++j)
			cin >> list[j];
		int LIS[car_num], LDS[car_num];
		int max = 0;
		for (int j = car_num - 1 ; j > -1 ; --j)
		{
			LIS[j] = LDS[j] = 1;
			for (int k = car_num - 1 ; k > j ; --k)
			{
				if (list[k] < list[j] && LIS[k] + 1 > LIS[j])
					LIS[j] = LIS[k] + 1;
				if (list[k] > list[j] && LDS[k] + 1 > LDS[j])
					LDS[j] = LDS[k] + 1;
			}
			if (max < LIS[j] + LDS[j] - 1)
				max = LIS[j] + LDS[j] - 1;
		}
		cout << max << endl;
	}
	return 0;
}
