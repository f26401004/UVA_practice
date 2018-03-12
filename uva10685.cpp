#include <iostream>
#include <map>
#include <string>
using namespace std;

string collapsingFind(map<string, string>* set, string x)
{
	if ((*set)[x].compare(x) == 0)
		return x;
	return (*set)[x] = collapsingFind(set, (*set)[x]);
}

int unionSet(map<string, string>* set, map<string, int>* weight, string x, string y)
{
	if (x.compare(y) == 0)
		return 0;
	string target_x = collapsingFind(set, x);
	string target_y	 = collapsingFind(set, y);
	if (target_x.compare(target_y) != 0)
	{
		if ((*weight)[target_y] < (*weight)[target_x])
		{
			(*set)[target_y] = target_x;
			(*weight)[target_x] += (*weight)[target_y];
		}
		else
		{
			(*set)[target_x] = target_y;
			(*weight)[target_y] += (*weight)[target_x];
		}
		return 1;
	}
	return 0;
}


int main()
{
	int type_num, case_num;
	while(cin >> type_num >> case_num)
	{
		if (type_num == 0)
			break;
		map<string, string> set;
		map<string, int> weight;
		string type;
		for (int i = 0 ; i < type_num ; ++i)
		{
			cin >> type;
			set[type] = type;
			weight[type] = 1;
		}
		for (int i = 0 ; i < case_num ; ++i)
		{
			string parent, child;
			cin >> parent >> child;
			unionSet(&set, &weight, parent, child);
		}
		int max_set_num = 0;
		for (map<string, string>::iterator iter = set.begin() ; iter != set.end() ; ++iter)
		{
			if (max_set_num < weight[iter->first])
				max_set_num = weight[iter->first];
		}
		cout << max_set_num << endl;
	}
	return 0;
}

