#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1000010
using namespace std;

vector<int> order;
queue<int> buffer;
vector<int> adjacent[MAX];
int adjacent_length[MAX];
int visited[MAX];
int n, m;

int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0 ; i < MAX ; ++i)
			adjacent[i].clear();
		memset(visited, false, sizeof(visited));
		memset(adjacent_length, false, sizeof(adjacent_length));
		order.clear();	
		if (m == 0 && n == 0)
			break;
		int t1, t2;
		for(int i = 0 ; i < m ; ++i)
		{
			cin >> t1 >> t2;
			adjacent[t1].push_back(t2);
			++adjacent_length[t2];
		}
		for(int i = 1 ; i < n + 1 ; ++i)
			if (adjacent_length[i] == 0)
				buffer.push(i);
		while(!buffer.empty())
		{
			int i = buffer.front();
			order.push_back(i);
			buffer.pop();
			for(int j = 0 ; j < adjacent[i].size() ; ++j)
			{
				--adjacent_length[adjacent[i].at(j)];
				if (adjacent_length[adjacent[i].at(j)] == 0)
					buffer.push(adjacent[i].at(j));
			}
		}
		if (order.size() == n)
		{
			for (int i = 0 ; i < order.size() ; ++i)
				cout << order.at(i) << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
