#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define INF 2000000
using namespace std;

int N, n;
int cap[60][60];
bool visited[60];


int DFS(int cur, int c)
{
	visited[cur] = true;
	if(cur == n + 28)
		return c;
	for(int i = 1 ; i <= n + 28 ; ++i)
	{
		if (cap[cur][i] > 0 && !visited[i])
		{
			int buffer = DFS(i, min(c, cap[cur][i]));
			if (buffer > 0)
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
		int temp = DFS(0, INF);
		if (temp == 0)
			break;
		ret += temp;
		memset(visited, false, sizeof(visited));
	}
	return ret;
}

void normalize(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	str.at(0) = toupper(str.at(0));
}

int main()
{
	cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		string name[60][60];
		memset(cap, 0, sizeof(cap));
		cin >> n;
		for(int j = 1 ; j <= n ; ++j)
		{
			int k;
			cin >> k;
			cap[0][j + 27] = 1;
			cap[j][n + 28] = 1;
			for(int l = 0 ; l < k ; ++l)
			{
				string str;
				cin >> str;
				normalize(str);
				int buffer = str.at(0) - 'A' + 1;
				if (buffer < n + 1)
				{
					cap[j + 27][buffer] = 1;
					name[j + 27][buffer] = str;
				}
			}
		
		}
		FordFulkerson();
		cout << "Case #" << i+1 << ":" << endl;
		for(int i = 1 ; i <= n ; ++i)
		{
			for (int j = 1 ; j <= n ; ++j)
			{
				if (cap[j + 27][i] == 0 && cap[i][j + 27] != 0) 
				{
					cout << name[j + 27][i] << endl;
					break;
				}
			}
		}
		
	}	
	return 0;
}
