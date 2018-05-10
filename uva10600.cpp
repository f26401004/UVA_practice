#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 2000000
using namespace std;

int adjacent[105][105];
int path[105][105];
int previous[105];
bool edgeUse[105][105];
bool visited[105];
int dist[105];
int cost_1, cost_2;
int N, M;

void prim()
{
	dist[1] = 0;
	for(int i = 2 ; i <= N ; ++i)
		dist[i] = adjacent[1][i];
	for(int i = 1 ; i <= N ; ++i)
	{
		int min_index, min_value = INF;
		for(int j = 1 ; j <= N ; ++j)
			if (min_value > dist[j] && !visited[j])
			{
				min_value = dist[j];
				min_index = j;
			}
		edgeUse[previous[min_index]][min_index] = edgeUse[min_index][previous[min_index]] = true;
		visited[min_index] = true;
		cost_1 = cost_1 + min_value;
		for(int j = 1 ; j <= N ; ++j)
		{
			if(visited[j] && j != min_index) 
				path[min_index][j] = path[j][min_index] = max(min_value, path[j][previous[min_index]]);
			if (dist[j] > adjacent[min_index][j] && !visited[j])
			{
				dist[j] = adjacent[min_index][j];
				previous[j] = min_index;
			}
		}
	}
	cost_2 = INF;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j)
		{
			if (edgeUse[i][j])
				continue;
			cost_2 = min(cost_2, cost_1 + adjacent[i][j] - path[i][j]);
		}
}

void init()
{
	for(int i = 0 ; i < 105 ; ++i)
	{
		dist[i] = INF;
		for(int j = 0 ; j < 105 ; ++j)
		{
			adjacent[i][j] = INF;
			path[i][j] = 0;
		}
		previous[i] = 1;
	}
	memset(edgeUse, false, sizeof(edgeUse));
	memset(visited, false, sizeof(visited));
	cost_1 = cost_2 = 0;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		init();
		cin >> N >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			int n1, n2, c;
			cin >> n1 >> n2 >> c;
			adjacent[n1][n2] = adjacent[n2][n1] = c;
		}
		prim();
		cout << cost_1 << " " << cost_2 << endl;
	}
	return 0;
}
