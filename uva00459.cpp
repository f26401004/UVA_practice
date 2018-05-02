#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;

vector<int> adjacent[30];
int dfn[30];
int low[30];
int dfns;
int ans;
int max_int;
stack<int> stk;
bool instack[30];

void DFS(int cur)
{
	dfn[cur] = low[cur] = dfns++;
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
		int top;
		do {
			top = stk.top();
			stk.pop();
			instack[top] = false;
		} while(top != cur);
		++ans;
	}
}

void init()
{
	for(int i = 0 ; i < 30 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, false, sizeof(instack));
	dfns = 0;
	ans = 0;
	max_int = 0;
	while(stk.size() > 0)
		stk.pop();
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int j = 0 ; j < test_case ; ++j)
	{
		init();
		if (j != 0)
			cout << endl;
		char max_c;
		cin >> max_c;
		cin.get();
		max_int = max_c - 'A' + 1;
		char list[20];
		while(fgets(list, sizeof(list), stdin))
		{
			if (list[0] == '\n')
				break;
			adjacent[list[0] - 'A' + 1].push_back(list[1] - 'A' + 1);
			adjacent[list[1] - 'A' + 1].push_back(list[0] - 'A' + 1);
		}
		for (int i = 1 ; i <= max_int ; ++i)
			if (!dfn[i])
				DFS(i);
		cout << ans << endl;
	}
	return 0;
}
