#include <iostream>
using namespace std;

int main()
{
	int num;
	int coin_type[5] = {1, 5, 10, 25, 50};
	int case_coin[7490] = {0};
	case_coin[0] = 1;
	for (int j = 0 ; j < 5 ; ++j)
		for (int i = coin_type[j] ; i <= 7489 ; ++i)
		{
			if (case_coin[i - coin_type[j]])
					case_coin[i] += case_coin[i - coin_type[j]];
		}

	while(cin >> num)
		cout << case_coin[num] << endl;
	return 0;
}
