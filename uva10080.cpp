#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef struct Node
{
	double x;
	double y;
} node;

typedef struct Edge
{
	int from;
	int to;
	double distance;
} edge;

int n, m, s, v;
vector<node> nodesL;
vector<node> nodesR;
vector<edge> edges[105];
bool used[105];
int rlink[105], llink[105];

bool DFS(int cur)
{
	for(int i = 0 ; i < edges[cur].size() ; ++i)
	{
		if (used[edges[cur].at(i).to])
			continue;
		used[edges[cur].at(i).to] = true;
		if (rlink[edges[cur].at(i).to] == -1 || DFS(rlink[edges[cur].at(i).to]))
		{
			llink[cur] = edges[cur].at(i).to;
			rlink[edges[cur].at(i).to] = cur;
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

	for(int i = 0 ; i < nodesL.size() ; ++i)
	{
		memset(used, false, sizeof(used));
		if (DFS(i))
			ans++;	
	}
	return ans;
}

void init()
{
	nodesL.clear();
	nodesR.clear();
	for(int i = 0 ; i < 105 ; ++i)
		edges[i].clear();
}

int main()
{
	while(cin >> n)
	{
		cin >> m >> s >> v;
		init();
		for(int i = 0 ; i < n ; ++i)
		{
			node n;
			cin >> n.x >> n.y;
			nodesL.push_back(n);
		}
		for(int i = 0 ; i < m ; ++i)
		{
			node n;
			cin >> n.x >> n.y;
			nodesR.push_back(n);
		}
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < m ; ++j)
			{
				edge e;
				e.from = i;
				e.to = j;
				double dx = nodesL.at(i).x - nodesR.at(j).x;
				double dy = nodesL.at(i).y - nodesR.at(j).y;
				e.distance = sqrt(dx*dx + dy*dy);
				if (e.distance / v <= s)
					edges[i].push_back(e);
			}
		}
		cout << n - Bipartite() << endl;
	}
	return 0;
}
