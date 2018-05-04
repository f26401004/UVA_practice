#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 2000000
using namespace std;

vector< pair<int, int> > coin;

int main()
{
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		int type, target;
		cin >> type >> target;
		int dp[305][305] = {0};
		coin.clear();
		for (int i = 0 ; i < type ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			coin.push_back(make_pair(n1, n2));
		}
		for (int i = 0 ; i <= 300 ; ++i)
			for (int j = 0 ; j <= 300 ; ++j)
				dp[i][j] = INF;
		dp[0][0] = 0;
		for (int i = 0 ; i < coin.size() ; ++i)
		{
			for (int j = coin.at(i).first ; j <=  300 ; ++j)
				for (int k = coin.at(i).second ; k <= 300 ; ++k)
					dp[j][k] = min(dp[j][k], dp[j - coin.at(i).first][k - coin.at(i).second] + 1);
				
		}
		int min_value = INF;
		for (int i = 0 ; i <= target ; ++i)
		{
			for (int j = 0 ; j <= target ; ++j)
			{
				if (i*i + j*j == target*target)
					min_value = min(min_value, dp[i][j]);
			}
		}
		if (min_value == INF)
			cout << "not possible" << endl;
		else
			cout << min_value << endl;
	}
	return 0;
}
