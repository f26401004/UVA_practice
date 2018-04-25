#include <iostream>
#include <algorithm>
#define INF 2000000
using namespace std;

int C, S, Q;
int dist[105][105];
int start, target;

void Floyd()
{
	for (int k = 0 ; k < C ; ++k)
		for (int i = 0 ; i < C ; ++i)
			for (int j = 0 ; j < C ; ++j)
				if (dist[i][j] > max(dist[i][k], dist[k][j]))
					dist[i][j] = max(dist[i][k], dist[k][j]);
}


int main()
{
	int case_num = 1;
	while (cin >> C >> S >> Q)
	{
		if (C == 0 && S == 0 && Q == 0)
			break;
		for (int i = 0 ; i < 105 ; ++i)
		{
			for (int j = 0 ; j < 105 ; ++j)
				dist[i][j] = INF;
			dist[i][i] = 0;
		}
		for (int i = 0 ; i < S ; ++i)
		{
			int n1, n2, c;
			cin >> n1 >> n2 >> c;
			dist[n1-1][n2-1] = c;
			dist[n2-1][n1-1] = c;
		}
		Floyd();
		if (case_num != 1)
			cout << endl;
		cout << "Case #" << case_num++ << endl;
		for (int i = 0 ; i < Q ; ++i)
		{
			cin >> start >> target;
			if (dist[start-1][target-1] < INF)
				cout << dist[start - 1][target - 1] << endl;
			else
				cout << "no path" << endl;
		}
	}	
	return 0;
}
