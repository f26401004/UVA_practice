#include <iostream>
#include <algorithm>
#define INF 2000000
using namespace std;

typedef struct {
	int start;
	int end;
	int cost;
} edge;

int N, S, edge_size;
int dist[105];
edge edges[5000];

void init()
{
	for (int i = 0 ; i < 105 ; ++i)
		dist[i] = INF;
	dist[S - 1] = 0;
	edge_size = 0;
}

void Relax(int j, int k, int cost)
{
	if (dist[k] > dist[j] + cost)
		dist[k] = dist[j] + cost;
}

void BellmanFord()
{
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < edge_size ; ++j)
			Relax(edges[j].start, edges[j].end, edges[j].cost);
}

int main()
{
	int case_num = 1;
	while(cin >> N)
	{
		if (N == 0)
			break;
		cin >> S;
		init();
		int p, q;
		while(cin >> p >> q)
		{
			if (p == 0 && q == 0)
				break;
			edges[edge_size].start = p - 1;
			edges[edge_size].end = q - 1;
			edges[edge_size].cost = -1;
			++edge_size;
		}
		BellmanFord();
		int min = INF;
		int min_index = 0;
		for (int i = 0 ; i < N ; ++i)
			if (min > dist[i])
			{
				min = dist[i];
				min_index = i + 1;
			}
		cout << "Case " << case_num++ << ": The longest path from " << S << " has length "<< -min  << ", finishing at "<< min_index << "." << endl;
		cout << endl;
	}
	return 0;
}
