#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N;
map<string, int> id;
string numberToString[105];
vector<int> adjacent[105];
int dfn[105];
int low[105];
int dfns;
vector<string> ans;

void DFS(int cur, int prev)
{
	bool cut = false;
	int child = 0;
	dfn[cur] = low[cur] = dfns++;
	for (int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		if (!dfn[adjacent[cur].at(i)])
		{
			DFS(adjacent[cur].at(i), cur);
			low[cur] = min(low[cur], low[adjacent[cur].at(i)]);
			if (low[adjacent[cur].at(i)] >= dfn[cur])
				cut = true;
			++child;
		}
		else if (adjacent[cur].at(i) != prev)
			low[cur] = min(low[cur], dfn[adjacent[cur].at(i)]);
	}
	if ((child > 1 || prev != -1) && cut)
		ans.push_back(numberToString[cur]);
	
}

void init()
{
	for(int i = 0 ; i < 105 ; ++i)
	{
		adjacent[i].clear();
		numberToString[i] = "";
	}
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	dfns = 1;
	ans.clear();
	id.clear();
}

int main()
{
	int test_case = 1;
	while(cin >> N)
	{
		if (N == 0)
			break;
		if (test_case != 1)
			cout << endl;
		init();
		for (int i = 1 ; i <= N ; ++i)
		{
			string n;
			cin >> n;
			numberToString[i] = n;
			id[n] = i;
		}
		int road_num;
		cin >> road_num;
		for (int i = 0 ; i < road_num ; ++i)
		{
			string n1, n2;
			cin >> n1 >> n2;
			adjacent[id[n1]].push_back(id[n2]);
			adjacent[id[n2]].push_back(id[n1]);
		}
		for (int i = 1 ; i <= N ; ++i)
			if (!dfn[i])
				DFS(i, -1);
		sort(ans.begin(), ans.end());
		cout << "City map #" << test_case++ << ": " << ans.size() << " camera(s) found" << endl;
		for (int i = 0 ; i < ans.size() ; ++i)
			cout << ans.at(i) << endl;
			
	}	
	return 0;
}
