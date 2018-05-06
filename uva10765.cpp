#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<int> adjacent[10005];
int dfn[10005];
int low[10005];
int dfns;
map<int, int>ans;

int DFS(int cur, int prev)
{
	dfn[cur] = low[cur] = dfns++;
	for(int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(adjacent[cur].at(i), cur);
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
			if (low[adjacent[cur].at(i)] > dfn[cur])
			{
				ans[cur] = ans[cur] + 1;	
				ans[adjacent[cur].at(i)] = ans[adjacent[cur].at(i)] + 1;
			}
		}
		else if (adjacent[cur].at(i) != prev)
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
}

void init()
{
	for (int i = 0 ; i < 10005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	dfns = 1;
	ans.clear();
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	while(cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		init();
		int n1, n2;
		while(cin >> n1 >> n2)
		{
			if (n1 == -1 && n2 == -1)
				break;
			adjacent[n1].push_back(n2);
			adjacent[n2].push_back(n1);
		}
		for (int i = 0 ; i < n ; ++i)
			if (!dfn[i])
				DFS(i, -1);
		for (int i = 0 ; i < n ; ++i)
			if (ans[i] != adjacent[i].size())
				ans[i]++;
		vector< pair<int, int> > buffer(ans.begin(), ans.end());
		sort(buffer.begin(), buffer.end(), compare);
		for (int i = 0 ; i < m ; ++i)
			cout << buffer.at(i).first << " " << buffer.at(i).second << endl;
		cout << endl;
	}

	return 0;
}
