#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#define INF 2000000
using namespace std;

typedef struct Vertex {
	double x;
	double y;
} vertex;


int N;

vector<vertex> list;
vector<int> adjacent[105];
bool visited[105];
double dist[105];
double cost;

void Prim(int cur)
{
	visited[cur] = true;
	for (int i = 0 ; i < adjacent[cur].size() ; ++i)
	{
		int index = adjacent[cur].at(i);
		if (visited[index])
			continue;
		double dx = abs(list.at(index).x - list.at(cur).x);
		double dy = abs(list.at(index).y - list.at(cur).y);
		double b = sqrt(dx*dx + dy*dy);
		dist[index] = min(dist[index], b);

	}
	for(int i = 0 ; i < N - 1 ; ++i)
	{
		double min_value = INF;
		int next_index = -1;
		for (int j = 0 ; j < N ; ++j)
		{
			if (visited[j])
				continue;
			if (min_value > dist[j])
			{
				min_value = dist[j];
				next_index = j;
			}
		}
		if (next_index == -1)
			break;
		visited[next_index] = true;
		cost = cost + min_value;
		for (int j = 0 ; j < adjacent[next_index].size() ; ++j)
		{
			int index = adjacent[next_index].at(j);
			if (visited[index])
				continue;
			double dx = abs(list.at(index).x - list.at(next_index).x);
			double dy = abs(list.at(index).y - list.at(next_index).y) ;
			double b = sqrt(dx*dx + dy*dy);
			dist[index] = min(dist[index], b);
		}
	}
}

void init()
{
	list.clear();
	for (int i = 0 ; i < 105 ; ++i)
	{
		adjacent[i].clear();
		dist[i] = INF;
	}
	memset(visited, false, sizeof(visited));
	cost = 0;
}

int main()
{
	int test_case;
	int index = 1;
	cin >> test_case;
	while(test_case--)
	{
		if (index != 1)
			cout << endl;
		index++;
		init();
		cin >> N;
		for (int i = 0 ; i < N ; ++i)
		{
			vertex v;
			cin >> v.x >> v.y;
			list.push_back(v);
		}
		for (int i = 0 ; i < N ; ++i)
			for (int j = 0 ; j < N ; ++j)
				if (i != j)
					adjacent[i].push_back(j);
		Prim(0);	
		printf("%.2f\n", cost);
	}
	return 0;
}
