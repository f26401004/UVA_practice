#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

vector<int> adjacent[1005];
vector<int> DAGAdjacent[1005];
int dfn[1005];
int low[1005];
int set[1005];
int dfns;
stack<int> stk;
bool instack[1005];
int DAGNumber[1005];
int sccs;
int dp[1005];

int n, m;


void DFS(int cur, int prev)
{
	stk.push(cur);
	instack[cur] = true;
	dfn[cur] = low[cur] = dfns++;
	for(int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(adjacent[cur].at(i), cur);
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
		}
		else if (instack[adjacent[cur].at(i)])
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
	if (dfn[cur] == low[cur])
	{
		int top;
		do {
			top = stk.top();
			stk.pop();
			instack[top] = false;
			set[top] = sccs;
			++DAGNumber[sccs];
		} while(top != cur);
		sccs++;
	}
}

void find_path(int cur)
{
	if (dp[cur] != -1) 
		return;
	dp[cur] = 0;
	for(int i = 0 ; i < DAGAdjacent[cur].size() ; ++i)
	{
		find_path(DAGAdjacent[cur].at(i));
		dp[cur] = max(dp[cur], dp[DAGAdjacent[cur].at(i)]);
	}
	dp[cur] = dp[cur] + DAGNumber[cur];
}

void init()
{
	for(int i = 0 ; i < 1005 ; ++i)
	{
		adjacent[i].clear();
		DAGAdjacent[i].clear();
	}
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(set, -1, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(dp, -1, sizeof(dp));
	memset(DAGNumber, 0, sizeof(DAGNumber));
	dfns = 1;
	sccs = 0;
	while(stk.size() > 0)
		stk.pop();
}


int main()
{
	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		init();
		cin >> n >> m;
		for (int i = 0 ; i < m ; ++i)
		{
			int v1, v2;
			cin >> v1 >> v2;
			adjacent[v1].push_back(v2);
		}
		for(int i = 1 ; i <= n ; ++i)
			if (!dfn[i])
			{
				dfns = 1;
				DFS(i, -1);
			}
		for (int i = 1 ; i <= n ; ++i)
		{
			for(int j = 0 ; j < adjacent[i].size() ; ++j)
			{
				if (set[i] != set[adjacent[i].at(j)])
					DAGAdjacent[set[i]].push_back(set[adjacent[i].at(j)]);
			}
		}
		for(int i = 0 ; i < sccs ; ++i)
			if (dp[i] == -1)
				find_path(i);
		int ans = 0;
		for(int i = 0 ; i < sccs ; ++i)
			ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	return 0;
}

