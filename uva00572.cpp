#include <iostream>
#include <stack>
using namespace std;

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool boundingCheck(int x, int y, int bx, int by)
{
	return x > -1 && y > -1 && x < bx && y < by;
}
char map[105][105];
int check[105][105];

void DFS(int cur_x, int cur_y, int bx, int by)
{
	check[cur_x][cur_y] = 1;
	for (int i = 0 ; i < 8 ; ++i)
	{
		int nx = cur_x + dir[i][0];
		int ny = cur_y + dir[i][1];
		if (!boundingCheck(nx, ny, bx, by))
			continue;
		if (check[nx][ny] == 0 && map[nx][ny] == '@')
			DFS(nx, ny, bx, by);
	}
}


int main() {
	int grid_x, grid_y;
	while(cin >> grid_x >> grid_y)
	{
		if (grid_x == 0)
			break;
		int num = 0;
		for (int i = 0 ; i < grid_x ; ++i)
			for (int j = 0 ; j < grid_y ; ++j) 
			{
				cin >> map[i][j];
				check[i][j] = 0;
			}
		for (int i = 0 ; i < grid_x ; ++i) 
		{
			for (int j = 0 ; j < grid_y ; ++j)
				if (map[i][j] == '@' && check[i][j] == 0) 
				{
					DFS(i, j, grid_x, grid_y);
					++num;
				}
		}
		cout << num << endl;
	}
	return 0;
}
