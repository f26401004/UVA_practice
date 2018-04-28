#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adjacent[100005];
int N, M;
int dfn[100005];
int low[100005];
int DAG[100005];
int ans;
int dfns;
int sccs;
stack<int> stk;
bool instack[100005];

void DFS(int cur)
{
	int top;
	dfn[cur] = low[cur] = ++dfns;
	stk.push(cur);
	instack[cur] = true;
	for(int i = 0 ; i < adjacent[cur].size() ; ++i)
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
			DAG[top] = sccs;
		} while(top != cur);
		++sccs;
	}
}

void init()
{
	for (int i = 0 ; i < 100005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(DAG, 0, sizeof(DAG));
	memset(instack, false, sizeof(instack));
	ans = 0;
	dfns = 0;
	sccs = 0;
	while(stk.size() > 0)
		stk.pop();
}

int main()
{
	int test_case;
	scanf("%d", &test_case);
	while(test_case--)
	{
		init();
		cin >> N >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			int n1, n2;
			scanf("%d%d", &n1, &n2);
			adjacent[n1-1].push_back(n2-1);
		}
		for (int i = 0 ; i < N ; ++i)
		{
			if (!dfn[i])
			{
				DFS(i);
			}
		}
		int seq[N];
		memset(seq, 0, sizeof(seq));
		for (int i = 0 ; i < N ; ++i)
		{
			int u = DAG[i];
			for (int j = 0 ; j < adjacent[i].size() ; ++j)
				if (u != DAG[adjacent[i].at(j)])
					seq[DAG[adjacent[i].at(j)]]++;
		}
		for (int i = 0 ; i < sccs ; ++i)
			if (seq[i] == 0)
				++ans;
		cout << ans << endl;
	}
	return 0;
}
