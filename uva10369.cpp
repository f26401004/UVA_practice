#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

typedef struct Edge {
	int from;
	int to;
	double cost;
} edge;

vector<edge> edges;
vector< pair<int, int> > point;
vector<double> chooseEdges;
int parent[10005];
double D;
int N, S, P;

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int x = Find(a);
	int y = Find(b);
	parent[y] = x;
}

void kruskal()
{
	for(int i = 0, e_num = 0 ; i < edges.size() && e_num < P - 1 ; ++i)
	{
		if (Find(edges.at(i).from) != Find(edges.at(i).to))
		{
			Union(edges.at(i).from, edges.at(i).to);
			chooseEdges.push_back(edges.at(i).cost);
			++e_num;
		}
	}
	D = chooseEdges.at(P - S - 1);
}

void init()
{
	for(int i = 0; i < 10005 ; ++i)
		parent[i] = i;
	D = 0;
	edges.clear();
	point.clear();
	chooseEdges.clear();
}

bool compare(edge a, edge b)
{
	return a.cost < b.cost;
}


int main()
{
	cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		init();
		cin >> S >> P;
		for(int j = 0 ; j < P ; ++j)
		{
			int x, y;
			cin >> x >> y;
			point.push_back(make_pair(x, y));
		}	
		for(int j = 0 ; j < P ; ++j)
		{
			for(int k = j + 1 ; k < P ; ++k)
			{
				int dx = point.at(j).first - point.at(k).first;
				int dy = point.at(j).second - point.at(k).second;
				double cost = sqrt(dx*dx + dy*dy);
				edge e;
				e.from = j;
				e.to = k;
				e.cost = cost;
				edges.push_back(e);
			}
		}
		sort(edges.begin(), edges.end(), compare);
		kruskal();
		printf("%.2f\n", D);
	}
	return 0;
}
