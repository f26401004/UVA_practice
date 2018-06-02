#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 2000000
using namespace std;


int N;
int S, T, C;
int cap[120][120];
bool visited[120];

int DFS(int cur, int c)
{
	visited[cur] = true;
	if (cur == T)
		return c;
	for(int i = 1 ; i <= N ; ++i)
	{
		if (cap[cur][i] > 0 && !visited[i]) 
		{
			int buffer = DFS(i, min(c, cap[cur][i]));
			if (buffer > 0)
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
		int temp = DFS(S, INF);
		if (temp == 0)
			break;
		ret += temp;
		memset(visited, false, sizeof(visited));
	}
	return ret;
}

int main()
{
	int test_case = 1;
	while(cin >> N) 
	{
		if (N == 0)
			break;
		memset(cap, 0, sizeof(cap));
		cin >> S >> T >> C;
		for(int i = 0 ; i < C ; ++i)
		{
			int n1, n2, c;
			cin >> n1 >> n2 >> c;
			cap[n1][n2] += c; 
			cap[n2][n1] += c;
		}
		cout << "Network " << test_case++ << endl;
		cout << "The bandwidth is " <<  FordFulkerson() << "." << endl << endl;
	}
	return 0;
}
