#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <sstream>
#define INF 20000000 
using namespace std;

typedef struct Edge {
	int start;
	int end;
	int cost;
} edge;

vector<edge> edges[105];
int start, finish;

int dist[105];
bool inqueue[105];

bool SPFA()
{
	for (int i = 0 ; i < 105 ; ++i)
		dist[i] = 0;
	dist[start] = 100;
	queue<int> q;
	q.push(start);
	inqueue[start] = true;
	int count = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		inqueue[now] = false;
		for (int i = 0 ; i < edges[now].size() ; ++i)
		{
			if (dist[edges[now].at(i).end] < dist[now] + edges[now].at(i).cost)
			{
				dist[edges[now].at(i).end] = dist[now] + edges[now].at(i).cost;
				if (!inqueue[edges[now].at(i).end])
				{
					q.push(edges[now].at(i).end);
					inqueue[edges[now].at(i).end] = true;
					++count;
				}
			}
			if (dist[finish] > 0)
				return true; 
			if (count > 1000000)
				return false;

		}
	}
	return false;
}

void init()
{
	for (int i = 0 ; i < 105 ; ++i)
		edges[i].clear();
	memset(inqueue, false, sizeof(inqueue));
	start = INF;
	finish = INF;
}

int main()
{
	int n;
	while(cin >> n)
	{
		if (n == -1)
			break;
		init();
		for (int i = 0 ; i < n ; ++i)
		{
			int value, num;
			char list[1024];
			cin >> value >> num;
			if (value == 0) 
			{
				if (start == INF)
					start = i;
				else
					finish = i;
			}
			for (int j = 0 ; j < num ; ++j)
			{
				edge iter;
				iter.start = i;
				cin >> iter.end;
				--iter.end;
				iter.cost = value;
				edges[i].push_back(iter);
			}
		}
		if (SPFA())
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;
	}
	return 0;
}
