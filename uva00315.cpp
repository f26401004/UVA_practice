#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int N;
int ans;
int dfn[105];
int low[105];
int dfsn;
vector<int> adjacent[105];

void DFS(int prev, int cur)
{
	bool cut = false;
	int child = 0;
	low[cur] = dfn[cur] = ++dfsn;
	for (int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(cur, adjacent[cur].at(i));
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
			if (low[adjacent[cur].at(i)] >= dfn[cur])
				cut = true;
			++child;
		}
		else if (adjacent[cur].at(i) != prev)
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
	if ((child > 1 || prev != -1) && cut)
		++ans;
}

int main()
{
	while(cin >> N)
	{
		if (N == 0)
			break;
		for (int i = 0 ; i < 105 ; ++i)
			adjacent[i].clear();
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		dfsn = 0;		
		ans = 0;
		int start;
		int edge_size = 0;
		while(cin >> start)
		{
			if (start == 0)
				break;
			char list[1024];
			fgets(list, sizeof(list), stdin);
			stringstream sin(list);
			int target;
			while(sin >> target)
			{
				adjacent[start].push_back(target);
				adjacent[target].push_back(start);
			}
		}
		DFS(-1, 1);
		cout << ans << endl;
	}
	return 0;
}
