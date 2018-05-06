#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dfn[30];
int low[30];
vector<int> adjacent[30];
int dfns;
stack<int> stk;
bool instack[30];
vector< vector<int> > ans;

void DFS(int cur)
{
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
		int top;
		vector<int> buffer;
		do {
			top = stk.top();
			stk.pop();
			instack[top] = false;
			buffer.push_back(top);
		} while(top != cur);
		ans.push_back(buffer);
	}
}

void init()
{
	for (int i = 0 ; i < 30 ; ++i)
		adjacent[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, false, sizeof(instack));
	dfns = 1;
	while(stk.size() > 0)
		stk.pop();
	ans.clear();
}

bool compare(vector<int> a, vector<int> b)
{
	return a.at(0) < b.at(0);
}

int main()
{
	int index = 1;
	while(cin >> n)
	{
		if (n == 0)
			break;
		if (index != 1)
			cout << endl;
		index++;
		init();
		char list[5];
		bool allchoice[26] = {false};
		for (int i = 0 ; i < n ; ++i)
		{
			for (int j = 0 ; j < 5 ; ++j)
			{
				cin >> list[j];
				allchoice[list[j] - 'A'] = true;
			}
			char ans;
			cin >>  ans;
			for (int j = 0 ; j < 5 ; ++j)
			{
				if (list[j] == ans)
					continue;
				adjacent[ans - 'A'].push_back(list[j] - 'A');
			}
		}
		for (int i = 0 ; i < 26 ; ++i)
			if (!dfn[i] && allchoice[i])
				DFS(i);
		for (int i = 0 ; i < ans.size() ; ++i)
			sort(ans.at(i).begin(), ans.at(i).end());
		sort(ans.begin(), ans.end(), compare);
		for (int i = 0 ; i < ans.size() ; ++i)
		{
			cout << (char)('A' + ans.at(i).at(0));
			for (int j = 1 ; j < ans.at(i).size() ; ++j)
				cout << " " <<  (char)('A' + ans.at(i).at(j));
			cout << endl;
		}
	}	
	return 0;
}
