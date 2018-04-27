#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#define INF 20000000
using namespace std;

int f, inter;
int cost[505][505];
vector<int> fire;

void init()
{
	for (int i = 0 ; i < 505 ; ++i)
	{
		for (int j = 0 ; j < 505 ; ++j)
			cost[i][j] = INF;
		cost[i][i] = 0;
	}
	fire.clear();
}

void Floyd()
{
	for (int k = 0 ; k < inter ; ++k)
		for (int i = 0 ; i < inter ; ++i)
			for (int j = 0 ; j < inter ; ++j)
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
	for (int i = 0 ; i < inter ; ++i)
		cost[i][i] = 0;
	// origin pshortest path.
	int path[inter];
	for(int i = 0 ; i < inter ; ++i)
		path[i] = INF;
	int max_path = 0;
	for (int i = 0 ; i < inter ; ++i)
	{
		for (int j = 0 ; j < fire.size() ; ++j)
		{
			if (path[i] > cost[i][fire.at(j)])
				path[i] = cost[i][fire.at(j)];
		}
		if (max_path < path[i])
			max_path = path[i];
	}
	int max_index = 0;
	for (int i = inter - 1 ; i > -1 ; --i)
	{
		int max = 0;
		for (int j = 0 ; j < inter ; ++j)
		{
			if (cost[j][i] < path[j])
			{
				if (cost[j][i] > max)
					max = cost[j][i];
			}
			else
			{
				if (path[j] > max)
					max = path[j];
			}
		}
		if (max <= max_path)
		{
			max_index = i;
			max_path = max;
		}
	}
	cout << max_index + 1 << endl;
}


int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 0 ; i < test_case ; ++i)
	{
		if (i)
			cout << endl;
		init();
		cin >> f >> inter;
		for (int j = 0 ; j < f ; ++j)
		{
			int buffer;
			cin >> buffer;
			fire.push_back(buffer - 1);
		}
		cin.get();
		string list;
		while(getline(cin, list) && !list.empty())
		{
			stringstream sin(list);
			int n1, n2, c;
			sin >> n1 >> n2 >> c;
			cost[n1-1][n2-1] = c;
			cost[n2-1][n1-1] = c;
		}
		Floyd();
	}
	return 0;
}
