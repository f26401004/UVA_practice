#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dir[6][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}}; 
char map[205][205];
bool check[205][205];

bool boundingCheck(int x, int y, int n)
{
	return x > -1 && x < n && y > -1 && y < n;
}

void DFS(int cur_x, int cur_y, int n, int* winner)
{
	check[cur_x][cur_y] = true;
	if (cur_x == n - 1)
		*winner = 1;
	for (int i = 0 ; i < 6 ; ++i)
	{
		int nx = cur_x + dir[i][0];
		int ny = cur_y + dir[i][1];
		if (check[nx][ny])
			continue;
		if (!boundingCheck(nx, ny, n))
			continue;
		if (map[nx][ny] == 'b')
			DFS(nx, ny, n, winner);
	}
}

int main()
{
	int case_num = 1, n, winner;
	while(scanf("%d", &n))
	{
		memset(check, false, sizeof(check));
		winner = 0;
		if (!n)
			break;
		for (int i = 0 ; i < n ; ++i)
			scanf("%s", map[i]);
		for (int i = 0 ; i < n ; ++i)
			if (map[0][i] == 'b')
				DFS(0, i, n, &winner);
		printf("%d %c\n", case_num++, winner == 0 ? 'W' : 'B');
	}	
	return 0;
}
