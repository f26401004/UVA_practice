#include <iostream>
#include <queue>
#define INF 2000000
using namespace std;

typedef struct Edge {
	int start;
	int end;
	int cost;
	struct Edge* next;
} edge;

typedef struct EdgeNode {
	struct Edge* next;
} edgenode;

int n, m, start, target;
edgenode* edges[20005];
int dist[20005];

void init()
{
	for (int i = 0 ; i < 20005 ; ++i)
	{
		dist[i] = INF;
		edges[i] = new edgenode;
		edges[i]->next = NULL;
	}
}

void BellmanFord()
{
	dist[start] = 0;
	queue<int> q;
	bool inqueue[20005] = {false};
	q.push(start);
	inqueue[start] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		inqueue[x] = false;
		for (edge* i = edges[x]->next ; i != NULL ; i = i->next)
		{
			if (dist[i->start] + i->cost < dist[i->end])
			{
				dist[i->end] = dist[i->start] + i->cost;
				if (!inqueue[i->end])
				{
					q.push(i->end);
					inqueue[i->end] = true;
				}
			}
		}
	}

}

void addEdge(int n1, int n2, int c)
{
	edge* t1 = new edge;
	t1->start = n1;
	t1->end = n2;
	t1->cost = c;
	t1->next = NULL;

	edge* t2 = new edge;
	t2->start = n2;
	t2->end = n1;
	t2->cost = c;
	t2->next = NULL;

	if (edges[n1]->next == NULL)
		edges[n1]->next = t1;
	else
	{
		edge* iter = edges[n1]->next;
		while(iter->next != NULL)
			iter = iter->next;
		iter->next = t1;
	}
	if (edges[n2]->next == NULL)
		edges[n2]->next = t2;
	else
	{
		edge* iter = edges[n2]->next;
		while(iter->next != NULL)
			iter = iter->next;
		iter->next = t2;
	}

}

int main()
{
	int case_num;
	cin >> case_num;
	for (int i = 0 ; i < case_num ; ++i)
	{
		init();
		cin >> n >> m >> start >> target;
		for (int j = 0 ; j < m ; ++j)
		{
			int n1, n2, c;
			cin >> n1 >> n2 >> c;
			addEdge(n1, n2, c);
		}
		BellmanFord();
		if (dist[target] < INF)
			cout << "Case #" << i+1 << ": " << dist[target] << endl;
		else
			cout << "Case #" << i+1 << ": unreachable" << endl;
	}
	return 0;
}
