#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 2000000
using namespace std;

int N, M, B, D;
int cap[500][500];
bool visited[500];

int DFS(int cur, int c)
{
	visited[cur] = true;
	if(cur == N + 100 + 1)
		return c;
	for(int i = 0 ; i <= N + 100 + 1 ; ++i)
	{
		if (cap[cur][i] > 0 && !visited[i])
		{
			int buffer = DFS(i, min(c, cap[cur][i]));
			if(buffer > 0)
			{
				cap[cur][i] = cap[cur][i] - buffer;
				cap[i][cur] = cap[i][cur] + buffer;
				return buffer;
			}
		}
	}
	return 0;
}

int FordFulkerson()
{
	int ret = 0;
	memset(visited, false, sizeof(visited));
	while(1)
	{
		int temp = DFS(0, INF);
		if (temp == 0)
			break;
		ret += temp;
		memset(visited, false, sizeof(visited));
	}
	return ret;
}

int main()
{
	while(cin >> N)
	{
		memset(cap, 0, sizeof(cap));
		for(int i = 1 ; i <= N ; ++i)
		{
			int c;
			cin >> c;
			cap[i + 100][i] = c;
		}
		cin >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			int n1, n2, c;
			cin >> n1 >> n2 >> c;
			cap[n1][n2 + 100] = c;
		}
		cin >> B >> D;
		for(int i = 0 ; i < B ; ++i)
		{
			int n;
			cin >> n;
			cap[0][n + 100] = INF;
		}
		for(int i = 0 ; i < D ; ++i)
		{
			int n;
			cin >> n;
			cap[n][N + 100 + 1] = INF;
		}
		cout << FordFulkerson() << endl;
	}
	return 0;
}
