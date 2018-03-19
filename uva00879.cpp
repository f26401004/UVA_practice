#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int number;

int collapsingFind(int* parent, int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = collapsingFind(parent, parent[x]);
}

int unionSet(int* parent, int x, int y)
{
	if (x == y) 
		return 0;
	int target_x = collapsingFind(parent, x);
	int target_y = collapsingFind(parent, y);
	if (target_x != target_y)
	{
		parent[target_x] = target_y;
		--number;
		return 1;
	}
	return 0;
}

int main()
{
	int case_num;
	cin >> case_num;
	while(getchar() != '\n');
	while(getchar() != '\n');
	while(case_num--)
	{	
		int N = 0;
		cin >> N;
		while(getchar() != '\n');
		int parent[65536];
		number = N;
		for (int i = 0 ; i < N ; ++i)
			parent[i] = i;
		int parent_num, child_num;
		char list[1024];
		while(gets(list))
		{
			if (list[0] == '\0')
				break;
			stringstream sin(list);
           		while (sin >> parent_num >> child_num) 
				unionSet(parent, parent_num - 1, child_num - 1);
		}
		cout << number << endl;	
		if (case_num > 0)
			cout << endl;
	}
	return 0;
}
