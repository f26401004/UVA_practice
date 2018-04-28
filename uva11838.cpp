#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M;
vector<int> adjacent[2005];
int dfn[2005];
int low[2005];
int ans;
int dfns;
stack<int> stk;
bool instack[2005];

void DFS(int cur)
{
	int top;
	dfn[cur] = low[cur] = ++dfns;
	stk.push(cur);
	instack[cur] = true;
	for (int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(adjacent[cur].at(i));
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
		}
		else if (instack[adjacent[cur].at(i)])
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
	if (dfn[cur] == low[cur])
	{
		do
		{
			top = stk.top();
			stk.pop();
			instack[top] = false;
		} while(top != cur);
		++ans;
	}
}

void init()
{
	for(int i = 0 ; i < 2005 ; ++i)
		adjacent[i].clear();
	ans = 0;
	dfns = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, false, sizeof(instack));
	while(stk.size() > 0)
		stk.pop();
}

int main()
{
	while(cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;
		init();
		int V, W, P;
		for (int i = 0 ; i < M ; ++i)
		{
			cin >> V >> W >> P;
			adjacent[V-1].push_back(W-1);
			if (P == 2)
				adjacent[W-1].push_back(V-1);
		}
		
		DFS(1);
		bool flag = true;
		for (int i = 0 ; i < N ; ++i)
			if (dfn[i] == 0)
			{
				flag = false;
				break;
			}
		if (ans == 1 && flag)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
