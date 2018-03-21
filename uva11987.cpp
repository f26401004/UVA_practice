#include <iostream>
#include <vector>
#define MAX 100010
using namespace std;

int unionSet(int* root, vector<int>* set, int x, int y)
{
	if (x == y)
		return 0;
	int target_x = root[x];
	int target_y = root[y];
	if (target_x != target_y)
	{
		for (vector<int>::iterator iter = set[target_y].begin() ; iter != set[target_y].end() ; ++iter)
		{
			set[target_x].push_back(*iter);
			root[*iter] = target_x;
		}
		set[target_y].clear();
		return 1;
	}
	return 0;
}

int main()
{
	int type_num, case_num;
	while(cin >> type_num >> case_num)
	{
		int root[MAX];
		vector<int> set[MAX];
		for (int i = 0 ; i < type_num ; ++i)
		{
			root[i] = i;
			set[i].clear();
			set[i].push_back(i);
		}
		for (int i = 0 ; i < case_num ; ++i)
		{
			int order, n, m;
			cin >> order;
			if (order == 1)
			{
				cin >> n >> m;
				n = n -  1;
				m = m - 1;
				unionSet(root, set, n, m);
			}
			else if (order == 2)
			{
				cin >> n >> m;
				n = n - 1;
				m = m - 1;
				if (root[n] != root[m])
				{
					vector<int>::iterator iter;
					for(iter = set[root[n]].begin() ; iter != set[root[n]].end() ; ++iter)
						if (*iter == n)
							break;
					if (iter != set[root[n]].end())
						set[root[n]].erase(iter);
					root[n] = root[m];
					set[root[m]].push_back(n);
				}
			}
			else if (order == 3)
			{
				cin >> n;
				n = n - 1;
				int num = 0;
				vector<int>::iterator iter;
				for(iter = set[root[n]].begin() ; iter != set[root[n]].end() ; ++iter)
					num += (*iter) + 1;
				cout << set[root[n]].size() << " " << num << endl;
			}
		}
	}
	return 0;
}
