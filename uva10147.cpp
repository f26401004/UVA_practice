#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 2000000
using namespace std;


vector< pair<int, int> > town;
double adjacent[755][755];
int N, M;
bool visited[755];
double dist[755];
int ans;
int previous[755];

void prim()
{
	visited[1] = true;
	dist[1] = 0;
	for(int i = 1 ; i <= N ; ++i)
		if (dist[i] > adjacent[1][i])
		{
			dist[i] = adjacent[1][i];
			previous[i] = 1;
		}
	for(int i = 1 ; i < N ; ++i)
	{
		int min_index;
		double min_value = INF;
		for(int j = 1 ; j <= N ; ++j)
		{
			if (min_value > dist[j] && !visited[j])
			{
				min_value = dist[j];
				min_index = j;
			}
		}
		visited[min_index] = true;
		if (min_value > 0)
		{
			cout << previous[min_index] << " " << min_index << endl;
			ans++;
		}
		for(int j = 1 ; j <= N ; ++j)
			if (dist[j] > adjacent[min_index][j] && !visited[j])
			{
				dist[j] = adjacent[min_index][j];
				previous[j] = min_index;
			}
	}
}

void init()
{
	town.clear();
	for(int i = 0 ; i < 755 ; ++i)
	{
		dist[i] = INF;
		for(int j = 0 ; j < 755 ; ++j)
			adjacent[i][j] = INF;
	}
	memset(visited, false, sizeof(visited));
	memset(previous, -1, sizeof(previous));
	ans = 0;
}

int main()
{
	int test_case;
	cin >> test_case;
	for(int k = 0 ; k < test_case ; ++k)
	{
		if (k != 0)
			cout << endl;
		init();
		cin >> N;
		for(int i = 0 ; i < N ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			town.push_back(make_pair(n1, n2));
		}
		for(int i = 0 ; i < N ; ++i)
			for(int j = 0 ; j < N ; ++j)
				if (i != j)
				{
					int x = abs(town.at(i).first - town.at(j).first);
					int y = abs(town.at(i).second - town.at(j).second);
					double distance = sqrt(x*x + y*y);
					adjacent[i+1][j+1] = distance;
				}
		cin >> M;
		for(int i = 0 ; i < M ; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			adjacent[n1][n2] = adjacent[n2][n1] = 0;
		}
		prim();
		if (ans == 0)
			cout << "No new highways need" << endl;
	}
	return 0;
}
