#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int main() 
{
	bool first = true;
	int t, w;
	vector< pair<int, int> > result;
	while(cin >> t >> w)
	{
		if (!first)
			cout << endl;
		else
			first = !first;
		result.clear();
		int num;
		cin >> num;
		int dp[t + 1];
		int cost[num];
		int value[num];
		bool put[num][t + 1];
		memset(dp, 0, sizeof(dp));
		memset(cost, 0, sizeof(cost));
		memset(value, 0, sizeof(value));
		memset(put, false, sizeof(put));
		for(int i=  0 ; i < num ; ++i)
			cin >> cost[i] >> value[i];
		for (int i = 0 ; i < num ; ++i)
		{
			for(int j = t ; j >= cost[i] * 3 * w ; --j)
			{
				if (dp[j - cost[i] * 3 * w] + value[i] > dp[j])
				{
					dp[j] = dp[j - cost[i] * 3 * w] + value[i];
					put[i][j] = true;
				}
			}
		}
		int total = 0;
		for(int i = num - 1, j = t ; i >= 0 ; --i)
			if (put[i][j])
			{
				result.push_back(make_pair(cost[i], value[i]));
				total = total + value[i];
				j = j - cost[i] * 3 * w;
			}
		cout << total << endl;
		cout << result.size() << endl;
		for(int i = result.size() - 1 ; i > -1 ; --i)
			cout << result.at(i).first << " " << result.at(i).second << endl;
	}
	return 0;
}
