#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 20000000
using namespace std;

typedef struct Edge {
	int from;
	int to;
	int cost;
} edge;

vector<edge> edges;
int parent[105];
int target;

int n, m;

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);
	parent[a] = b;
}

void kruskal()
{
	for(int i = 0, e = 0 ; i < edges.size() && e < n - 1 ; ++i)
	{
		if (Find(edges.at(i).from) != Find(edges.at(i).to))
		{
			Union(edges.at(i).from, edges.at(i).to);
			e++;
		}
		if (e == n - 1)
			target = edges.at(i).cost;
	}
}

void init()
{
	edges.clear();
	target = INF;
	for(int i = 0 ; i < 105 ; ++i)
		parent[i] = i;
}

bool compare(edge a, edge b)
{
	return a.cost > b.cost;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		cin >> n >> m;
		init();
		for(int j = 0 ; j < m ; ++j)
		{
			edge t;
			cin >> t.from >> t.to >> t.cost;
			edges.push_back(t);
		}
		sort(edges.begin(), edges.end(), compare);
		kruskal();
		cout << "Case #" << i+1 << ": " << target << endl;
	}
	return 0;
}
