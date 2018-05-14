#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adjacent[1005];
int dfn[1005];
int low[1005];
int dfns;
vector< pair<int, int> > link;

int n, m;

void DFS(int cur, int prev)
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
				int v = adjacent[cur].at(i);
				if (v > cur)
					link.push_back(make_pair(cur, v));
				else
					link.push_back(make_pair(v, cur));
			}
		}
		else if (adjacent[cur].at(i) != prev)
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
}

void init()
{
	for(int i = 0 ; i < 1005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	dfns = 1;
	link.clear();
}

int main()
{
	while(cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		init();
		for(int i = 0 ; i < m ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjacent[n1].push_back(n2);
			adjacent[n2].push_back(n1);
		}
		for(int i = 0 ; i < n ; ++i)
			if (!dfn[i])
				DFS(i, -1);
		sort(link.begin(), link.end());
		cout << link.size();
		for(int i = 0 ; i < link.size() ; ++i)
			cout << " " << link.at(i).first << " " << link.at(i).second;
		cout << endl;
	}
	return 0;
}
