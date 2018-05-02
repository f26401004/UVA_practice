#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int n, m;
map<string, int> id;
string numberToString[30];
int dfn[30];
int low[30];
int dfns;
vector<int> adjacent[30];
stack<int> stk;
int instack[30];
vector<int> ans[30];
int sccs;

void DFS(int cur)
{
	int top;
	dfn[cur] = low[cur] = dfns++;
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
		do {
			top = stk.top();
			stk.pop();
			instack[top] = false;
			ans[sccs].push_back(top);
		} while(top != cur);
		sccs++;
	}
}

void init()
{
	id.clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	for (int i = 0 ; i < 30 ; ++i)
	{
		adjacent[i].clear();
		ans[i].clear();
		numberToString[i] = "";
	}
	while(stk.size() > 0)
		stk.pop();
	dfns = 1;
	sccs = 0;
}

int main()
{
	int index = 1;
	while(cin >> n >> m)
	{
		init();
		int number = 1;
		if (n == 0 && m == 0)
			break;
		for(int i = 0 ; i < m ; ++i)
		{
			string n1, n2;
			cin >> n1 >> n2;
			if (!id[n1])
			{
				numberToString[number] = n1;
				id[n1] = number++;
			}
			if (!id[n2])
			{
				numberToString[number] = n2;
				id[n2] = number++;
			}
			adjacent[id[n1]].push_back(id[n2]);
		}
		cout << "Calling circles for data set " << index++ << ":" << endl;
		for (int i = 1 ; i <= n ; ++i)
			if (!dfn[i])
				DFS(i);
		for (int i = sccs - 1 ; i > -1 ; --i)
		{
			for (int j = 0 ; j < ans[i].size() ; ++j)
			{
				cout << numberToString[ans[i].at(j)];
				if (j != ans[i].size() - 1)
					cout << ", ";
			}
			cout << endl;
		}
	}
	return 0;
}
