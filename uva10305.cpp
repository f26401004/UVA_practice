#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> order;
vector<int> adjacent[110];
int adjacent_length[110];
int visited[110];

void DFS(int i)
{
	visited[i] = true;
	for(int j = 0 ; j < adjacent[i].size() ; ++j)
	{
		if (!visited[adjacent[i].at(j)])
		{
			DFS(adjacent[i].at(j));
		}
	}
	order.push_back(i);
}

int main()
{
	int m, n;
	while(cin >> n >> m)
	{
		for(int i = 0 ; i < 110 ; ++i)
			adjacent[i].clear();
		memset(visited, false, sizeof(visited));
		order.clear();	
		if (m == 0 && n == 0)
			break;
		int t1, t2;
		for(int i = 0 ; i < m ; ++i)
		{
			cin >> t1 >> t2;
			adjacent[t1].push_back(t2);
		}
		for(int i = 1 ; i < n + 1 ; ++i)
		{
			if (!visited[i])
			{
				if (adjacent[i].size() > 0)
					DFS(i);
				else
				{
					order.push_back(i);
					visited[i] = true;
				}
			}
		}
		cout << order.at(order.size() - 1);
		for(int i = order.size() - 2 ; i > -1 ; --i)
			cout << " " << order.at(i);
		cout << endl;
	}
	return 0;
}
