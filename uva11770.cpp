#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adjacent[10005];
int dfn[10005];
int low[10005];
stack<int> stk;
int instack[10005];
int dfns;
int DAG[10005];
int ans;
int sccs;

int N, M;


void DFS(int cur)
{
	dfn[cur] = low[cur] = dfns++;
	instack[cur] = true;
	stk.push(cur);
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
		int top;
		do {
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
	for(int i = 0 ; i < 10005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, false, sizeof(instack));
	memset(DAG, -1, sizeof(DAG));
	dfns = 1;
	ans = 0;
	sccs = 0;
	while(stk.size() > 0)
		stk.pop();

}

int main()
{
	int test_case;
	cin >> test_case;
	for(int i = 0 ; i < test_case ; ++i)
	{
		init();
		cin >> N >> M;
		for(int j = 0 ; j < M ; ++j)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjacent[n1].push_back(n2);
		}
		for (int j = 1 ; j <= N ; ++j)
			if (!dfn[j])
				DFS(j);
		int seq[10005];
		memset(seq, 0, sizeof(seq));
		for(int j = 1 ; j <= N ; ++j)
		{
			for(int k = 0 ; k < adjacent[j].size() ; ++k)
				if (DAG[j] != DAG[adjacent[j].at(k)])
					seq[DAG[adjacent[j].at(k)]]++;
		}
		for (int j = 0 ; j < sccs ; ++j)
			if (seq[j] == 0)
				ans++;
		cout << "Case " << i+1 << ": " << ans << endl;
	}	
	return 0;
}
