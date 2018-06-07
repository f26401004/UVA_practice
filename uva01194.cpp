#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> edges[105];
int llink[105], rlink[105];
bool used[105];

int n, m, k;

bool DFS(int cur)
{
	for(int i = 0 ; i < edges[cur].size() ; ++i)
	{
		if (used[edges[cur].at(i)])
			continue;
		used[edges[cur].at(i)] = true;
		if (rlink[edges[cur].at(i)] == -1 || DFS(rlink[edges[cur].at(i)]))
		{
			llink[cur] = edges[cur].at(i);
			rlink[edges[cur].at(i)] = cur;
			return true;
		}
	}
	return false;
}

int Bipartite()
{
	int ans = 0;
	memset(rlink, -1, sizeof(rlink));
	memset(llink, -1, sizeof(llink));
		
	for(int i = 0 ; i < n ; ++i)
	{
		memset(used, false, sizeof(used));
		if (DFS(i))
			ans++;
	}
	return ans;
}


void init()
{
	for(int i = 0 ; i < 105 ; ++i)
		edges[i].clear();
	
}

int main()
{
	while(cin >> n)
	{
		if (n == 0)
			break;
		init();
		cin >> m >> k;
		for(int i = 0 ; i < k ; ++i)
		{
			int num, a, b;
			cin >> num >> a >> b;
			if (a == 0 || b == 0)
				continue;
			edges[a].push_back(b);
		}
		cout << Bipartite() << endl;
	}
	return 0;
}
