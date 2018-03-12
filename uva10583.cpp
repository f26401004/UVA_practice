#include <iostream>
using namespace std;

int collapsingFind(int* set, int x)
{
	if (set[x] == x)
		return x;
	return set[x] = collapsingFind(set, set[x]);
}

int unionSet(int* set, int x, int y)
{
	if (x == y) return 0;
	int target_x = collapsingFind(set, x);
	int target_y = collapsingFind(set, y);
	if (target_x != target_y)
	{
		set[target_y] = target_x;
		return 1;
	}
	return 0;
}

int main()
{
	int type_num, pair_num, case_num = 1;
	while (cin >> type_num >> pair_num)
	{
		if (type_num == 0 || pair_num == 0)
			break;
		int set[type_num], set_num = type_num;
		for (int i = 0 ; i < type_num ; ++i)
			set[i] = i;
		int parent, child;
		for (int i = 0 ; i < pair_num ; ++i)
		{
			cin >> parent >> child;
			set_num -= unionSet(set, parent - 1, child - 1);
		}
		cout << "Case " << case_num++ << ": " << set_num << endl;
		
	}
	return 0;
}
