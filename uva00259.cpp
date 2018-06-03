#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 2000000
using namespace std;

char type, num, computer[500];
int cap[500][500];
bool visited[500];
int total;
char ans[10];
int ans_num;

int DFS(int cur, int pre, int c)
{
	visited[cur] = true;
	if (cur == 47)
		return c;
	for(int i = 1 ; i <= 47 ; ++i)
	{
		if (cap[cur][i] > 0 && !visited[i])
		{
			int buffer = DFS(i, cur, min(c, cap[cur][i]));
			if (buffer > 0)
			{
				if (cur < 37 && cur > 26 && pre != -1)
					ans[cur - 27] = pre  + 'A' - 1;
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
	ans_num = 0;
	memset(visited, false, sizeof(visited));
	while(1)
	{
		int temp = DFS(0, -1, INF);
		if(temp == 0)
			break;
		ret += temp;
		memset(visited, false, sizeof(visited));
	}
	return ret;
}

int main()
{
	while(cin >> type >> num >> computer)
	{
		cin.get();
		memset(cap, 0, sizeof(cap));
		int t = type - 'A' + 1;
		total = num - '0';
		cap[0][type - 'A' + 1] = num - '0';
		for(int i = 0 ; i < strlen(computer) - 1 ; ++i)
			cap[type - 'A' + 1][computer[i] - '0' + 27] = 1;
		for(int i = 27 ; i < 37 ; ++i)
		{
			cap[i][i + 10] = 1;	
			cap[i + 10][47] = INF;
		}
		while( (type = getchar()) != '\n' && type != EOF)
		{
			cin >> num >> computer;
			cin.get();
			total += num - '0';
			cap[0][type - 'A' + 1] += num - '0';
			for(int i = 0 ; i < strlen(computer) - 1 ; ++i)
				cap[type - 'A' + 1][computer[i] - '0' + 27]++;
		}
		for(int i = 0 ; i < 10 ; ++i)
			ans[i] = '_';
		if (FordFulkerson() != total)
			cout << "!" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
