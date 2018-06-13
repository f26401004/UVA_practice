#include <iostream>
#include <cstring>
#define INF 2000000
using namespace std;

int T, n, m;
int cap[50][50];
int num[50][50];
bool visited[50];

int DFS(int cur, int c)
{
	visited[cur] = true;
	if(cur == n + m + 1)
		return c;
	for(int i = 1 ; i <= n + m + 1 ; ++i)
	{
		if (cap[cur][i] > 0 && !visited[i])
		{
			int buffer = DFS(i, min(c, cap[cur][i]));
			if(buffer > 0)
			{
				cap[cur][i] -= buffer;
				cap[i][cur] += buffer;
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
		int temp = DFS(1, INF);
		if(temp == 0)
			break;
		ret += temp;
		memset(visited, false, sizeof(visited));
	}
	return ret;
}

int main()
{
	cin >> T;
	for(int i = 0 ; i < T ; ++i)
	{
		memset(cap, 0, sizeof(cap));
		memset(num, 0, sizeof(num));
		cin >> n >> m;
		for(int j = 1 ; j <= n ; ++j)
		{
			int number;
			cin >> number;
			for(int k = 0 ; k < number ; ++k)
			{
				int type;
				cin >> type;
				num[j][type]++;
			}
		}
		for(int j = 1 ; j <= m ; ++j)
		{
			if (num[1][j] > 0)
				cap[1][n + j] = num[1][j];
			cap[n + j][n + m + 1] = 1;
		}
		for(int j = 2 ; j <= n ; ++j)
		{
			for(int k = 1 ; k <= m ; ++k)
			{
				if (num[j][k] == 0)
					cap[n + k][j] = 1;
				if (num[j][k] > 1)
					cap[j][n + k] = num[j][k] - 1;
			}
		}
		cout << "Case #" << i + 1 << ": " << FordFulkerson() << endl;
	}
	return 0;
}
