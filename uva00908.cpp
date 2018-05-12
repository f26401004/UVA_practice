#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Edge {
	int from;
	int to;
	int cost;
} edge;

vector<edge> edges;
int parent[1000005];
int cost;
int o_cost;

int N, M, K;

int Find(int x)
{
	if (x == parent[x]) 
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);
	parent[b] = a;
}

bool compare(edge a, edge b)
{
	return a.cost < b.cost;
}

void kruslal()
{
	sort(edges.begin(), edges.end(), compare);
	for(int i = 0, e_num = 0 ; i < edges.size() && e_num < N - 1; ++i)
	{
		edge e = edges.at(i);
		if (Find(edges.at(i).from) != Find(edges.at(i).to))
		{
			Union(e.from, e.to);
			cost = cost + e.cost;
		}
	}
}

void init()
{
	for(int i = 0 ; i < 1000005 ; ++i)
		parent[i] = i;
	edges.clear();
	cost = 0;
	o_cost = 0;
}

int main()
{
	int index = 0;
	while(cin >> N)
	{
		if (index != 0)
			cout << endl;
		index++;
		init();
		for(int i = 0 ; i < N - 1 ; ++i)
		{
			edge e;
			cin >> e.from >> e.to >> e.cost;
			o_cost = o_cost + e.cost;
		}
		cin >> K;
		for(int i = 0 ; i < K ; ++i)
		{
			edge e;
			cin >> e.from >> e.to >> e.cost;
			edges.push_back(e);	
		}
		cin >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			edge e;
			cin >> e.from >> e.to >> e.cost;
			edges.push_back(e);
		}
		kruslal();
		cout << o_cost << endl << cost << endl;	
	}
	return 0;
}
