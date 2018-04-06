#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int money, case_num;
	while( cin >> money >> case_num)
	{
		int dp[money + 210];
		int price[case_num];
		int favor[case_num];
		memset(dp, 0, sizeof(dp));
		memset(price, 0, sizeof(price));
		memset(favor, 0, sizeof(favor));
		for(int i = 0 ; i < case_num ; ++i)
			cin >> price[i] >> favor[i];
		for(int i = 0 ; i < case_num ; ++i)
			for(int j = money + 200 ; j >= price[i] ; --j)
			{
				if (!dp[j - price[i]] && j != price[i]) 
					continue;
				dp[j] = max(dp[j], dp[j - price[i]] + favor[i]);
			}
		int result = 0;
		for(int i = 0 ; i <= money + 200 ; ++i)
			if (i > 2000 || i <= money)
				result = max(result, dp[i]);
		cout << result << endl;
	}
	return 0;
}
