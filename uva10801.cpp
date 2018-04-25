#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
#include <vector>
#include <queue>
#define INF 2000000
using namespace std;

int cost[5];
int time_cost[105][105];
int dist[105];
bool inqueue[105];

void Relax(int j, int k, int c)
{
	if (time_cost[j][k] > c)
		time_cost[j][k] = time_cost[k][j] = c;
}

void SPFA()
{
	for (int i = 0 ; i < 105 ; ++i)
		dist[i] = INF;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	inqueue[0] = true;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		inqueue[now] = false;
		for (int i = 0 ; i < 100 ; ++i)
		{
			if (dist[i] > dist[now] + time_cost[now][i] + 60)
			{
				dist[i] = dist[now] + time_cost[now][i] + 60;
				if (!inqueue[i])
				{
					q.push(i);
					inqueue[i] = true;
				}
			}	
		}
	}
}

void init()
{
	for (int i = 0 ; i < 105 ; ++i)
		for (int j = 0 ; j < 105 ; ++j)
			time_cost[i][j] = INF;
	memset(inqueue, false, sizeof(inqueue));
	memset(cost, 0, sizeof(cost));
}

int main()
{
	int num, target;
	while(cin >> num >> target)
	{
		init();
		for (int i = 0 ; i < num ; ++i)
			cin >> cost[i];
		cin.get();
		for (int i = 0 ; i < num ; ++i)
		{
			char list[1024];
			fgets(list, sizeof(list), stdin);
			stringstream sin(list);
			int buffer;
			vector<int> floor;
			while(sin >> buffer)
				floor.push_back(buffer);
			for (int j = 0 ; j < floor.size() ; ++j)
				for (int k = 0 ; k < floor.size() ; ++k)
					Relax(floor.at(j), floor.at(k), abs(floor.at(j) - floor.at(k)) * cost[i] );
		}
		SPFA();
		if (target == 0)
			cout << 0 << endl;
		else if (dist[target] == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << dist[target] - 60 << endl;
	}
	return 0;
}
