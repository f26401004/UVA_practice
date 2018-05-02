#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<int> adjacent[1005];
int dfn[1005];
int low[1005];
bool visited[1005];
int dfns;

int DFS(int cur, int prev)
{
	visited[cur] = true;
	dfn[cur] = dfns++;
	int min_value = dfn[cur];
	for(int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!visited[adjacent[cur].at(i)])
		{
			int b = DFS(adjacent[cur].at(i), cur);
			if (b > dfn[cur])
			{
				cout << cur << " " << adjacent[cur].at(i) << endl;
				cout << adjacent[cur].at(i) << " " << cur << endl;
			}
			else
				cout << cur << " " << adjacent[cur].at(i) << endl;
			min_value = min(min_value, b);
		}
		else
		{
			if (adjacent[cur].at(i) != prev)
			{
				if (dfn[cur] >= dfn[adjacent[cur].at(i)])
					cout << cur << " " << adjacent[cur].at(i) << endl;
				min_value = min(min_value, dfn[adjacent[cur].at(i)]);
			}
		}
	}
	return min_value;
}

void init()
{
	for(int i = 0 ; i < 1005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(visited, false, sizeof(visited));
	dfns = 1;
}

int main()
{
	int test_case = 1;
	while(cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		cout << test_case++ << endl << endl;
		init();
		for(int i = 0 ; i < m ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjacent[n1].push_back(n2);
			adjacent[n2].push_back(n1);
		}
		for(int i = 1 ; i <= n ; ++i)
			if (!dfn[i])
			{
				dfns = 0;
				DFS(i, -1);
			}
		cout << "#" << endl;
	}
	return 0;
}
