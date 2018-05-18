#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#define INF 2000000
using namespace std;

map<string, int> namemap;
int adjacent[405][405];
int dist[405];
bool visited[405];
string start;
int s, c;
int cost;

void prim()
{
	for(int i = 0 ; i < 405 ; ++i)
		dist[i] = INF;	
	dist[namemap[start]] = 0;
	for(int i = 0 ; i < s ; ++i)
	{
		int min_index;
		int min_value = INF;
		for(int j =  0 ; j < 405 ; ++j)
		{
			if (min_value > dist[j] && !visited[j])
			{
				min_value = dist[j];
				min_index = j;
			}
		}
		visited[min_index] = true;
		cost = cost + min_value;
		for(int j = 0 ; j < 405 ; ++j)
		{
			if (dist[j] > adjacent[min_index][j] && !visited[j])
				dist[j] = adjacent[min_index][j];
		}
		
	}
}

void init()
{
	for(int i = 0 ; i < 405 ; ++i)
		for(int j = 0 ; j < 405 ; ++j)
			adjacent[i][j] = INF;
	memset(visited, false, sizeof(visited));
	namemap.clear();
	cost = 0;
	start = "";
}


int main()
{
	while(cin >> s >> c) 
	{
		if (s == 0 && c == 0)
			break;
		init();
		for(int i = 0 ; i < s ; ++i)
		{
			string name;
			cin >> name;
			namemap[name] = i;
		}
		for(int i = 0 ; i < c ; ++i)
		{
			int edge_cost;
			string n1, n2;
			cin >> n1 >> n2 >> edge_cost;
			adjacent[namemap[n1]][namemap[n2]] = edge_cost;
			adjacent[namemap[n2]][namemap[n1]] = edge_cost;
		}
		string start;
		cin >> start;
		prim();
		if (cost > INF)
			cout << "Impossible" << endl;
		else
			cout << cost << endl;
	}
	return 0;
}
