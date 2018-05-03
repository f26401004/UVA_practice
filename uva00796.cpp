#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> adjacent[2000000];
int dfn[2000000];
int dfns;
vector< pair<int, int> > ans;


int DFS(int cur, int prev)
{
	dfn[cur] = dfns++;
	int min_value = dfn[cur];
	for (int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			int b = DFS(adjacent[cur].at(i), cur);
			if (b > dfn[cur])
				ans.push_back(cur > adjacent[cur].at(i) ? make_pair(adjacent[cur].at(i), cur) : make_pair(cur, adjacent[cur].at(i)));
			min_value = min(min_value, b);
		}
		else
		{
			if (adjacent[cur].at(i) != prev)
				min_value = min(min_value, dfn[adjacent[cur].at(i)]);
		}
	}
	return min_value;
}

void init()
{
	for (int i = 0 ; i < 10005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	dfns = 1;
	ans.clear();
}

int main()
{
	int test_case = 1;
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			cout << "0 critical links" << endl;
			cout << endl;
			continue;
		}
		init();
		int server, num;
		for(int i = 0 ; i < n ; ++i)
		{
			scanf("%d (%d)", &server, &num);
			for (int j = 0 ; j < num ; ++j)
			{
				int n1;
				scanf("%d", &n1);
				adjacent[server].push_back(n1);
			}
		}
		for (int i = 0 ; i < n ; ++i)
			if (!dfn[i])
				DFS(i, -1);
		sort(ans.begin(), ans.end());
		cout << ans.size() << " critical links" << endl;
		for(int i = 0 ; i < ans.size() ; ++i)
			cout << ans.at(i).first << " - " << ans.at(i).second << endl;
		cout << endl;
	}
	return 0;
}
