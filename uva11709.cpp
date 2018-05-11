#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

vector<int> adjacent[1005];
map<string, int> namemap;
int dfn[1005];
int low[1005];
int dfns;
stack<int> stk;
bool instack[1005];
int ans;

int P, T;

void DFS(int cur)
{
	stk.push(cur);
	instack[cur] = true;
	dfn[cur] = low[cur] = dfns++;
	for(int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(adjacent[cur].at(i));
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
		}
		else if(instack[adjacent[cur].at(i)])
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
	for(int i = 0 ; i < 1005 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, false, sizeof(instack));
	dfns = 1;
	ans = 0;
	while(stk.size() > 0)
		stk.pop();
	namemap.clear();
}

int main()
{
	while(cin >> P >> T)
	{
		cin.get();
		if (P == 0 && T == 0)
			break;
		init();
		for (int i = 0 ; i < P ; ++i)
		{
			char list[100];
			fgets(list, sizeof(list), stdin);
			string str(list);
			namemap[str] = i;
		}
		for (int i = 0 ; i < T ; ++i)
		{
			char n1[100];
			char n2[100];		
			fgets(n1, sizeof(n1), stdin);
			fgets(n2, sizeof(n2), stdin);
			string str1(n1), str2(n2);
			adjacent[namemap[str1]].push_back(namemap[str2]);
		}
		for(int i = 0 ; i < P ; ++i)
			if (!dfn[i])
				DFS(i);
		cout << ans << endl;
	}	
	return 0;
}
