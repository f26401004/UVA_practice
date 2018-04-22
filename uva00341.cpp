#include <iostream>
#include <vector>
#include <cstring>
#define INF 2000000
using namespace std;

typedef struct Street {
	int start;
	int end;
	int delay;
} street;


int N, street_size;
street streets[100];
int dist[50];
int previous[50];

void Relax(int j, int k, int delay)
{
	if (dist[j] + delay < dist[k])
	{
		dist[k] = dist[j] + delay;
		previous[k] = j;
	}
}

void BellmanFord() 
{
	for (int i = 0 ; i < N - 1 ; ++i)
		for (int j = 0 ; j < street_size ; ++j)
			Relax(streets[j].start, streets[j].end, streets[j].delay);
}

void init()
{
	for (int i = 0 ; i < 20 ; ++i)
		dist[i] = INF;
	street_size = 0;
	memset(previous, -1, sizeof(previous));
}

void print_path(int end)
{
	vector<int> path;
	int prev_index = previous[end];
	while(prev_index != -1)
	{
		path.push_back(prev_index);
		prev_index = previous[prev_index];
	}
	for (int i = path.size() - 1 ; i > -1 ; --i)
		cout << path.at(i) + 1 << " ";
	cout << end + 1 << "; ";
}

int main()
{
	int case_num = 1;
	while(cin >> N)
	{
		if (N == 0)
			break;
		init();
		for (int i = 0 ; i < N ; ++i)
		{
			int pair_num;
			cin >> 	pair_num;
			for (int j = 0 ; j < pair_num ; ++j)
			{
				int end, delay;
				cin >> end >> delay;
				streets[street_size].start = i;
				streets[street_size].end = end - 1;
				streets[street_size].delay = delay;
				++street_size;
			}
		}
		int start, end;
		cin >> start >> end;
		dist[start - 1] = 0;
		BellmanFord();
		cout << "Case " << case_num++ << ": Path = ";
		print_path(end - 1);
		cout << dist[end - 1] << " second delay" << endl;
	}
	return 0;
}
