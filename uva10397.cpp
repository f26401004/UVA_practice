#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define INF 2000000
using namespace std;

vector< pair<int, int> > build;
double adjacent[755][755];
bool visited[755];
double dist[755];
double cost;
int N, M;

void prim()
{
	dist[1] = 0;
	visited[1] = true;
	for(int i = 2 ; i <= N ; ++i)
		dist[i] = min(dist[i], adjacent[1][i]);
	for(int i = 2 ; i <= N ; ++i)
	{
		int min_index;
		double min_value = INF;
		for(int j = 1 ; j <= N ; ++j)
		{
			if (min_value > dist[j] && !visited[j])
			{
				min_value = dist[j];
				min_index = j;
			}
		}
		visited[min_index] = true;
		cost = cost + min_value;
		for(int j = 1 ; j <= N ; ++j)
		{
			if (dist[j] > adjacent[min_index][j] && !visited[j])
				dist[j] = adjacent[min_index][j];
		}
	}
}

void init()
{
	build.clear();
	for(int i = 0 ; i < 755 ; ++i)
	{
		dist[i] = INF;
		for(int j = 0 ; j < 755 ; ++j)
			adjacent[i][j] = INF;
	}
	memset(visited, false, sizeof(visited));
	cost = 0;
}

int main()
{
	while(cin >> N)
	{
		init();
		for(int i = 0 ; i < N ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			build.push_back(make_pair(n1, n2));
		}
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < N ; ++j)
				if (i != j)
				{
					int x = abs(build.at(i).first - build.at(j).first);
					int y = abs(build.at(i).second - build.at(j).second);
					double distance = sqrt(x*x + y*y);
					adjacent[i+1][j+1] = adjacent[j+1][i+1] = distance;
				}
		cin >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjacent[n1][n2] = adjacent[n2][n1] = 0;
		}
		prim();
		printf("%.2f\n", cost);
	}
	return 0;
}
