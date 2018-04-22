#include <iostream>
#define INF 2000000
using namespace std;

typedef struct {
	int start;
	int end;
	int cost;
} edge;



int N, M;

edge edges[2005];
int dist[1005];

bool Relax(int j, int k, int cost)
{
	if (dist[k] > dist[j] + cost)
	{
		dist[k] = dist[j] + cost;
		return true;
	}
	return false;
}

bool BellmanFord()
{
	dist[0] = 0;
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < M ; ++j)
			Relax(edges[j].start, edges[j].end, edges[j].cost);
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < M ; ++j)
			if (Relax(edges[j].start, edges[j].end, edges[j].cost))
				return true;
	return false;	
}

int main()
{
	int C;
	cin >> C;
	while(C--)
	{
		cin >> N >> M;
		for (int i = 0 ; i < M ; ++i)
			cin >> edges[i].start >> edges[i].end >> edges[i].cost;
		if (BellmanFord())
			cout << "possible" << endl;
		else
			cout << "not possible" << endl;
	}
	return 0;
}
