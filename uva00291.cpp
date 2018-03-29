#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool visited[5] = {0};
int result[9];

bool adjacentList[5][5];

void reset()
{
	memset(adjacentList, false, sizeof(adjacentList));
	memset(adjacentList, false, sizeof(adjacentList));
	adjacentList[0][4] = adjacentList[4][0] = true;
	adjacentList[0][1] = adjacentList[1][0] = true;
	adjacentList[0][2] = adjacentList[2][0] = true;
	adjacentList[1][2] = adjacentList[2][1] = true;
	adjacentList[1][4] = adjacentList[4][1] = true;
	adjacentList[2][4] = adjacentList[4][2] = true;
	adjacentList[3][4] = adjacentList[4][3] = true;
	adjacentList[2][3] = adjacentList[3][2] = true;
	memset(result, 0, sizeof(result));
}

void backtracking(int a, int size)
{
	result[size] = a;
	if (size == 8)
	{
		for(int i = 0 ; i < 9 ; ++i)
			cout << result[i] + 1;
		cout << endl;
		return;
	}
	for(int i = 0 ; i < 5 ; ++i)
	{
		if (adjacentList[a][i])
		{
			adjacentList[a][i] = adjacentList[i][a] = false;
			backtracking(i, size + 1);
			adjacentList[a][i] = adjacentList[i][a] = true;
		}	
	}
}


int main()
{
	reset();
	backtracking(0, 0);
	return 0;
}
