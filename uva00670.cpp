#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, M;
int nodesX[2][105];
int nodesY[2][105];
int used[105];

int llink[105], rlink[105];

double dist(int type1, int a, int type2, int b)
{
	double dx = nodesX[type1][a] - nodesX[type2][b];
	double dy = nodesY[type1][a] - nodesY[type2][b];
	return sqrt(dx*dx + dy*dy);
}

double reachable(int cur, int target)
{
	double master = 2 * dist(0, cur + 1, 0, cur);
	double place = dist(1, target, 0, cur) + dist(0, cur + 1, 1, target);
	if (place < master)
		return true;
	return false;
}

bool DFS(int cur)
{
	for(int i = 1 ; i <= M ; ++i)
	{
		if (used[i])
			continue;
		if (!reachable(cur, i))
			continue;
		used[i] = true;
		if (rlink[i] == -1 || DFS(rlink[i]))
		{
			llink[cur] = i;
			rlink[i] = cur;
			return true;
		}
	}
	return false;
}

int Bipartite()
{
	int ans = 0;
	memset(rlink, -1, sizeof(rlink));
	memset(llink, -1, sizeof(llink));

	for(int i = 1 ; i < N ; ++i)
	{
		memset(used, false, sizeof(used));
		if (DFS(i))
			ans++;
	}
	return ans;
}

void init()
{
	memset(nodesX, 0, sizeof(nodesX));
	memset(nodesY, 0, sizeof(nodesY));
}

int main()
{
	int L;
	cin >> L;
	for(int i = 0 ; i < L ; ++i)
	{
		init();
		cin >> N >> M;
		for(int j = 1 ; j <= N ; ++j)
			cin >> nodesX[0][j] >> nodesY[0][j];
		for(int j = 1 ; j <= M ; ++j)
			cin >> nodesX[1][j] >> nodesY[1][j];
		cout << N + Bipartite() << endl;
		for(int j = 1 ; j <= N ; ++j )
		{
			cout << nodesX[0][j] << " " << nodesY[0][j];
			if (llink[j] != -1)
				cout << " " << nodesX[1][llink[j]] << " " << nodesY[1][llink[j]];
			if (j != N)
				cout << " ";
		}
		cout << endl;
		if (i != L - 1)
			cout << endl;
	}	
	return 0;
}
