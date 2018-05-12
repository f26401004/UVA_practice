#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 20000000
using namespace std;

typedef struct Edge {
	int from;
	int to;
	int cost;
	bool used;
} edge;
edge edges[30];
int n, m;
int cost_1, cost_2;
int ans;
int stackNum;

int Find(int x, int targetParent[])
{
	if (x == targetParent[x])
		return x;
	return targetParent[x] = Find(targetParent[x], targetParent);
}

void Union(int x, int y, int targetParent[])
{
	int a = Find(x, targetParent);
	int b = Find(y, targetParent);
	targetParent[b] = a;
}

bool compare(edge a, edge b)
{
	return a.cost < b.cost;
}

void kruskal(int index, int e_num, int currentCost, int targetParent[])
{
	if (currentCost >= ans) 
		return;
	if (e_num == n - 1)
	{
		int count = 0;
		int tempParent[15];
		for(int i = 0 ; i < 15 ; ++i)
			tempParent[i] = i;
		for(int i = 1 ; i < m && count < n - 1 ; ++i)
		{
			if (edges[i].used)
				continue;
			if (Find(edges[i].from, tempParent) != Find(edges[i].to, tempParent))
			{
				Union(edges[i].from, edges[i].to, tempParent);
				currentCost = currentCost + edges[i].cost;
				count++;
			}
		}
		if (count != n - 1)
			return;
		if (ans > currentCost)
			ans = currentCost;
		return;
	}
	for(int i = index; i < m ; ++i)
	{
		if (Find(edges[i].from, targetParent) != Find(edges[i].to, targetParent))
		{
			int tempParent[15];
			for(int j = 0 ; j < 15 ; ++j)
				tempParent[j] = targetParent[j];
			Union(edges[i].from, edges[i].to, tempParent);
			edges[i].used = true;
			kruskal(i + 1, e_num + 1, currentCost + edges[i].cost, tempParent);
			edges[i].used = false;
		}
	}
}

void init()
{
	ans = INF;
	stackNum = 0;
}

int main()
{
	while(cin >> n)
	{
		init();
		if (n == 0)
			break;
		cin >> m;
		for(int i = 0 ; i < m ; ++i)
		{
			scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].cost);
			edges[i].used = false;
		}
		sort(edges, edges + m, compare);
		int parent[15];
		for(int i = 0 ; i < 15 ; ++i)
			parent[i] = i;
		Union(edges[0].from, edges[0].to, parent);
		edges[0].used = true;
		kruskal(1, 1, edges[0].cost, parent);
		if (ans >= INF)
			printf("No way!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
